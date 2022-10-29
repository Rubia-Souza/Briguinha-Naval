#include <vector>
#include <memory>
#include <string>

#include "TroopPositioningOption.hpp"

#include "Screen.hpp"
#include "ButtonIcon.hpp"
#include "ButtonText.hpp"
#include "Text.hpp"

#include "TroopDisplay.hpp"
#include "SubmarineDisplay.hpp"
#include "CrusierDisplay.hpp"
#include "BattleshipDisplay.hpp"

#include "GameManager.hpp"

#include "StyleFunctions.hpp"
#include "AssetsPaths.hpp"
#include "Colors.hpp"

Views::TroopPositioningOption::TroopPositioningOption() : 
    buttonRotate(new Components::ButtonIcon(Icons::ROTATE_ARROW)),
    buttonEndPositioningTurn(new Components::ButtonText()) {
    availableTroops.push_back(std::shared_ptr<SubmarineDisplay>(new SubmarineDisplay(GameManager::getInstance()->getGameParameters().getAmountSubmarineTroops())));
    availableTroops.push_back(std::shared_ptr<CrusierDisplay>(new CrusierDisplay(GameManager::getInstance()->getGameParameters().getAmountCrusierTroops())));
    availableTroops.push_back(std::shared_ptr<BattleshipDisplay>(new BattleshipDisplay(GameManager::getInstance()->getGameParameters().getAmountBattleshipTroops())));

    buildBackground();
    buildTroopDisplays();
    buildButtonRotate();
    buildButtonEndPositioningTurn();

    setXPosition(0.0);
    setYPosition(0.0);

    findHeight();
    findWidth();
}

Views::TroopPositioningOption::~TroopPositioningOption() {}

void Views::TroopPositioningOption::render() {
    renderBackground();

    if(hasPositionedAllTroops()) {
        buttonEndPositioningTurn->render();
        return;
    }

    for(auto&& troopDisplay : availableTroops) {
        troopDisplay->render();
    }

    buttonRotate->render();

    return;
}

bool Views::TroopPositioningOption::checkButtonRotateClick() {
    return buttonRotate->checkClick();
}

bool Views::TroopPositioningOption::checkButtonEndPositioningTurn() {
    return buttonEndPositioningTurn->checkClick();
}

void Views::TroopPositioningOption::decrementTroopAmount(const std::string troopType) {
    for(auto&& selectableTroopDisplay : availableTroops) {
        if(selectableTroopDisplay->getTroopClassName() == troopType) {
            selectableTroopDisplay->decrementAmount();
        }
    }

    return;
}

void Views::TroopPositioningOption::incrementTroopAmount(const std::string troopType) {
    for(auto&& selectableTroopDisplay : availableTroops) {
        if(selectableTroopDisplay->getTroopClassName() == troopType) {
            selectableTroopDisplay->incrementAmount();
        }
    }

    return;
}

bool Views::TroopPositioningOption::hasPositionedAllTroops() const {
    for(auto&& selectableTroopDisplay : availableTroops) {
        if(selectableTroopDisplay->getAmount() > 0) {
            return false;
        }
    }

    return true;
}

#pragma region .: Styles :.

void Views::TroopPositioningOption::updateInnerComponentsPositions() {
    positionBackground();
    positionTroopsDisplays();
    positionButtonRotate();
    positionButtonEndPositioningTurn();

    return;
}

void Views::TroopPositioningOption::findWidth() {
    this->width = background.width;
    return;
}

void Views::TroopPositioningOption::findHeight() {
    this->height = background.height;
    return;
}

void Views::TroopPositioningOption::buildBackground() {
    background.width = percentOf(100, Screens::Screen::getDisplayWidth()) - 2 * percentOf(0.9, Screens::Screen::getDisplayHeight());
    background.height = percentOf(18, Screens::Screen::getDisplayHeight());

    return;
}

void Views::TroopPositioningOption::positionBackground() {
    background.x = getXPosition();
    background.y = getYPosition();

    return;
}

