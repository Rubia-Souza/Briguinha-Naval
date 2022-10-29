#include <string>
#include <memory>
#include <sstream>

#include "GameScreen.hpp"

#include "Text.hpp"
#include "ButtonTextIcon.hpp"

#include "GameBoardDisplay.hpp"
#include "GameScoreDisplay.hpp"

#include "PositionDisplay.hpp"

#include "Constants.hpp"
#include "AssetsPaths.hpp"
#include "Colors.hpp"

#include "StyleFunctions.hpp"
#include "ScoreFormatter.hpp"

const std::string BUTTON_TEXT_ICON_LABEL = "Revelar Tropas";

Screens::GameScreen::GameScreen(std::shared_ptr<Match> match) :
    player1Name(new Components::Text(match->getPlayer1()->getName())),
    player1Board(new Views::GameBoardDisplay(match->getPlayer1()->getBoard())),
    player1RevealTroopsButton(new Components::ButtonTextIcon(Icons::EYE, BUTTON_TEXT_ICON_LABEL)),
    player1ScoreDisplay(new Views::GameScoreDisplay(match->getPlayer1()->getScore())),
    
    player2Name(new Components::Text(match->getPlayer2()->getName())),
    player2Board(new Views::GameBoardDisplay(match->getPlayer2()->getBoard())),
    player2RevealTroopsButton(new Components::ButtonTextIcon(Icons::EYE, BUTTON_TEXT_ICON_LABEL)),
    player2ScoreDisplay(new Views::GameScoreDisplay(match->getPlayer2()->getScore())) {
    setActualMatch(match);

    buildBackground();

    buildPlayer1Name();
    buildPlayer1Board();
    buildPlayer1RevealTroopsButton();
    buildPlayer1ScoreDisplay();
        
    buildDivisionLine();
        
    buildPlayer2Name();
    buildPlayer2Board();
    buildPlayer2RevealTroopsButton();
    buildPlayer2ScoreDisplay();

    startPlayer1Turn();
}

Screens::GameScreen::~GameScreen() {}

void Screens::GameScreen::renderScreen() {
    renderBackground();

    player1Name->render();
    player1RevealTroopsButton->render();
    player1Board->render();
    player1ScoreDisplay->render();
    
    renderDivisionLine();
    
    player2Name->render();
    player2RevealTroopsButton->render();
    player2Board->render();
    player2ScoreDisplay->render();
}

void Screens::GameScreen::handleEvents() {
    if(match->isPlayer1Turn()) {
        verifyPlayerBoardClick(player2Board);
        verifyPlayerRevealTroopsClick(player1RevealTroopsButton, player1Board);
    }
    else {
        verifyPlayerBoardClick(player1Board);
        verifyPlayerRevealTroopsClick(player2RevealTroopsButton, player2Board);
    }

    return;
}

void Screens::GameScreen::verifyPlayerBoardClick(const std::unique_ptr<Views::GameBoardDisplay>& board) {
    std::vector<std::vector<std::shared_ptr<Views::PositionDisplay>>> cells = board->getCells();

    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j]->checkClick()) {
                cells[i][j]->setEnabled(false);
                checkTroopHit(*cells[i][j]);
                passTurn();
            }
        }
    }

    return;
}

void Screens::GameScreen::verifyPlayerRevealTroopsClick(const std::unique_ptr<Components::ButtonTextIcon>& playerRevealTroopsButton, const std::unique_ptr<Views::GameBoardDisplay>& board) {
    if(playerRevealTroopsButton->checkClick()) {
        if(isTroopsRevealed) {
            board->hideTroops();
        }
        else {
            board->revealTroops();
        }

        isTroopsRevealed = !isTroopsRevealed;
    }

    return;
}

void Screens::GameScreen::checkTroopHit(Views::PositionDisplay& target) {
    incrementPlayerShots();

    if(!target.containsTroop()) {
        return;
    }

    target.getTroop()->takeDamage();

    if(match->isPlayer1Turn()) {
        match->incrementPlayer1Score(target.getTroop()->isDead());
    }
    else {
        match->incrementPlayer2Score(target.getTroop()->isDead());
    }
    
    player1ScoreDisplay->updateLabels();
    player2ScoreDisplay->updateLabels();

    return;
}

