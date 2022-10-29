#include <string>

#include "Crusier.hpp"

#include "Troop.hpp"
#include "Point.hpp"

#include "AssetsPaths.hpp"

const unsigned int Crusier::INITIAL_HEALTH = 3;

std::string Crusier::getTroopName() {
    return "Crusador";
}

Crusier::Crusier() : Troop(INITIAL_HEALTH) {}
Crusier::~Crusier() {}

void Crusier::positionHorizontally(const Point initialPosition) {
    Troop::positionHorizontally(initialPosition);
    buildImagesMap(CRUSIER_HORIZONTAL_SPRITE_PATH_WITH_PREFIX);

    return;
}

void Crusier::positionVertically(const Point initialPosition) {
    Troop::positionVertically(initialPosition);
    buildImagesMap(CRUSIER_VERTICAL_SPRITE_PATH_WITH_PREFIX);

    return;
}

unsigned int Crusier::getInitialHealth() const {
    return INITIAL_HEALTH;   
}
