#include "doctest.hpp"
#include <stdexcept>

#include "Submarine.hpp"

TEST_CASE("Checking for troop name") {
    Submarine a;
    CHECK(a.getTroopName() == "Submarino");
}

TEST_CASE("Check initial health"){
    Submarine a;
    CHECK(a.getHealth() == 1);
    CHECK(a.getInitialHealth() == 1);
}

TEST_CASE("Check health before and after taking damage"){
    Submarine a;
    CHECK(a.getHealth() == 1);
    CHECK(a.getInitialHealth() == 1);
    a.takeDamage();
    CHECK(a.getHealth() == 0);
}

TEST_CASE("Check vertical positioning") {
    Submarine a;
    a.setPosition(Point(1,1), Orientation::VERTICAL);
    std::vector<Point> v = a.getOccupiedPositions();
    CHECK(v.size() == 1);
    CHECK(Point(1,1) == v[0]);
}

TEST_CASE("Check horizontal positioning") {
    Submarine a;
    a.setPosition(Point(5,5), Orientation::HORIZONTAL);
    std::vector<Point> v = a.getOccupiedPositions();
    CHECK(v.size() == 1);
    CHECK(Point(5,5) == v[0]);
}

TEST_CASE("Check if submarine contains point") {
    Submarine a;
    a.setPosition(Point(5,5), Orientation::HORIZONTAL);
    CHECK_FALSE(a.containsPoint(Point(4,4)));
    a.setPosition(Point(4,4), Orientation::HORIZONTAL);
    CHECK(a.containsPoint(Point(4,4)));
}

TEST_CASE("Killing submarine") {
    Submarine a;
    a.takeDamage();
    CHECK(a.isDead());
}

TEST_CASE("Trying to damage the submarine after it dying"){
    Submarine a;
    a.takeDamage();
    CHECK_THROWS_AS(a.takeDamage(), std::logic_error);
}

TEST_CASE("Check if initial positioning is empty") {
    Submarine a;
    CHECK(a.getOccupiedPositions().size() == 0);
}