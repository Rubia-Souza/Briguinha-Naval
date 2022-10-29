#include <memory>
#include <algorithm>
#include <stdexcept>

#include "Board.hpp"

#include "Position.hpp"
#include "Constants.hpp"

Board::Board() : Board(DEFAULT_BOARD_AMOUNT_HORIZONTAL_CELLS, DEFAULT_BOARD_AMOUNT_VERTICAL_CELLS) {}

Board::Board(const int width, const int height) {
    setHeight(height);
    setWidth(width);

    initializeBoardPositions();
}

Board::~Board() {}

void Board::initializeBoardPositions() {
    for(int i = 0; i < getHeight(); i++){
        board.push_back(std::vector<std::shared_ptr<Position>>());

        for(int j = 0; j < getWidth(); j++) {
            board[i].push_back(std::shared_ptr<Position>(new Position(i, j)));
        } 
    }

    return;
}

void Board::positionTroop(const std::shared_ptr<Troop> troop){
    if(troop->getOccupiedPositions().size() == 0) throw std::invalid_argument("Troop has not been positioned yet");
    if(!isPositionValid(troop->getOccupiedPositions())) throw std::invalid_argument("Position occupied by troop is invalid");
    for(Point coordinates : troop->getOccupiedPositions()){
        board[coordinates.getX()][coordinates.getY()]->setTroop(troop);
    }

    troops.push_back(troop);
    return;
}

void Board::removeTroop(const std::shared_ptr<Troop> troop) {
    for(Point coordinates : troop->getOccupiedPositions()) {
        board[coordinates.getX()][coordinates.getY()]->setTroop(nullptr);
    }

    std::vector<std::shared_ptr<Troop>>::iterator iterator = std::find(troops.begin(), troops.end(), troop);
    if(iterator != troops.end()) {
        troops.erase(iterator);
    }
    
    return;
}

bool Board::isPositionValid(const std::vector<Point>& positionCoordinates) const {
    for(Point coordinate : positionCoordinates) {
        if(!isPointWithinBoundaries(coordinate) || doesPositionContainsTroop(coordinate)) {
            return false;
        }
    }

    return true;
}

bool Board::doesPositionContainsTroop(const Point coordinate) const {
    if(!isPointWithinBoundaries(coordinate)) throw std::invalid_argument("Point is out of boundaries");
    return board[coordinate.getX()][coordinate.getY()]->hasTroop();
}

bool Board::isPointWithinBoundaries(const Point point) const {
    bool verifyX = point.getX() >= 0 && point.getX() < getWidth();
    bool verifyY = point.getY() >= 0 && point.getY() < getHeight();

    return (verifyX && verifyY);
}

#pragma region .: Gets-Sets :.

void Board::setHeight(const int height) {
    if(height < 0) throw std::invalid_argument("Cannot set negative height to board");
    this->height = height;
    return;
}

int Board::getHeight() const {
    return height;
}

void Board::setWidth(const int width) {
    if(width < 0) throw std::invalid_argument("Cannot set negative width to board");
    this->width = width;
    return;
}

int Board::getWidth() const {
    return width;
}

std::vector<std::shared_ptr<Troop>> Board::getTroops() const {
    return troops;
}

std::shared_ptr<Position> Board::getPosition(const int x, const int y) const {
    if(!isPointWithinBoundaries(Point(x,y))) throw std::invalid_argument("Points out of boundaries");
    return board[x][y];
}

#pragma endregion
