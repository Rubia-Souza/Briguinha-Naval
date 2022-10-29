#include <string>
#include <iostream>
#include <memory>
#include "raylib.h"

#include "EndGameScreen.hpp"
#include "Screen.hpp"
#include "TitleScreen.hpp"
#include "ScreenManager.hpp"

#include "Text.hpp"
#include "Image.hpp"
#include "ButtonText.hpp"

#include "StyleFunctions.hpp"
#include "ScoreFormatter.hpp"

#include "Colors.hpp"
#include "AssetsPaths.hpp"

#include "Player.hpp"

#include "EndGameScoreDisplay.hpp"

Screens::EndGameScreen::EndGameScreen(const Player& player1, const Player& player2) :
    backgroundImage(new Components::Image(Backgrounds::MAIN)),
    player1Name(new Components::Text()),
    player1Status(new Components::Text()),
    player1ScoreDisplay(new Views::EndGameScoreDisplay(*player1.getScore())),
    player2Name(new Components::Text()),
    player2Status(new Components::Text()),
    player2ScoreDisplay(new Views::EndGameScoreDisplay(*player2.getScore())),
    buttonVoltar(new Components::ButtonText) {
    setPlayer1(player1);
    setPlayer2(player2);

    buildBackgroundImage();
    buildPlayer1SectionTitle();
    buildPlayer1ScoreDisplay();

    buildDivisionLine();

    buildPlayer2SectionTitle();
    buildPlayer2ScoreDisplay();

    buildButtonVoltar();
}

Screens::EndGameScreen::~EndGameScreen() {}

void Screens::EndGameScreen::renderScreen() {
    renderBackground();
    
    renderPlayer1SectionTitle();
    player1ScoreDisplay->render();
    
    renderDivisionLine();

    renderPlayer2SectionTitle();
    player2ScoreDisplay->render();

    buttonVoltar->render();
    return;
}

void Screens::EndGameScreen::handleEvents() {
    if(buttonVoltar->checkClick()) {
        std::shared_ptr<Screen> titleScreen(new TitleScreen());
        ScreenManager::getScreenManager()->loadScreen(titleScreen);
    }
    return;
}

#pragma region .: Styles :.

void Screens::EndGameScreen::renderBackground() {
    backgroundImage->render();
    DrawRectangleRec(backgroundMask, backgroundMaskColor);
    DrawRectangleRec(mainContentBackground, mainContentBackgroundColor);
    return;
}

void Screens::EndGameScreen::renderPlayer1SectionTitle() {
    player1Name->render();
    player1Status->render();
    return;
}

void Screens::EndGameScreen::renderDivisionLine() {
    DrawRectangleRec(divisionLine, DEFAULT_WHITE);
    return;
}

void Screens::EndGameScreen::renderPlayer2SectionTitle() {
    player2Name->render();
    player2Status->render();
    return;
}

void Screens::EndGameScreen::buildBackgroundImage() {
    backgroundImage->setXPosition(0.0);
    backgroundImage->setYPosition(0.0);

    backgroundImage->setWidth(getDisplayWidth());
    backgroundImage->setHeight(getDisplayHeight());

    backgroundMask.x = 0.0;
    backgroundMask.y = 0.0;
    backgroundMask.height = getDisplayHeight();
    backgroundMask.width = getDisplayWidth();

    backgroundMaskColor = DEFAULT_BALCK;
    backgroundMaskColor.a = 160;

    mainContentBackground.height = percentOf(80, getDisplayHeight());
    mainContentBackground.width = getDisplayWidth();
    mainContentBackground.x = 0.0;
    mainContentBackground.y = (getDisplayHeight() - mainContentBackground.height) / 2;

    mainContentBackgroundColor = DEFAULT_BALCK;
    mainContentBackgroundColor.a = 200;
    return;
}

void Screens::EndGameScreen::buildPlayer1SectionTitle() {
    player1Name->setText(getPlayer1().getName());
    player1Name->setFontSize(Components::Text::getDefaultTitleSize());
    
    player1Name->setXPosition(((mainContentBackground.width / 2) - player1Name->getWidth()) / 2);
    player1Name->setYPosition((mainContentBackground.y + getPlayerNameMarginTop()));

    player1Status->setText(getStatusText(*getPlayer1().getScore()));
    player1Status->setFontSize(getPlayerStatusFontSize());
    player1Status->setTextColor(getStatusColor(*getPlayer1().getScore()));

    player1Status->setXPosition(player1Name->getXPosition() + (player1Name->getWidth() - player1Status->getWidth()) / 2);
    player1Status->setYPosition((player1Name->getYPosition() + player1Name->getHeight() + getPlayerStatusMarginTop()));
    return;
}