void Views::TroopPositioningOption::renderBackground() {
    DrawRectangleRec(background, DEFAULT_BALCK);
    return;
}

void Views::TroopPositioningOption::buildTroopDisplays() {
    availableTroops[0]->setTroopImageWidth(percentOf(6, Screens::Screen::getDisplayWidth()));
    availableTroops[1]->setTroopImageWidth(percentOf(9, Screens::Screen::getDisplayWidth()));
    availableTroops[2]->setTroopImageWidth(percentOf(15, Screens::Screen::getDisplayWidth()));

    return;
}

void Views::TroopPositioningOption::buildButtonRotate() {
    const float BUTTON_SIZE = percentOf(4.8, Screens::Screen::getDisplayHeight());
    const float ICON_SIZE = percentOf(4.2, Screens::Screen::getDisplayHeight());

    buttonRotate->setHeight(BUTTON_SIZE);
    buttonRotate->setWidth(BUTTON_SIZE);

    buttonRotate->setIconHeight(ICON_SIZE);
    buttonRotate->setIconWidth(ICON_SIZE);

    buttonRotate->setBackgroundColor(DEFAULT_WHITE);
    buttonRotate->setMouseHoverBackgroundColor(LIGHT_GRAY);

    return;
}

void Views::TroopPositioningOption::positionButtonRotate() {
    const float MARGIN_RIGHT = percentOf(1.5, Screens::Screen::getDisplayWidth());
    const float MARING_TOP = percentOf(1, Screens::Screen::getDisplayHeight());

    buttonRotate->setXPosition(background.x + background.width - buttonRotate->getIconWidth() - MARGIN_RIGHT);
    buttonRotate->setYPosition(background.y + MARING_TOP);

    return;
}

void Views::TroopPositioningOption::buildButtonEndPositioningTurn() {
    const std::string LABEL = "Finalizar posicionamento";

    buttonEndPositioningTurn->setText(LABEL);
    buttonEndPositioningTurn->setFontSize(Components::Text::getDefaultFontSize());
    
    buttonEndPositioningTurn->setTextColor(DEFAULT_BALCK);
    buttonEndPositioningTurn->setMouseHoverTextColor(DEFAULT_BALCK);

    buttonEndPositioningTurn->setBackgroundColor(DEFAULT_WHITE);
    buttonEndPositioningTurn->setMouseHoverBackgroundColor(LIGHT_GRAY);

    buttonEndPositioningTurn->setHeight(percentOf(7.2, Screens::Screen::getDisplayHeight()));
    buttonEndPositioningTurn->setWidth(percentOf(54, Screens::Screen::getDisplayWidth()));

    return;
}

void Views::TroopPositioningOption::positionButtonEndPositioningTurn() {
    buttonEndPositioningTurn->setXPosition(background.x + (background.width - buttonEndPositioningTurn->getWidth()) / 2);
    buttonEndPositioningTurn->setYPosition(background.y + (background.height - buttonEndPositioningTurn->getHeight()) / 2);

    return;
}

void Views::TroopPositioningOption::positionTroopsDisplays() {
    const float MARGIN_LEFT = percentOf(3, Screens::Screen::getDisplayWidth());
    const float TROOP_MARGIN_LEFT = percentOf(1.8, Screens::Screen::getDisplayWidth());

    availableTroops[0]->setXPosition(background.x + MARGIN_LEFT);
    availableTroops[0]->setYPosition(background.y + (background.height - availableTroops[0]->getHeight()) / 2);

    for(unsigned int i = 1; i < availableTroops.size(); i++) {
        availableTroops[i]->setXPosition(availableTroops[i-1]->getXPosition() + availableTroops[i-1]->getWidth() + TROOP_MARGIN_LEFT);
        availableTroops[i]->setYPosition(availableTroops[i-1]->getYPosition());
    }

    return;
}

#pragma endregion

#pragma region .: Gets-Sets :.

std::vector<std::shared_ptr<Views::TroopDisplay>> Views::TroopPositioningOption::getSelectableTroops() const {
    return availableTroops;
}

#pragma endregion
