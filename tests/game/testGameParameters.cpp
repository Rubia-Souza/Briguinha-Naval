#include "doctest.hpp"
#include <stdexcept>

#include "GameParameters.hpp"

TEST_CASE("Check default parameters"){
    GameParameters a;
    CHECK(a.getAmountBattleshipTroops() == 3);
    CHECK(a.getAmountCrusierTroops() == 3);
    CHECK(a.getAmountSubmarineTroops() == 3);
    CHECK(a.getBoardAmountHorizontalCells() == 9);
    CHECK(a.getBoardAmountVerticalCells() == 9);
    CHECK(a.getTotalAmountOfTroops() == 9);
}

TEST_CASE("Set valid custom parameters") {
    GameParameters a;
    a.setAmountBattleshipTroops(1);
    a.setAmountCrusierTroops(1);
    a.setAmountSubmarineTroops(1);
    a.setBoardAmountHorizontalCells(5);
    a.setBoardAmountVerticalCells(5);

    CHECK(a.getAmountBattleshipTroops() == 1);
    CHECK(a.getAmountCrusierTroops() == 1);
    CHECK(a.getAmountSubmarineTroops() == 1);
    CHECK(a.getBoardAmountHorizontalCells() == 5);
    CHECK(a.getBoardAmountVerticalCells() == 5);
    CHECK(a.getTotalAmountOfTroops() == 3);
}

TEST_CASE("Trying to set negative values") {
    GameParameters a;

    CHECK_THROWS_AS(a.setAmountBattleshipTroops(-1),std::invalid_argument);
    CHECK_THROWS_AS(a.setAmountCrusierTroops(-1),std::invalid_argument);
    CHECK_THROWS_AS(a.setAmountSubmarineTroops(-1),std::invalid_argument);
    CHECK_THROWS_AS(a.setBoardAmountHorizontalCells(-1),std::invalid_argument);
    CHECK_THROWS_AS(a.setBoardAmountVerticalCells(-1),std::invalid_argument);
}