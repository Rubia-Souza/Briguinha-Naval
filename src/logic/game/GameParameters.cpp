#include "GameParameters.hpp"
#include <stdexcept>

const int GameParameters::DEFAULT_AMOUNT_TROOPS = 3;
const int GameParameters::DEFAULT_BOARD_AMOUNT_HORIZONTAL_CELLS = 9;
const int GameParameters::DEFAULT_BOARD_AMOUNT_VERTICAL_CELLS = 9;

GameParameters::GameParameters() {}
GameParameters::~GameParameters() {}

#pragma region .: Gets-Sets :.

void GameParameters::setAmountSubmarineTroops(const int amountSubmarineTroops) {
    if(amountSubmarineTroops < 0) throw std::invalid_argument("Value cannot be negative");
    this->amountSubmarineTroops = amountSubmarineTroops;
    return;
}

int GameParameters::getAmountSubmarineTroops() const {
    return amountSubmarineTroops;
}

void GameParameters::setAmountCrusierTroops(const int amountCrusierTroops) {
    if(amountCrusierTroops < 0) throw std::invalid_argument("Value cannot be negative");
    this->amountCrusierTroops = amountCrusierTroops;
    return;
}

int GameParameters::getAmountCrusierTroops() const {
    return amountCrusierTroops;
}

void GameParameters::setAmountBattleshipTroops(const int amountBattleshipTroops) {
    if(amountBattleshipTroops < 0) throw std::invalid_argument("Value cannot be negative");
    this->amountBattleshipTroops = amountBattleshipTroops;
    return;
}

int GameParameters::getAmountBattleshipTroops() const {
    return amountBattleshipTroops;
}

void GameParameters::setBoardAmountHorizontalCells(const int boardAmountHorizontalCells) {
    if(boardAmountHorizontalCells < 0) throw std::invalid_argument("Value cannot be negative"); 
    this->boardAmountHorizontalCells = boardAmountHorizontalCells;
    return;
}

int GameParameters::getBoardAmountHorizontalCells() const {
    return boardAmountHorizontalCells;
}

void GameParameters::setBoardAmountVerticalCells(const int boardAmountVerticalCells) {
    if(boardAmountVerticalCells < 0) throw std::invalid_argument("Value cannot be negative"); 
    this->boardAmountVerticalCells = boardAmountVerticalCells;
    return;
}

int GameParameters::getBoardAmountVerticalCells() const {
    return boardAmountVerticalCells;
}

int GameParameters::getTotalAmountOfTroops() const {
    return getAmountBattleshipTroops() + getAmountCrusierTroops() + getAmountSubmarineTroops();
}

#pragma endregion
