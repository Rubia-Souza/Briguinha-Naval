#include <string>
#include <sstream>
#include <memory>
#include "raylib.h"

#include "MatchResultDisplay.hpp"

#include "Screen.hpp"

#include "Colors.hpp"
#include "ScoreFormatter.hpp"
#include "StyleFunctions.hpp"

#include "MatchResults.hpp"

Views::MatchResultDisplay::MatchResultDisplay() :
    title(new Components::Text()),
    matchDateTime(new Components::Text()),
    player1RegistredScore(new PlayerRegistredScore()),
    player2RegistredScore(new PlayerRegistredScore()) {
    setXPosition(0.0);
    setYPosition(0.0);

    findHeight();
    findWidth();
}

Views::MatchResultDisplay::~MatchResultDisplay() {}

void Views::MatchResultDisplay::render() {
    renderTitle();

    player1RegistredScore->render();
    player2RegistredScore->render();

    return;
}

#pragma region .: Styles :.

void Views::MatchResultDisplay::update(const MatchResults matchResult) {
    setMatchResult(matchResult);

    player1RegistredScore->update(getMatchResult().getPlayer1Name(), getMatchResult().getPlayer1Score());
    player2RegistredScore->update(getMatchResult().getPlayer2Name(), getMatchResult().getPlayer2Score());

    buildTitle();
    buildMatchDateTime();
    buildDivisionLines();

    findWidth();
    findHeight();

    return;
}

void Views::MatchResultDisplay::updateInnerComponentsPositions() {
    positionTitle();
    positionScores();

    return;
}

void Views::MatchResultDisplay::findWidth() {
    width = title->getWidth();
    return;
}

void Views::MatchResultDisplay::findHeight() {
    height = abs(title->getYPosition() - player2RegistredScore->getYPosition()) + player2RegistredScore->getHeight();
    return;
}

void Views::MatchResultDisplay::renderTitle() {
    title->render();
    matchDateTime->render();

    DrawRectangleRec(leftDivisionLine, DEFAULT_WHITE);
    DrawRectangleRec(rightDivisionLine, DEFAULT_WHITE);

    return;
}

void Views::MatchResultDisplay::buildTitle() {
    const std::string LABEL = "Partida:";

    title->setText(LABEL);
    title->setFontSize(getTitleFontSize());

    return;
}

void Views::MatchResultDisplay::buildMatchDateTime() {
    std::stringstream matchDateTimeLabel;
    matchDateTimeLabel.clear();
    matchDateTimeLabel << getMatchResult().getId();

    matchDateTime->setText(matchDateTimeLabel.str());
    matchDateTime->setFontSize(getTitleFontSize());

    return;
}

void Views::MatchResultDisplay::buildDivisionLines() {
    const float DIVISION_LINE_HEIGHT = 5.1;
    const float DIVISION_LINE_WIDTH = percentOf(2.7, Screens::Screen::getDisplayWidth());

    leftDivisionLine.height = DIVISION_LINE_HEIGHT;
    leftDivisionLine.width = DIVISION_LINE_WIDTH;

    rightDivisionLine.height = DIVISION_LINE_HEIGHT;
    rightDivisionLine.width = DIVISION_LINE_WIDTH;

    return;
}

void Views::MatchResultDisplay::positionTitle() {
    const float MATCH_DATE_TIME_MARGIN_TOP = percentOf(1.5, Screens::Screen::getDisplayHeight());
    const float DIVISION_LINE_MARGIN = percentOf(1.5, Screens::Screen::getDisplayWidth());

    title->setXPosition(getXPosition());
    title->setYPosition(getYPosition());

    matchDateTime->setXPosition(title->getXPosition() + (title->getWidth() - matchDateTime->getWidth()) / 2);
    matchDateTime->setYPosition(title->getYPosition() + title->getHeight() + MATCH_DATE_TIME_MARGIN_TOP);

    leftDivisionLine.x = matchDateTime->getXPosition() - leftDivisionLine.width - DIVISION_LINE_MARGIN;
    leftDivisionLine.y = title->getYPosition() + (title->getHeight() + matchDateTime->getHeight() + MATCH_DATE_TIME_MARGIN_TOP - leftDivisionLine.height) / 2;

    rightDivisionLine.x = matchDateTime->getXPosition() + matchDateTime->getWidth() + DIVISION_LINE_MARGIN;
    rightDivisionLine.y = title->getYPosition() + (title->getHeight() + matchDateTime->getHeight() + MATCH_DATE_TIME_MARGIN_TOP - rightDivisionLine.height) / 2;

    return;
}

void Views::MatchResultDisplay::positionScores() {
    const float PLAYER_REGISTRED_SCORE_MARGIN_TOP = percentOf(4.8, Screens::Screen::getDisplayHeight());

    player1RegistredScore->setXPosition(matchDateTime->getXPosition() + (matchDateTime->getWidth() - player1RegistredScore->getWidth()) / 2);
    player1RegistredScore->setYPosition(matchDateTime->getYPosition() + matchDateTime->getHeight() + PLAYER_REGISTRED_SCORE_MARGIN_TOP);

    player2RegistredScore->setXPosition(matchDateTime->getXPosition() + (matchDateTime->getWidth() - player2RegistredScore->getWidth()) / 2);
    player2RegistredScore->setYPosition(player1RegistredScore->getYPosition() + player1RegistredScore->getHeight() + PLAYER_REGISTRED_SCORE_MARGIN_TOP);

    return;
}

float Views::MatchResultDisplay::getTitleFontSize() const {
    return percentOf(3.6, Screens::Screen::getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::MatchResultDisplay::setMatchResult(const MatchResults matchResult) {
    this->matchResult = matchResult;
    return;
}

MatchResults Views::MatchResultDisplay::getMatchResult() const {
    return matchResult;
}

#pragma endregion
