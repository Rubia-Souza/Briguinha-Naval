#include "doctest.hpp"
#include <stdexcept>
#include "Crusier.hpp"

TEST_CASE("Getting default crusier name") {
    Crusier a;
    CHECK(a.getTroopName() == "Crusador");
}

TEST_CASE("Getting crusier health before and after damage") {
    Crusier a;
    CHECK(a.getHealth() == 3);
    CHECK(a.getInitialHealth() == 3);
    a.takeDamage();
    CHECK(a.getHealth() == 2);
}

TEST_CASE("Trying to kill crusier") {
    Crusier a;
    CHECK_FALSE(a.isDead());
    a.takeDamage(); a.takeDamage(); a.takeDamage();
    CHECK(a.getHealth() == 0);
    CHECK(a.isDead());
}

TEST_CASE("Trying to damage crusier after its dead") {
    Crusier a;
    a.takeDamage(); a.takeDamage(); a.takeDamage();

    CHECK_THROWS_AS(a.takeDamage(), std::logic_error);
}

TEST_CASE("Check for horizontal positioning") {
    Crusier a;
    a.setPosition(Point(1,1), Orientation::HORIZONTAL);
    std::vector<Point> expected = {Point(1,1), Point(1,2), Point(1,3)}, pos = a.getOccupiedPositions();
    CHECK(pos.size() == 3);
    for(int i=0; i < 3; i++) CHECK(pos[i] == expected[i]);
}

TEST_CASE("Check for vertical positioning") {
    Crusier a;
    a.setPosition(Point(1,1), Orientation::VERTICAL);
    std::vector<Point> expected = {Point(1,1), Point(2,1), Point(3,1)}, pos = a.getOccupiedPositions();
    CHECK(pos.size() == 3);
    for(int i=0; i < 3; i++) CHECK(pos[i] == expected[i]);
}

TEST_CASE("Check if points are occupied") {
    Crusier a;
    for(int i=1; i < 4; i++) CHECK_FALSE(a.containsPoint(Point(1,i)));
    a.setPosition(Point(1,1), Orientation::HORIZONTAL);
    for(int i=1; i < 4; i++) CHECK(a.containsPoint(Point(1,i)));
}

TEST_CASE("Check if initial positioning is empty") {
    Crusier a;
    CHECK(a.getOccupiedPositions().size() == 0);
}