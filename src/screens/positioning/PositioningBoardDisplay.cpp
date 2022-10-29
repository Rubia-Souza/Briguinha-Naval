#include <vector>

#include "PositioningBoardDisplay.hpp"
#include "PositioningPositionDisplay.hpp"

#include "Board.hpp"
#include "Point.hpp"

#include "InvalidPositionException.hpp"

#include "Colors.hpp"

const std::string INVALID_TROOP_POSITION_ERROR_MESSAGE = "Posicionamento da tropa incorreto";

Views::PositioningBoardDisplay::PositioningBoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells) :
    BoardDisplay(amountHorizontalCells, amountVerticalCells) {
    buildComponent();
}

Views::PositioningBoardDisplay::PositioningBoardDisplay(std::shared_ptr<Board> logicBoard) :
    BoardDisplay(logicBoard) {
    buildComponent();
}

void Views::PositioningBoardDisplay::buildComponent() {
    initializeCells();

    setXPosition(0.0);
    setYPosition(0.0);

    buildBackground();
    
    findHeight();
    findWidth();

    return;
}

Views::PositioningBoardDisplay::~PositioningBoardDisplay() {}

void Views::PositioningBoardDisplay::initializeCells() {
    for(unsigned int i = 0; i < getAmountVerticalCells(); i++) {
        cells.push_back(std::vector<std::shared_ptr<PositionDisplay>>());

        for(unsigned int j = 0; j < getAmountHorizontalCells(); j++) {
            cells[i].push_back(std::shared_ptr<PositionDisplay>(new PositioningPositionDisplay(logicBoard->getPosition(i, j))));
        }
    }

    return;
}

void Views::PositioningBoardDisplay::positionTroop(const std::shared_ptr<Troop> troop) {
    if(!logicBoard->isPositionValid(troop->getOccupiedPositions())) {
        throw InvalidPositionException(INVALID_TROOP_POSITION_ERROR_MESSAGE);
    }

    logicBoard->positionTroop(troop);
    for(Point coodinate : troop->getOccupiedPositions()) {
        cells[coodinate.getX()][coodinate.getY()]->setTroopImage(troop);
    }

    return;
}

void Views::PositioningBoardDisplay::removeTroop(const std::shared_ptr<Troop> troop) {
    logicBoard->removeTroop(troop);
    return;
}

void Views::PositioningBoardDisplay::markPositions(const std::vector<Point>& points) {
    Color markColor = logicBoard->isPositionValid(points) ? BRIGHT_GREEN : BRIGHT_RED;

    for(Point point : points) {
        if(logicBoard->isPointWithinBoundaries(point)) {
            std::shared_ptr<PositioningPositionDisplay> cell = std::dynamic_pointer_cast<PositioningPositionDisplay>(cells[point.getX()][point.getY()]);
            cell->setMarked(true);
            cell->setMarkedColor(markColor);
        }
    }

    return;
}

void Views::PositioningBoardDisplay::unmarkPositions(const std::vector<Point>& points) {
    for(Point point : points) {
        if(logicBoard->isPointWithinBoundaries(point)) {
            unmarkPosition(point);
        }
    }

    return;
}

void Views::PositioningBoardDisplay::unmarkPosition(const Point point) {
    std::shared_ptr<PositioningPositionDisplay> cell = std::dynamic_pointer_cast<PositioningPositionDisplay>(cells[point.getX()][point.getY()]);
    cell->setMarked(false);

    return;
}

#pragma region .: Gets-Sets :.

std::vector<std::vector<std::shared_ptr<Views::PositioningPositionDisplay>>> Views::PositioningBoardDisplay::getCellsAsPositioningCells() const {
    std::vector<std::vector<std::shared_ptr<PositioningPositionDisplay>>> positioningCells;

    for(unsigned int i = 0; i < cells.size(); i++) {
        positioningCells.push_back(std::vector<std::shared_ptr<PositioningPositionDisplay>>());
        for(unsigned int j = 0; j < cells[i].size(); j++) {
            positioningCells[i].push_back(std::dynamic_pointer_cast<PositioningPositionDisplay>(cells[i][j]));
        }
    }

    return positioningCells;
}

#pragma endregion
