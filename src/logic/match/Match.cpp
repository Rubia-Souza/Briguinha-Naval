#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "Match.hpp"

#include "GameManager.hpp"
#include "Player.hpp"

Match::Match() : 
    player1(new Player("Jogador1")), 
    player2(new Player("Jogador2")) {
    id = createMatchId();
}

Match::~Match() {}

void Match::passTurn() {
    currentTurn++;

    if(hasGameFinished()) {
        GameManager::getInstance()->endGame();
    }

    return;
}

bool Match::isPlayer1Turn() const {
    return (currentTurn % 2 == 0);
}

bool Match::isPlayer2Turn() const {
    return (currentTurn % 2 != 0);
}

bool Match::hasGameFinished() const {
    return (!getPlayer1()->getScore()->isWinner() || !getPlayer2()->getScore()->isWinner());
}

void Match::incrementPlayer1Score(const bool wasTroopDestroyed) {
    getPlayer1()->getScore()->incrementHitShoots();

    if(wasTroopDestroyed) {
        getPlayer1()->getScore()->incrementDestroyedTroops();

        getPlayer2()->getScore()->decrementRemainingTroops();
        getPlayer2()->getScore()->incrementLostTroops();
    }

    return;
}

void Match::incrementPlayer1AmountShots() {
    getPlayer1()->getScore()->incrementTotalAmountShoots();
    return;
}    

void Match::incrementPlayer2Score(const bool wasTroopDestroyed) {
    getPlayer2()->getScore()->incrementHitShoots();

    if(wasTroopDestroyed) {
        getPlayer2()->getScore()->incrementDestroyedTroops();

        getPlayer1()->getScore()->decrementRemainingTroops();
        getPlayer1()->getScore()->incrementLostTroops();
    }

    return;
}

void Match::incrementPlayer2AmountShots() {
    getPlayer2()->getScore()->incrementTotalAmountShoots();
    return;
}

std::string Match::createMatchId() const {
    std::stringstream generatedId;
    generatedId.clear();

    std::time_t actualTime = std::time(0);
    std::tm* dateTime = std::localtime(&actualTime);

    generatedId << (dateTime->tm_year + 1900) << '/' 
           << std::setw(2) << std::setfill('0') << (dateTime->tm_mon + 1) << '/'
           << std::setw(2) << std::setfill('0') <<  dateTime->tm_mday << "-" 
           << std::setw(2) << std::setfill('0') << dateTime->tm_hour << ":" 
           << std::setw(2) << std::setfill('0') << dateTime->tm_min << ":" 
           << std::setw(2) << std::setfill('0') << dateTime->tm_sec;

    return generatedId.str();
}

#pragma region .: Gets-Sets :.

std::shared_ptr<Player> Match::getPlayer1() const {
    return player1;
}

std::shared_ptr<Player> Match::getPlayer2() const {
    return player2;
}

MatchResults Match::getResults() const {
    return MatchResults(getPlayer1()->getName(), *(getPlayer1()->getScore()), getPlayer2()->getName(), *(getPlayer2()->getScore()), id);
}

#pragma endregion
