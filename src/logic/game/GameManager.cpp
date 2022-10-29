#include <memory>

#include "GameManager.hpp"

#include "PositioningScreen.hpp"
#include "Screen.hpp"
#include "ScreenManager.hpp"
#include "GameScreen.hpp"
#include "EndGameScreen.hpp"

#include "Match.hpp"
#include "Board.hpp"
#include "GameParameters.hpp"
#include "TxtWriter.hpp"
#include "MatchResults.hpp"

#include "Constants.hpp"

std::shared_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager() {
    initializeMatch();
}

GameManager::~GameManager() {}

void GameManager::startGame() {
    if(!player1HasPositionedTroops) {
        startPlayerPositioningTurn(match->getPlayer1());
        player1HasPositionedTroops = true;
        return;
    }

    if(!player2HasPositionedTroops) {
        startPlayerPositioningTurn(match->getPlayer2());
        player2HasPositionedTroops = true;
        return;
    }

    std::shared_ptr<Screens::Screen> gameScreen(new Screens::GameScreen(match));
    Screens::ScreenManager::getScreenManager()->loadScreen(gameScreen);

    return;
}

void GameManager::initializeMatch() {
    match = std::shared_ptr<Match>(new Match());
    intializePlayersScore();

    return;
}

void GameManager::intializePlayersScore() {
    match->getPlayer1()->getScore()->setRemainingTroops(gameParameters.getTotalAmountOfTroops());
    match->getPlayer2()->getScore()->setRemainingTroops(gameParameters.getTotalAmountOfTroops());

    return;
}

void GameManager::startPlayerPositioningTurn(std::shared_ptr<Player> playerPositioningTurn) {
    std::shared_ptr<Screens::Screen> positioningScreen(new Screens::PositioningScreen(playerPositioningTurn));
    Screens::ScreenManager::getScreenManager()->loadScreen(positioningScreen);

    return;
}

void GameManager::endGame() {
    registerScores();

    std::shared_ptr<Screens::Screen> endGameScreen(new Screens::EndGameScreen(*match->getPlayer1(), *match->getPlayer2()));
    Screens::ScreenManager::getScreenManager()->loadScreen(endGameScreen);

    resetGameManager();
    initializeMatch();

    return;
}

void GameManager::registerScores() {
    std::unique_ptr<TxtWriter> writer(new TxtWriter(SCORE_SAVE_FILE_NAME));

    MatchResults results = match->getResults(); 
    writer->writeResults(results);
    
    return;
}

void GameManager::resetGameManager() {
    player1HasPositionedTroops = false;
    player2HasPositionedTroops = false;

    match.reset();

    return;
}

#pragma region .: Gets-Sets :.

GameParameters GameManager::getGameParameters() const {
    return gameParameters;
}

std::shared_ptr<GameManager> GameManager::getInstance() {
    if(instance == nullptr) {
        instance = std::shared_ptr<GameManager>(new GameManager());
    }

    return instance;
}

#pragma endregion
