#include "doctest.hpp"
#include <stdexcept>

#include "Battleship.hpp"

TEST_CASE("Check default battleship name") {
    Battleship a;
    CHECK(a.getTroopName() == "Encouracado");
}

TEST_CASE("Check battleship health before and after damage") {
    Battleship a;
    CHECK(a.getHealth() == 4);
    CHECK(a.getInitialHealth() == 4);
    a.takeDamage();
    CHECK(a.getHealth() == 3);
}

TEST_CASE("Trying to kill a battleship") {
    Battleship a;
    CHECK_FALSE(a.isDead());
    for(int i=0; i < 4; i++) a.takeDamage();
    CHECK(a.getHealth() == 0);
    CHECK(a.isDead());
}

TEST_CASE("Trying to damage cruiser after its dead") {
    Battleship a;
    for(int i=0; i < 4; i++) a.takeDamage();
    CHECK_THROWS_AS(a.takeDamage(), std::logic_error);
}

TEST_CASE("Check for horizontal positioning") {
    Battleship a;
    a.setPosition(Point(1,1), Orientation::HORIZONTAL);
    std::vector<Point> expected = {Point(1,1), Point(1,2), Point(1,3), Point(1,4)}, pos = a.getOccupiedPositions();
    CHECK(pos.size() == 4);
    for(int i=0; i < 4; i++) CHECK(pos[i] == expected[i]);
}

TEST_CASE("Check for vertical positioning") {
    Battleship a;
    a.setPosition(Point(1,1), Orientation::VERTICAL);
    std::vector<Point> expected = {Point(1,1), Point(2,1), Point(3,1), Point(4,1)}, pos = a.getOccupiedPositions();
    CHECK(pos.size() == 4);
    for(int i=0; i < 4; i++) CHECK(pos[i] == expected[i]);
}

TEST_CASE("Check if points are occupied") {
    Battleship a;
    for(int i=1; i < 5; i++) CHECK_FALSE(a.containsPoint(Point(1,i)));
    a.setPosition(Point(1,1), Orientation::HORIZONTAL);
    for(int i=1; i < 5; i++) CHECK(a.containsPoint(Point(1,i)));
}

TEST_CASE("Check if initial positioning is empty") {
    Battleship a;
    CHECK(a.getOccupiedPositions().size() == 0);
}

