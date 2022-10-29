#include <memory>
#include <typeinfo>
#include <string>

#include "CrusierDisplay.hpp"

#include "Troop.hpp"
#include "Crusier.hpp"

#include "AssetsPaths.hpp"

Views::CrusierDisplay::CrusierDisplay(const unsigned int amount) :
    TroopDisplay(amount, Crusier::getTroopName(), CRUSIER_HORIZONTAL_FULL_SPRITE) {
    setXPosition(0.0);
    setYPosition(0.0);
}

Views::CrusierDisplay::~CrusierDisplay() {}

#pragma region .: Gets-Sets :.

std::shared_ptr<Troop> Views::CrusierDisplay::getTroopInstance() const {
    return std::shared_ptr<Troop>(new Crusier());
}

std::string Views::CrusierDisplay::getTroopClassName() const {
    return typeid(Crusier).name();
}

#pragma endregion