void Screens::GameScreen::incrementPlayerShots() {
    if(match->isPlayer1Turn()) {
        match->incrementPlayer1AmountShots();
        player1ScoreDisplay->updateLabels();
    }
    else {
        match->incrementPlayer2AmountShots();
        player2ScoreDisplay->updateLabels();
    }

    return;
}

void Screens::GameScreen::passTurn() {
    isTroopsRevealed = false;
    match->passTurn();

    if(match->isPlayer1Turn()) {
        startPlayer1Turn();
    }
    else {
        startPlayer2Turn();
    }

    return;
}

void Screens::GameScreen::startPlayer1Turn() {
    player2Name->setText(match->getPlayer2()->getName());
    player1Name->setText(buildPlayerTurnMark(match->getPlayer1()->getName()));
    player1Board->disable();
    player1RevealTroopsButton->setEnabled(true);

    player2Board->enable();
    player2Board->hideTroops();
    player2RevealTroopsButton->setEnabled(false);

    return;
}

void Screens::GameScreen::startPlayer2Turn() {
    player1Name->setText(match->getPlayer1()->getName());
    player2Name->setText(buildPlayerTurnMark(match->getPlayer2()->getName()));
    player2Board->disable();
    player2RevealTroopsButton->setEnabled(true);

    player1Board->enable();
    player1Board->hideTroops();
    player1RevealTroopsButton->setEnabled(false);

    return;
}

#pragma region .: Styles :.

void Screens::GameScreen::renderBackground() {
    DrawRectangleRec(background, BACKGROUND_BLUE);
    DrawRectangleRec(foreground, DEFAULT_WHITE);

    return;
}

