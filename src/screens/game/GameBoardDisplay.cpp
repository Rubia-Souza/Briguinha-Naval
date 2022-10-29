#include <memory>
#include <vector>

#include "GameBoardDisplay.hpp"

#include "BoardDisplay.hpp"
#include "PositionDisplay.hpp"
#include "GamePositionDisplay.hpp"

#include "Point.hpp"
#include "Troop.hpp"
#include "Board.hpp"

Views::GameBoardDisplay::GameBoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells) :
    BoardDisplay(amountHorizontalCells, amountVerticalCells) {
    buildComponent();
}


Views::GameBoardDisplay::GameBoardDisplay(std::shared_ptr<Board> logicBoard) :
    BoardDisplay(logicBoard) {
    buildComponent();
}

Views::GameBoardDisplay::~GameBoardDisplay() {}

void Views::GameBoardDisplay::buildComponent() {
    initializeCells();

    setXPosition(0.0);
    setYPosition(0.0);

    buildBackground();
    
    findHeight();
    findWidth();

    return;
}

void Views::GameBoardDisplay::initializeCells() {
    for(unsigned int i = 0; i < getAmountVerticalCells(); i++) {
        cells.push_back(std::vector<std::shared_ptr<PositionDisplay>>());

        for(unsigned int j = 0; j < getAmountHorizontalCells(); j++) {
            cells[i].push_back(std::shared_ptr<PositionDisplay>(new GamePositionDisplay(logicBoard->getPosition(i, j))));
        }
    }

    return;
}

void Views::GameBoardDisplay::enable() {
    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            cells[i][j]->setEnabled(true);
        }
    }
    return;
}

void Views::GameBoardDisplay::disable() {
    for(unsigned int i = 0; i < cells.size(); i++) {
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            cells[i][j]->setEnabled(false);
        }
    }
    return;
}

void Views::GameBoardDisplay::revealTroops() {
    std::vector<std::vector<std::shared_ptr<GamePositionDisplay>>> positions = getCellsAsGameCells();

    for(unsigned int i = 0; i < positions.size(); i++) {
        for(unsigned int j = 0; j < positions[i].size(); j++) {
            positions[i][j]->setRevealTroop(true);
        }
    }

    return;
}

void Views::GameBoardDisplay::hideTroops() {
    std::vector<std::shared_ptr<Troop>> troops = logicBoard->getTroops();

    for(auto&& troop : troops) {
        for(Point position : troop->getOccupiedPositions()) {
            std::shared_ptr<GamePositionDisplay> troopPosition = std::dynamic_pointer_cast<GamePositionDisplay>(cells[position.getX()][position.getY()]);
            troopPosition->setRevealTroop(false);
        }
    }

    return;
}

#pragma region .: Gets-Sets :.

std::vector<std::vector<std::shared_ptr<Views::GamePositionDisplay>>> Views::GameBoardDisplay::getCellsAsGameCells() const {
    std::vector<std::vector<std::shared_ptr<GamePositionDisplay>>> positioningCells;

    for(unsigned int i = 0; i < cells.size(); i++) {
        positioningCells.push_back(std::vector<std::shared_ptr<GamePositionDisplay>>());
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            positioningCells[i].push_back(std::dynamic_pointer_cast<GamePositionDisplay>(cells[i][j]));
        }
    }

    return positioningCells;
}

#pragma endregion
