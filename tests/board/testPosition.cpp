#include "doctest.hpp"
#include <stdexcept>
#include "Position.hpp"
#include "Submarine.hpp"

TEST_CASE("Initialize a position and set a troop to it") {
    Position a(1,2);

    CHECK_FALSE(a.hasTroop());

    std::shared_ptr<Troop> pointer(new Submarine());
    a.setTroop(pointer);

    CHECK(pointer.get() == a.getTroop().get());
    CHECK(a.hasTroop());
}

TEST_CASE("Initialize a position and check for its x and y values") {
    Position a(1,2);
    CHECK(a.getX() == 1);
    CHECK(a.getY() == 2); 
}

TEST_CASE("Initailize a position with negative numbers") {
    CHECK_THROWS_AS(Position(-1,2), std::invalid_argument);
    CHECK_THROWS_AS(Position(1,-2), std::invalid_argument);
}