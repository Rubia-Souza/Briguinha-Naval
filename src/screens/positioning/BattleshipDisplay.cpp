#include <memory>
#include <typeinfo>
#include <string>

#include "BattleshipDisplay.hpp"

#include "Troop.hpp"
#include "Battleship.hpp"

#include "AssetsPaths.hpp"

Views::BattleshipDisplay::BattleshipDisplay(const unsigned int amount) :
    TroopDisplay(amount, Battleship::getTroopName(), BATTLESHIP_HORIZONTAL_FULL_SPRITE) {
    setXPosition(0.0);
    setYPosition(0.0);
}

Views::BattleshipDisplay::~BattleshipDisplay() {}

#pragma region .: Gets-Sets :.

std::shared_ptr<Troop> Views::BattleshipDisplay::getTroopInstance() const {
    return std::shared_ptr<Troop>(new Battleship());
}

std::string Views::BattleshipDisplay::getTroopClassName() const {
    return typeid(Battleship).name();
}

#pragma endregion
