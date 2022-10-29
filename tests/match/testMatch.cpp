#include "doctest.hpp"
#include <stdexcept>

#include <regex>

#include "Match.hpp"

bool compareScores(Score a, Score b){
    if (a.getDestroyedTroops() != b.getDestroyedTroops()) return false;
    if (a.getHitShoots() != b.getHitShoots()) return false;
    if (a.getLostTroops() != b.getLostTroops()) return false;
    if (a.getRemainingTroops() != b.getRemainingTroops()) return false;
    if (a.getTotalAmountShoots() != b.getTotalAmountShoots()) return false;
    return true;
}

TEST_CASE("Initialize a match and check default values"){
    Match a;
    CHECK(a.getPlayer1()->getName() == "Jogador1");
    CHECK(a.getPlayer2()->getName() == "Jogador2");
}

TEST_CASE("Check turns, and passing turns without "){
    Match a;
    CHECK(a.isPlayer1Turn());
    CHECK_FALSE(a.isPlayer2Turn());

    a.getPlayer1()->getScore()->setRemainingTroops(1);
    a.getPlayer2()->getScore()->setRemainingTroops(1);

    a.passTurn();

    CHECK_FALSE(a.isPlayer1Turn());
    CHECK(a.isPlayer2Turn());
}

TEST_CASE("Check for a finished game by player 1 and 2, and both") {
    Match a;
    a.getPlayer1()->getScore()->setRemainingTroops(1);
    a.getPlayer2()->getScore()->setRemainingTroops(1);

    CHECK_FALSE(a.hasGameFinished());

    a.getPlayer1()->getScore()->decrementRemainingTroops();

    CHECK(a.hasGameFinished());
    
    a.getPlayer1()->getScore()->setRemainingTroops(1);
    a.getPlayer2()->getScore()->decrementRemainingTroops();

    CHECK(a.hasGameFinished());

    a.getPlayer1()->getScore()->decrementRemainingTroops();

    CHECK(a.hasGameFinished());
}

TEST_CASE("Increment both players score without a troop being destroyed") {
    Match a;
    //Preventing exceptions by setting artificial initial state
    a.incrementPlayer1AmountShots();
    a.incrementPlayer2AmountShots();
    
    CHECK(a.getPlayer1()->getScore()->getHitShoots() == 0);
    CHECK(a.getPlayer2()->getScore()->getHitShoots() == 0);

    a.incrementPlayer1Score(false);
    
    CHECK(a.getPlayer1()->getScore()->getHitShoots() == 1);
    CHECK(a.getPlayer2()->getScore()->getHitShoots() == 0);

    a.incrementPlayer2Score(false);

    CHECK(a.getPlayer1()->getScore()->getHitShoots() == 1);
    CHECK(a.getPlayer2()->getScore()->getHitShoots() == 1);

}

TEST_CASE("Increment both players score with a troop being destroyed") {
    Match a;
    //Preventing exceptions by setting artificial initial state
    a.incrementPlayer1AmountShots();
    a.incrementPlayer2AmountShots();
    a.getPlayer1()->getScore()->setRemainingTroops(10);
    a.getPlayer2()->getScore()->setRemainingTroops(10);

    CHECK(a.getPlayer1()->getScore()->getDestroyedTroops() == 0);
    CHECK(a.getPlayer1()->getScore()->getRemainingTroops() == 10);
    CHECK(a.getPlayer1()->getScore()->getLostTroops() == 0);

    CHECK(a.getPlayer2()->getScore()->getDestroyedTroops() == 0);
    CHECK(a.getPlayer2()->getScore()->getRemainingTroops() == 10);
    CHECK(a.getPlayer2()->getScore()->getLostTroops() == 0);

    a.incrementPlayer1Score(true);
    a.incrementPlayer2Score(true);

    CHECK(a.getPlayer1()->getScore()->getDestroyedTroops() == 1);
    CHECK(a.getPlayer1()->getScore()->getRemainingTroops() == 9);
    CHECK(a.getPlayer1()->getScore()->getLostTroops() == 1);

    CHECK(a.getPlayer2()->getScore()->getDestroyedTroops() == 1);
    CHECK(a.getPlayer2()->getScore()->getRemainingTroops() == 9);
    CHECK(a.getPlayer2()->getScore()->getLostTroops() == 1);
}

TEST_CASE("Increment player 1 and 2 amount of shots") {
    Match a;

    CHECK(a.getPlayer1()->getScore()->getTotalAmountShoots() == 0);
    CHECK(a.getPlayer2()->getScore()->getTotalAmountShoots() == 0);

    a.incrementPlayer1AmountShots();
    a.incrementPlayer2AmountShots();

    CHECK(a.getPlayer1()->getScore()->getTotalAmountShoots() == 1);
    CHECK(a.getPlayer2()->getScore()->getTotalAmountShoots() == 1);
}

TEST_CASE("Trying to get MatchResults out of match") {
    Match a;
    std::shared_ptr<Score> score1 = a.getPlayer1()->getScore(), score2 = a.getPlayer2()->getScore();
    score1->setDestroyedTroops(1);
    score1->setRemainingTroops(2);
    score1->setLostTroops(3);
    score1->setTotalAmountShoots(5);
    score1->setHitShoots(4);

    score2->setDestroyedTroops(6);
    score2->setRemainingTroops(7);
    score2->setLostTroops(8);
    score2->setTotalAmountShoots(10);
    score2->setHitShoots(9);

    MatchResults b = a.getResults();

    CHECK(a.getPlayer1()->getName() == b.getPlayer1Name());
    CHECK(a.getPlayer2()->getName() == b.getPlayer2Name());

    CHECK(compareScores(*score1, b.getPlayer1Score()));
    CHECK(compareScores(*score2, b.getPlayer2Score()));

    CHECK(std::regex_match(b.getId(), std::regex(".{4}/.{2}/.{2}-.{2}:.{2}:.{2}")));
}