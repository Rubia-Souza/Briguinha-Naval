#include <string>

#include "Battleship.hpp"

#include "Troop.hpp"
#include "Point.hpp"

#include "AssetsPaths.hpp"

const unsigned int Battleship::INITIAL_HEALTH = 4;

std::string Battleship::getTroopName() {
    return "Encouracado";
}

Battleship::Battleship() : Troop(INITIAL_HEALTH) {}
Battleship::~Battleship() {}

void Battleship::positionHorizontally(const Point initialPosition) {
    Troop::positionHorizontally(initialPosition);
    buildImagesMap(BATTLESHIP_HORIZONTAL_SPRITE_PATH_WITH_PREFIX);

    return;
}

void Battleship::positionVertically(const Point initialPosition) {
    Troop::positionVertically(initialPosition);
    buildImagesMap(BATTLESHIP_VERTICAL_SPRITE_PATH_WITH_PREFIX);

    return;
}

unsigned int Battleship::getInitialHealth() const {
    return INITIAL_HEALTH;
}
