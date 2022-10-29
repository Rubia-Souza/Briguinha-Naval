#include "Score.hpp"

#include <stdexcept>

Score::Score() {}

Score::Score(int dTroops, int rTroops, int lTroops, int tAShoots, int hShoots) {
    setDestroyedTroops(dTroops);
    setRemainingTroops(rTroops);
    setLostTroops(lTroops);
    setTotalAmountShoots(tAShoots);
    setHitShoots(hShoots);
}

Score::~Score() {}

bool Score::isWinner() const {
    return (getRemainingTroops() > 0);
}

#pragma region .: Gets-Sets :.

void Score::setDestroyedTroops(const int value) {
    if(value < 0) throw std::invalid_argument("Values cannot be negative");
    destroyedTroops = value;
    return;
}

void Score::incrementDestroyedTroops() {
    setDestroyedTroops(getDestroyedTroops() + 1);
    return;
}

int Score::getDestroyedTroops() const {
    return destroyedTroops;
}

void Score::setRemainingTroops(const int value) {
    if(value < 0) throw std::invalid_argument("Values cannot be negative");
    remainingTroops = value;
    return;
}

void Score::decrementRemainingTroops(){
    setRemainingTroops(getRemainingTroops() - 1);
    return;
}

int Score::getRemainingTroops() const {
    return remainingTroops;
}

void Score::setLostTroops(const int value) {
    if(value < 0) throw std::invalid_argument("Values cannot be negative");
    lostTroops = value;
    return;
}

void Score::incrementLostTroops(){
    setLostTroops(getLostTroops() + 1);
    return;
}

int Score::getLostTroops() const {
    return lostTroops;
}

void Score::setTotalAmountShoots(const int value) {
    if(value < 0) throw std::invalid_argument("Values cannot be negative");
    if(value < hitShoots) throw std::invalid_argument("Total amount of shoots cannot be smaller then number of shoots hit");
    totalAmountShoots = value;
    return;
}

void Score::incrementTotalAmountShoots(){
    setTotalAmountShoots(getTotalAmountShoots() + 1);
    return;
}

int Score::getTotalAmountShoots() const {
    return totalAmountShoots;
}

void Score::setHitShoots(const int value) {
    if(value < 0) throw std::invalid_argument("Values cannot be negative");
    if(value > totalAmountShoots) throw std::invalid_argument("Total hit shoots cannot be bigger than total amount of shoots");
    hitShoots = value;
    return;
}

void Score::incrementHitShoots(){
    setHitShoots(getHitShoots() + 1);
    return;
}

int Score::getHitShoots() const {
    return hitShoots;
}

int Score::getInitialAmountShips() const {
    return (getLostTroops() + getRemainingTroops());
}

float Score::getPrecision() const {
    if(getTotalAmountShoots() == 0) throw std::invalid_argument("Total amount of shoots is zero, cannot divide by zero.");
    return (getHitShoots() / (float) getTotalAmountShoots());
}

#pragma endregion
