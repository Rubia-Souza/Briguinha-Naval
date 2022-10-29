#include <memory>
#include <typeinfo>

#include "SubmarineDisplay.hpp"

#include "Troop.hpp"
#include "Submarine.hpp"

#include "AssetsPaths.hpp"

Views::SubmarineDisplay::SubmarineDisplay(const unsigned int amount) :
    TroopDisplay(amount, Submarine::getTroopName(), SUBMARINE_HORIZONTAL_FULL_SPRITE) {
    setXPosition(0.0);
    setYPosition(0.0);
}

Views::SubmarineDisplay::~SubmarineDisplay() {}

#pragma region .: Gets-Sets :.

std::shared_ptr<Troop> Views::SubmarineDisplay::getTroopInstance() const {
    return std::shared_ptr<Troop>(new Submarine());
}

std::string Views::SubmarineDisplay::getTroopClassName() const {
    return typeid(Submarine).name();
}

#pragma endregion
