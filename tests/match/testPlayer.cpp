#include "doctest.hpp"
#include <stdexcept>

#include "Player.hpp"
#include "Constants.hpp"

TEST_CASE("Constructing a player with empty string") {
    CHECK_THROWS_AS(Player(""), std::invalid_argument);
}

TEST_CASE("Trying to set a player name to empty string") {
    Player a;
    CHECK_THROWS_AS(a.setName(""), std::invalid_argument);
}

TEST_CASE("Constructing a player with set name") {
    Player a("teste");
    CHECK(a.getName() == "teste");
}

TEST_CASE("Construct player with default name") {
    Player a;
    CHECK(a.getName() == "Player");
}

TEST_CASE("Construct player and check if board has default values") {
    Player a;
    std::shared_ptr<Board> pointer = a.getBoard();
    CHECK(pointer->getWidth() == DEFAULT_BOARD_AMOUNT_HORIZONTAL_CELLS);
    CHECK(pointer->getHeight() == DEFAULT_BOARD_AMOUNT_VERTICAL_CELLS);
}

TEST_CASE("Construct player and check that score has no values") {
    Player a;
    std::shared_ptr<Score> pointer = a.getScore();

    CHECK(pointer->getDestroyedTroops() == 0);
    CHECK(pointer->getHitShoots() == 0);
    CHECK(pointer->getLostTroops() == 0);
    CHECK(pointer->getRemainingTroops() == 0);
    CHECK(pointer->getTotalAmountShoots() == 0);
}