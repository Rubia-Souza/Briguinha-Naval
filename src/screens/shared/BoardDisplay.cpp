#include <vector>

#include "BoardDisplay.hpp"

#include "Image.hpp"
#include "Screen.hpp"

#include "Point.hpp"
#include "Board.hpp"

#include "AssetsPaths.hpp"
#include "StyleFunctions.hpp"

Views::BoardDisplay::BoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells) :
    background(new Components::Image(Backgrounds::BOARD)),
    logicBoard(new Board(amountHorizontalCells, amountVerticalCells)) {
    setAmountHorizontalCells(amountHorizontalCells);
    setAmountVerticalCells(amountVerticalCells);

    setXPosition(0.0);
    setYPosition(0.0);
}

Views::BoardDisplay::BoardDisplay(std::shared_ptr<Board> logicBoard) :
    background(new Components::Image(Backgrounds::BOARD)),
    logicBoard(logicBoard) {
    setAmountHorizontalCells(logicBoard->getWidth());
    setAmountVerticalCells(logicBoard->getHeight());

    setXPosition(0.0);
    setYPosition(0.0);
}

Views::BoardDisplay::~BoardDisplay() {}

void Views::BoardDisplay::render() {
    background->render();

    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            cells[i][j]->render();
        }
    }

    return;
}

#pragma region .: Styles :.

void Views::BoardDisplay::updateInnerComponentsPositions() {
    positionBackground();
    positionCells();

    return;
}

void Views::BoardDisplay::findWidth() {
    this->width = background->getWidth();
    return;
}

void Views::BoardDisplay::findHeight() {
    this->height = background->getHeight();
    return;
}

void Views::BoardDisplay::buildBackground() {
    background->setHeight(getCellsMatrixHeight() + getBoardPadding());
    background->setWidth(getCellsMatrixWidth() + getBoardPadding());

    return;
}

void Views::BoardDisplay::positionBackground() {
    background->setXPosition(getXPosition());
    background->setYPosition(getYPosition());

    return;
}

void Views::BoardDisplay::positionCells() {
    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            if(i == 0 && j == 0) {
                cells[i][j]->setXPosition(background->getXPosition() + (background->getWidth() - getCellsMatrixWidth()) / 2);
                cells[i][j]->setYPosition(background->getYPosition() + (background->getHeight() - getCellsMatrixHeight()) / 2);
                continue;
            }

            if(j == 0) {
                cells[i][j]->setXPosition(cells[i-1][j]->getXPosition());
                cells[i][j]->setYPosition(cells[i-1][j]->getYPosition() + cells[i][j]->getHeight() + getCellsSpacing());
            }
            else {
                cells[i][j]->setXPosition(cells[i][j-1]->getXPosition() + cells[i][j]->getWidth() + getCellsSpacing());
                cells[i][j]->setYPosition(cells[i][j-1]->getYPosition());
            }
        }
    }

    return;
}

float Views::BoardDisplay::getBoardPadding() const {
    return percentOf(3.6, Screens::Screen::getDisplayHeight());
}

float Views::BoardDisplay::getCellsSpacing() const {
    return percentOf(0.1 * getAmountHorizontalCells(), Screens::Screen::getDisplayHeight());
}

float Views::BoardDisplay::getCellsMatrixHeight() const {
    return abs(cells[0][0]->getYPosition() - cells[cells.size()-1][0]->getYPosition()) + cells[cells.size()-1][0]->getHeight();
}

float Views::BoardDisplay::getCellsMatrixWidth() const {
    return abs(cells[0][0]->getXPosition() - cells[0][cells.size()-1]->getXPosition()) + cells[0][cells.size()-1]->getWidth();
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::BoardDisplay::setAmountHorizontalCells(const unsigned int amountHorizontalCells) {
    this->amountHorizontalCells = amountHorizontalCells;
    return;
}

unsigned int Views::BoardDisplay::getAmountHorizontalCells() const {
    return amountHorizontalCells;
}

void Views::BoardDisplay::setAmountVerticalCells(const unsigned int amountVerticalCells) {
    this->amountVerticalCells = amountVerticalCells;
    return;
}

unsigned int Views::BoardDisplay::getAmountVerticalCells() const {
    return amountVerticalCells;
}

std::vector<std::vector<std::shared_ptr<Views::PositionDisplay>>> Views::BoardDisplay::getCells() const {
    return cells;
}

#pragma endregion
