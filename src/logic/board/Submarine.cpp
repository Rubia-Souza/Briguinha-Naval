#include <string>
#include <map>

#include "Submarine.hpp"

#include "Troop.hpp"
#include "Point.hpp"

#include "AssetsPaths.hpp"

const unsigned int Submarine::INITIAL_HEALTH = 1;

std::string Submarine::getTroopName() {
    return "Submarino";
}

Submarine::Submarine() : Troop(INITIAL_HEALTH) {}

Submarine::~Submarine() {}

void Submarine::positionHorizontally(const Point initialPosition) {
    Troop::positionHorizontally(initialPosition);
    buildImagesMap(SUBMARINE_HORIZONTAL_FULL_SPRITE);

    return;
}

void Submarine::positionVertically(const Point initialPosition) {
    Troop::positionVertically(initialPosition);
    buildImagesMap(SUBMARINE_VERTICAL_FULL_SPRITE);

    return;
}

void Submarine::buildImagesMap(const std::string troopName) {
    images.clear();

    images.insert(std::pair<Point, std::string>(shape[0], troopName));
    
    return;
}

unsigned int Submarine::getInitialHealth() const {
    return INITIAL_HEALTH;
}
