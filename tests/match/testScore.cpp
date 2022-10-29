#include "doctest.hpp"
#include <stdexcept>
#include "Score.hpp"

TEST_CASE("Initialize a score with custom valid values") {
    Score a(1,2,3,5,4);

    CHECK(a.getDestroyedTroops() == 1);
    CHECK(a.getRemainingTroops() == 2);
    CHECK(a.getLostTroops() == 3);
    CHECK(a.getTotalAmountShoots() == 5);
    CHECK(a.getHitShoots() == 4);
}

TEST_CASE("Initialize score with negative values") {
    CHECK_THROWS_AS(Score a(-1,2,3,5,4), std::invalid_argument);
    CHECK_THROWS_AS(Score a(1,-2,3,5,4), std::invalid_argument);
    CHECK_THROWS_AS(Score a(1,2,-3,5,4), std::invalid_argument);
    CHECK_THROWS_AS(Score a(1,2,3,-5,4), std::invalid_argument);
    CHECK_THROWS_AS(Score a(1,2,3,5,-4), std::invalid_argument);
}

TEST_CASE("Trying to set negative values to a score") {
    Score a;
    CHECK_THROWS_AS(a.setDestroyedTroops(-1), std::invalid_argument);
    CHECK_THROWS_AS(a.setRemainingTroops(-1), std::invalid_argument);
    CHECK_THROWS_AS(a.setLostTroops(-1), std::invalid_argument);
    CHECK_THROWS_AS(a.setHitShoots(-1), std::invalid_argument);
    CHECK_THROWS_AS(a.setTotalAmountShoots(-1), std::invalid_argument);
}

TEST_CASE("Trying to decrement remaining troops below zero") {
    Score a;
    CHECK_THROWS_AS(a.decrementRemainingTroops(), std::invalid_argument);
}

TEST_CASE("Incrementing each value") {
    Score a;
    a.setRemainingTroops(1);

    a.decrementRemainingTroops();
    a.incrementDestroyedTroops();
    a.incrementLostTroops();
    a.incrementTotalAmountShoots();
    a.incrementHitShoots();

    CHECK(a.getRemainingTroops() == 0);
    CHECK(a.getDestroyedTroops() == 1);
    CHECK(a.getLostTroops() == 1);
    CHECK(a.getTotalAmountShoots() == 1);
    CHECK(a.getHitShoots() == 1);
    CHECK(a.getInitialAmountShips() == 1);
}

TEST_CASE("Trying to set a value of hit shoots higher than total amount of shoots") {
    CHECK_THROWS_AS(Score a(1,2,3,4,5), std::invalid_argument);

    Score a;
    a.setTotalAmountShoots(10);
    CHECK_THROWS_AS(a.setHitShoots(11), std::invalid_argument);
    a.setHitShoots(10);
    CHECK_THROWS_AS(a.incrementHitShoots(), std::invalid_argument);
}

TEST_CASE("Trying to set a value of total amount of shoots lower than the amount of hit shoots") {
    Score a;
    a.setTotalAmountShoots(10);
    a.setHitShoots(10);

    CHECK_THROWS_AS(a.setTotalAmountShoots(9), std::invalid_argument);
}

TEST_CASE("Checking for precision formula") {
    Score a;
    a.setTotalAmountShoots(10);
    a.setHitShoots(5);
    CHECK(a.getPrecision() == 0.5);
}

TEST_CASE("Trying to get precision with 0 total amount of shoots") {
    Score a;
    CHECK_THROWS_AS(a.getPrecision(), std::logic_error);
}