void Screens::EndGameScreen::buildPlayer1ScoreDisplay() {
    player1ScoreDisplay->setXPosition(((mainContentBackground.width / 2) - player1ScoreDisplay->getWidth()) / 2);
    player1ScoreDisplay->setYPosition(player1Status->getYPosition() + player1Status->getHeight() + getPlayerScoreMarginTop());

    return;
}

void Screens::EndGameScreen::buildDivisionLine() {
    const float Y_POSITION_OFFSET = percentOf(6, mainContentBackground.height);

    divisionLine.height = percentOf(75, mainContentBackground.height);
    divisionLine.width = 3;
    divisionLine.x = (mainContentBackground.width - divisionLine.width) / 2;
    divisionLine.y = mainContentBackground.y + (mainContentBackground.height - divisionLine.height) / 2 - Y_POSITION_OFFSET;

    return;
}

void Screens::EndGameScreen::buildPlayer2SectionTitle() {
    player2Name->setText(getPlayer2().getName());
    player2Name->setFontSize(Components::Text::getDefaultTitleSize());

    player2Name->setXPosition(((3 * mainContentBackground.width / 2) - player1Name->getWidth()) / 2);
    player2Name->setYPosition((mainContentBackground.y + getPlayerNameMarginTop()));

    player2Status->setText(getStatusText(*getPlayer2().getScore()));
    player2Status->setFontSize(getPlayerStatusFontSize());
    player2Status->setTextColor(getStatusColor(*getPlayer2().getScore()));

    player2Status->setXPosition(player2Name->getXPosition() + (player2Name->getWidth() - player2Status->getWidth()) / 2);
    player2Status->setYPosition((player2Name->getYPosition() + player2Name->getHeight() + getPlayerStatusMarginTop()));
    return;
}

void Screens::EndGameScreen::buildPlayer2ScoreDisplay() {
    player2ScoreDisplay->setXPosition(((3 * mainContentBackground.width / 2) - player2ScoreDisplay->getWidth()) / 2);
    player2ScoreDisplay->setYPosition(player2Status->getYPosition() + player2Status->getHeight() + getPlayerScoreMarginTop());

    return;
}

void Screens::EndGameScreen::buildButtonVoltar() {
    const std::string LABEL = "Voltar ao Menu";
    const float MARGIN_BOTTOM = percentOf(14.2, mainContentBackground.height);

    buttonVoltar->setText(LABEL);

    buttonVoltar->setBackgroundColor(DEFAULT_WHITE);
    Color hoverBackgroundColor = LIGHT_GRAY;
    buttonVoltar->setMouseHoverBackgroundColor(hoverBackgroundColor);

    buttonVoltar->setTextColor(DEFAULT_BALCK);
    buttonVoltar->setMouseHoverTextColor(DEFAULT_BALCK);
    buttonVoltar->setFontSize(Components::Text::getDefaultFontSize());

    buttonVoltar->setWidth(percentOf(27, mainContentBackground.width));
    buttonVoltar->setHeight(percentOf(9.3, mainContentBackground.height));

    buttonVoltar->setXPosition((mainContentBackground.width - buttonVoltar->getWidth()) / 2);
    buttonVoltar->setYPosition(mainContentBackground.y + mainContentBackground.height - MARGIN_BOTTOM);
    return;
}

float Screens::EndGameScreen::getPlayerNameMarginTop() const {
    return percentOf(9, getDisplayHeight());
}

float Screens::EndGameScreen::getPlayerStatusFontSize() const {
    return percentOf(5.1, getDisplayHeight());
}

float Screens::EndGameScreen::getPlayerStatusMarginTop() const {
    return percentOf(2, getDisplayHeight());
}

float Screens::EndGameScreen::getPlayerScoreMarginTop() const {
    return percentOf(6.6, getDisplayHeight());
}

std::string Screens::EndGameScreen::getStatusText(const Score playerScore) const {
    const std::string WINNER_TEXT = "Vitoria!";
    const std::string LOOSER_TEXT = "Derrota";

    return (playerScore.isWinner()) ? WINNER_TEXT : LOOSER_TEXT;
}

Color Screens::EndGameScreen::getStatusColor(const Score playerScore) const {
    return (playerScore.isWinner()) ? BRIGHT_GOLD : BRIGHT_RED;
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Screens::EndGameScreen::setPlayer1(const Player& player1Score) {
    this->player1 = player1Score;
    return;
}

Player Screens::EndGameScreen::getPlayer1() const {
    return player1;
}

void Screens::EndGameScreen::setPlayer2(const Player& player2Score) {
    this->player2 = player2Score;
    return;
}

Player Screens::EndGameScreen::getPlayer2() const {
    return player2;
}

#pragma endregion
