#include "doctest.hpp"
#include <stdexcept>

#include "MatchResults.hpp"

bool compareResults(Score a, Score b){
    if (a.getDestroyedTroops() != b.getDestroyedTroops()) return false;
    if (a.getHitShoots() != b.getHitShoots()) return false;
    if (a.getLostTroops() != b.getLostTroops()) return false;
    if (a.getRemainingTroops() != b.getRemainingTroops()) return false;
    if (a.getTotalAmountShoots() != b.getTotalAmountShoots()) return false;
    return true;
}

TEST_CASE("Creating a default MatchResults") {
    MatchResults a;
    CHECK(a.getPlayer1Name() == "");
    CHECK(a.getPlayer2Name() == "");
    CHECK(a.getId() == "");
}

TEST_CASE("Trying to make or set a MatchResults with empty id") {
    CHECK_THROWS_AS(MatchResults a("teste", Score(), "teste2", Score(), ""), std::invalid_argument);
    MatchResults a("teste", Score(), "teste2", Score(), "a");
    CHECK_THROWS_AS(a.setId(""), std::invalid_argument);
}

TEST_CASE("Trying to construct or set a MatchResults with id with spaces") {
    CHECK_THROWS_AS(MatchResults a("teste", Score(), "teste2", Score(), "a a"), std::invalid_argument);
    MatchResults a("teste", Score(), "teste2", Score(), "a");
    CHECK_THROWS_AS(a.setId("aaaa a"), std::invalid_argument);
}

TEST_CASE("Trying to construct MatchResults and getting attributes"){
    Score score1, score2(1,2,3,5,4);
    MatchResults match("player1", score1, "player2", score2, "id");
    CHECK(compareResults(score1, match.getPlayer1Score()));
    CHECK(compareResults(score2, match.getPlayer2Score()));
    CHECK("id" == match.getId());
    CHECK("player1" == match.getPlayer1Name());
    CHECK("player2" == match.getPlayer2Name());
}