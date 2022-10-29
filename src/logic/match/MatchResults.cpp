#include <string>
#include <stdexcept>

#include "MatchResults.hpp"

#include "Score.hpp"

MatchResults::MatchResults() {}

MatchResults::MatchResults(const std::string player1Name, const Score player1Score, const std::string player2Name, const Score player2Score, const std::string id) {
    setPlayer1Name(player1Name);
    setPlayer1Score(player1Score);

    setPlayer2Name(player2Name);
    setPlayer2Score(player2Score);

    setId(id);
}

MatchResults::~MatchResults() {}

#pragma region .: Gets-Sets :.

void MatchResults::setPlayer1Name(const std::string name) {
    this->player1Name = name;
    return;
}

std::string MatchResults::getPlayer1Name() const {
    return player1Name;
}

void MatchResults::setPlayer1Score(const Score score) {
    this->player1Score = score;
    return;
}

Score MatchResults::getPlayer1Score() const {
    return player1Score;
}

void MatchResults::setPlayer2Name(const std::string name) {
    this->player2Name = name;
    return;
}

std::string MatchResults::getPlayer2Name() const {
    return player2Name;
}

void MatchResults::setPlayer2Score(const Score score) {
    this->player2Score = score;
    return;
}

Score MatchResults::getPlayer2Score() const {
    return player2Score;
}

void MatchResults::setId(const std::string id) {
    if(id == "") throw std::invalid_argument("Id cannot be blank");
    else if(id.find(' ') != std::string::npos) throw std::invalid_argument("Id cannot have spaces");
    this->id = id;
    return;
}

std::string MatchResults::getId() const {
    return id;
}

#pragma endregion
