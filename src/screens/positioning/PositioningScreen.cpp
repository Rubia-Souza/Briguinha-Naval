#include <vector>
#include <memory>
#include <typeinfo>
#include "raylib.h"

#include "PositioningScreen.hpp"

#include "Text.hpp"

#include "PositionDisplay.hpp"
#include "WarningPopUp.hpp"
#include "PositioningPositionDisplay.hpp"
#include "PositioningBoardDisplay.hpp"
#include "TroopPositioningOption.hpp"
#include "TroopDisplay.hpp"

#include "Troop.hpp"
#include "Point.hpp"
#include "Player.hpp"
#include "Orientation.hpp"
#include "InvalidPositionException.hpp"
#include "GameManager.hpp"

#include "Colors.hpp"
#include "Constants.hpp"
#include "StyleFunctions.hpp"

const std::string Screens::PositioningScreen::POPUP_MESSAGE = "Nao e possivel colocar a tropa nessa posicao!\nPor favor escolha outra em que os quadrados estejam verdes.";

Screens::PositioningScreen::PositioningScreen(std::shared_ptr<Player> playerPositioningTurn) :
    playerName(new Components::Text(playerPositioningTurn->getName())),
    board(new Views::PositioningBoardDisplay(playerPositioningTurn->getBoard())),
    availableTroops(new Views::TroopPositioningOption()),
    popup(new Views::WarningPopUp(POPUP_MESSAGE)) {
    buildBackground();
    buildPlayerName();
    buildBoard();
    buildAvailableTroops();
}

Screens::PositioningScreen::~PositioningScreen() {}

void Screens::PositioningScreen::renderScreen() {
    renderBackground();

    playerName->render();
    board->render();

    availableTroops->render();

    if(shouldDisplayPopUp) {
        popup->render();
    }

    return;
}

void Screens::PositioningScreen::handleEvents() {
    verifyPopupShouldClose();

    if(!shouldDisplayPopUp) {
        verifyButtonRotateClick();
        verifyTroopSelection();
        verifyTroopPositioning();
        verifyTroopRemoved();
        verifyEndPositioningTurnCilck();
    }

    clearBoard();
    return;
}

void Screens::PositioningScreen::verifyPopupShouldClose() {
    if(popup->checkExit()) {
        shouldDisplayPopUp = false;
    }

    return;
}

void Screens::PositioningScreen::verifyEndPositioningTurnCilck() {
    if(availableTroops->hasPositionedAllTroops() && availableTroops->checkButtonEndPositioningTurn()) {
        GameManager::getInstance()->startGame();
    }

    return;
}

void Screens::PositioningScreen::verifyButtonRotateClick() {
    if(availableTroops->checkButtonRotateClick()) {
        troopBuildDirection = (troopBuildDirection == HORIZONTAL) ? VERTICAL : HORIZONTAL;
    }

    return;
}

void Screens::PositioningScreen::verifyTroopSelection() {
    std::vector<std::shared_ptr<Views::TroopDisplay>> selectableTroops = availableTroops->getSelectableTroops();

    for(auto&& troopOption : selectableTroops) {
        if(troopOption->checkClick()) {
            troopToBePositioned = troopOption->getTroopInstance();
        }
    }

    return;
}

void Screens::PositioningScreen::verifyTroopPositioning() {
    if(troopToBePositioned == nullptr) {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Views::PositioningPositionDisplay>>> cells = board->getCellsAsPositioningCells();

    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j]->checkMouseExit()) {
                board->unmarkPositions(troopToBePositioned->getOccupiedPositions());
            }

            if(cells[i][j]->checkMouseEnter()) {
                troopToBePositioned->setPosition(cells[i][j]->getCoordinates(), troopBuildDirection);
                board->markPositions(troopToBePositioned->getOccupiedPositions());
            }

            if(cells[i][j]->checkClick()) {
                try {
                    board->unmarkPositions(troopToBePositioned->getOccupiedPositions());
                    board->positionTroop(troopToBePositioned);
                    availableTroops->decrementTroopAmount(typeid(*troopToBePositioned).name());
                    troopToBePositioned.reset();
                }
                catch(InvalidPositionException& exception) {
                    handleInvalidPositionException();   
                }
            }
        }
    }

    return;
}

void Screens::PositioningScreen::verifyTroopRemoved() {
    std::vector<std::vector<std::shared_ptr<Views::PositioningPositionDisplay>>> cells = board->getCellsAsPositioningCells();

    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j]->checkMouseRightClick() && cells[i][j]->containsTroop()) {
                availableTroops->incrementTroopAmount(typeid(*cells[i][j]->getTroop()).name());
                board->removeTroop(cells[i][j]->getTroop());
            }
        }
    }

    return;
}

void Screens::PositioningScreen::clearBoard() {
    if(troopToBePositioned == nullptr) {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Views::PositioningPositionDisplay>>> cells = board->getCellsAsPositioningCells();

    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j]->isMarked() && !cells[i][j]->containsTroop() && !troopToBePositioned->containsPoint(cells[i][j]->getCoordinates())) {
                board->unmarkPosition(cells[i][j]->getCoordinates());
            }
        }
    }
    
    return;
}


void Screens::PositioningScreen::handleInvalidPositionException() {
    board->unmarkPositions(troopToBePositioned->getOccupiedPositions());
    troopToBePositioned.reset();
    shouldDisplayPopUp = true;

    return;
}

#pragma region .: Styles :.

void Screens::PositioningScreen::renderBackground() {
    DrawRectangleRec(background, BACKGROUND_BLUE);
    DrawRectangleRec(foreground, DEFAULT_WHITE);

    return;
}

void Screens::PositioningScreen::buildBackground() {
    const float FOREGROUND_MARIGN = percentOf(0.9, getDisplayHeight());

    background.x = 0.0;
    background.y = 0.0;
    background.height = getDisplayHeight();
    background.width = getDisplayWidth();

    foreground.x = background.x + FOREGROUND_MARIGN;
    foreground.y = background.y + FOREGROUND_MARIGN;
    foreground.height = background.height - 2 * FOREGROUND_MARIGN;
    foreground.width = background.width - 2 * FOREGROUND_MARIGN;

    return;
}

void Screens::PositioningScreen::buildPlayerName() {
    const float MARGIN_TOP = percentOf(9, getDisplayHeight());

    playerName->setFontSize(Components::Text::getDefaultTitleSize());
    playerName->setTextColor(DEFAULT_BALCK);

    playerName->setXPosition(foreground.x + (foreground.width - playerName->getWidth()) / 2);
    playerName->setYPosition(foreground.y + MARGIN_TOP);

    return;
}

void Screens::PositioningScreen::buildBoard() {
    const float MARGIN_TOP = percentOf(5.1, getDisplayHeight());

    board->setXPosition(playerName->getXPosition() + (playerName->getWidth() - board->getWidth()) / 2);
    board->setYPosition(playerName->getYPosition() + playerName->getHeight() + MARGIN_TOP);

    return;
}

void Screens::PositioningScreen::buildAvailableTroops() {
    const float MARGIN_BOTTOM = percentOf(3, getDisplayHeight());

    availableTroops->setXPosition(foreground.x);
    availableTroops->setYPosition(getDisplayHeight() - availableTroops->getHeight() - MARGIN_BOTTOM);

    return;
}

#pragma endregion
