#include <string>
#include <memory>
#include <stdexcept>

#include "Player.hpp"

#include "Board.hpp"
#include "Score.hpp"

Player::Player(const std::string name) : score(new Score()), board(new Board()) {
        setName(name);
}

Player::Player() : Player("Player") {}

Player::~Player() {}

#pragma region .: Gets-Sets :.

void Player::setName(const std::string name) {
    if(name == "") throw std::invalid_argument("Name cannot be empty");
    this->name = name;
    return;
}

std::string Player::getName() const { 
    return name;
}

std::shared_ptr<Score> Player::getScore() const {
    return score;
}

std::shared_ptr<Board> Player::getBoard() const {
    return board;
}

#pragma endregion