void Screens::GameScreen::buildBackground() {
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

void Screens::GameScreen::buildPlayer1Name() {
    player1Name->setFontSize(Components::Text::getDefaultTitleSize());
    player1Name->setTextColor(DEFAULT_BALCK);

    player1Name->setXPosition(foreground.x + ((foreground.width / 2) - player1Name->getWidth()) / 2);
    player1Name->setYPosition((foreground.y + getPlayerNameMarginTop()));

    return;
}

void Screens::GameScreen::buildPlayer1Board() {
    player1Board->setXPosition(player1Name->getXPosition() + (player1Name->getWidth() - player1Board->getWidth()) / 2);
    player1Board->setYPosition(player1Name->getYPosition() + player1Name->getHeight() + getBoardMarginTop());

    return;
}

void Screens::GameScreen::buildPlayer1RevealTroopsButton() {
    player1RevealTroopsButton->setIconHeight(getRevealButtonIconHeight());
    player1RevealTroopsButton->setIconWidth(getRevealButtonIconWidth());

    player1RevealTroopsButton->setFontSize(getRevealButtonFontSize());

    player1RevealTroopsButton->setHeight(getRevealButtonHeight());
    player1RevealTroopsButton->setWidth(getRevealButtonWidth());

    player1RevealTroopsButton->setBackgroundColor(LIGHT_PURPLE);
    player1RevealTroopsButton->setMouseHoverBackgroundColor(DARK_PURPLE);

    player1RevealTroopsButton->setXPosition(player1Board->getXPosition() + (player1Board->getWidth() - player1RevealTroopsButton->getWidth()) / 2);
    player1RevealTroopsButton->setYPosition(player1Board->getYPosition() + player1Board->getHeight() - getRevealButtonYOffset());

    return;
}

void Screens::GameScreen::buildPlayer1ScoreDisplay() {
    player1ScoreDisplay->setXPosition(player1RevealTroopsButton->getXPosition() + (player1RevealTroopsButton->getWidth() - player1ScoreDisplay->getWidth()) / 2);
    player1ScoreDisplay->setYPosition(player1RevealTroopsButton->getYPosition() + player1RevealTroopsButton->getHeight() + getPlayerScoreDisplayMarginTop());

    return;
}

void Screens::GameScreen::renderDivisionLine() {
    DrawRectangleRec(divisionLine, DEFAULT_BALCK);
    return;
}

void Screens::GameScreen::buildDivisionLine() {
    divisionLine.width = percentOf(0.3, foreground.width);
    divisionLine.height = percentOf(95, foreground.height);
    divisionLine.x = foreground.x + (foreground.width - divisionLine.width) / 2;
    divisionLine.y = foreground.y + (foreground.height - divisionLine.height) / 2;
        
    return;
}

void Screens::GameScreen::buildPlayer2Name() {
    player2Name->setFontSize(Components::Text::getDefaultTitleSize());
    player2Name->setTextColor(DEFAULT_BALCK);

    player2Name->setXPosition(foreground.x + ((3 * foreground.width / 2) - player1Name->getWidth()) / 2);
    player2Name->setYPosition((foreground.y + getPlayerNameMarginTop()));

    return;
}

void Screens::GameScreen::buildPlayer2Board() {
    player2Board->setXPosition(player2Name->getXPosition() + (player2Name->getWidth() - player2Board->getWidth()) / 2);
    player2Board->setYPosition(player2Name->getYPosition() + player2Name->getHeight() + getBoardMarginTop());

    return;
}

void Screens::GameScreen::buildPlayer2RevealTroopsButton() {
    player2RevealTroopsButton->setIconHeight(getRevealButtonIconHeight());
    player2RevealTroopsButton->setIconWidth(getRevealButtonIconWidth());

    player2RevealTroopsButton->setFontSize(getRevealButtonFontSize());

    player2RevealTroopsButton->setHeight(getRevealButtonHeight());
    player2RevealTroopsButton->setWidth(getRevealButtonWidth());

    player2RevealTroopsButton->setBackgroundColor(LIGHT_PURPLE);
    player2RevealTroopsButton->setMouseHoverBackgroundColor(DARK_PURPLE);

    player2RevealTroopsButton->setXPosition(player2Board->getXPosition() + (player2Board->getWidth() - player2RevealTroopsButton->getWidth()) / 2);
    player2RevealTroopsButton->setYPosition(player2Board->getYPosition() + player2Board->getHeight() - getRevealButtonYOffset());
    
    return;
}

void Screens::GameScreen::buildPlayer2ScoreDisplay(){
    player2ScoreDisplay->setXPosition(player2RevealTroopsButton->getXPosition() + (player2RevealTroopsButton->getWidth() - player2ScoreDisplay->getWidth()) / 2);
    player2ScoreDisplay->setYPosition(player2RevealTroopsButton->getYPosition() + player2RevealTroopsButton->getHeight() + getPlayerScoreDisplayMarginTop());

    return;
}

std::string Screens::GameScreen::buildPlayerTurnMark(const std::string playerName) const {
    const std::string MARK = "*";

    std::stringstream markedName;
    markedName.clear();
    markedName << playerName << MARK;

    return markedName.str();
}

float Screens::GameScreen::getPlayerNameMarginTop() const {
    return percentOf(7.2, getDisplayHeight());
}

float Screens::GameScreen::getBoardMarginTop() const {
    return percentOf(5.1, getDisplayHeight());
}

float Screens::GameScreen::getRevealButtonIconHeight() const {
    return percentOf(2.1, getDisplayHeight());
}

float Screens::GameScreen::getRevealButtonIconWidth() const {
    return percentOf(3, getDisplayHeight());
}

float Screens::GameScreen::getRevealButtonFontSize() const {
    return percentOf(2.1, getDisplayHeight());
}

float Screens::GameScreen::getRevealButtonWidth() const {
    return percentOf(85, player1Board->getWidth());
}

float Screens::GameScreen::getRevealButtonHeight() const {
    return percentOf(4.2, getDisplayHeight());
}

float Screens::GameScreen::getRevealButtonYOffset() const {
    return percentOf(0.6, getDisplayHeight());
}

float Screens::GameScreen::getPlayerScoreDisplayMarginTop() const {
    return percentOf(2.1, getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Screens::GameScreen::setActualMatch(const std::shared_ptr<Match> match) {
    this->match = match;
    return;
}

Match Screens::GameScreen::getActualMatch() const {
    return *match;
}

#pragma endregion
