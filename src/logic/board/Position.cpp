#include <stdexcept>

#include "Position.hpp"

#include "Troop.hpp"

Position::Position(const int x, const int y) : Point(x, y) {}

Position::~Position() {}

bool Position::hasTroop() const {
    return (troop != nullptr);
}

#pragma region .: Gets-Sets :.

void Position::setTroop(std::shared_ptr<Troop> troop) {
    this->troop = troop;
    return;
}

std::shared_ptr<Troop> Position::getTroop() const {
    return troop;
}

#pragma endregion
