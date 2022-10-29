#include "doctest.hpp"
#include <stdexcept>

#include "Board.hpp"
#include "Submarine.hpp"

TEST_CASE("Initializing board with negative height or width") {
    CHECK_THROWS_AS(Board(-1,2), std::invalid_argument);
    CHECK_THROWS_AS(Board(1,-2), std::invalid_argument);
}

TEST_CASE("Initializing board with valid values and getting their values") {
    Board board(1,2);
    CHECK(board.getWidth() == 1);
    CHECK(board.getHeight() == 2);
}

TEST_CASE("Positions a troop in a valid position") {
    Board board(10,10);

    CHECK_FALSE(board.doesPositionContainsTroop(Point(5,4)));

    std::shared_ptr<Submarine> troop(new Submarine());
    troop->setPosition(Point(5,4), Orientation::HORIZONTAL);
    board.positionTroop(troop);

    CHECK(board.doesPositionContainsTroop(Point(5,4)));
}

TEST_CASE("Positions a troop in a valid positioning then removing it") {
    Board board(10,10);
    std::shared_ptr<Submarine> troop(new Submarine());
    troop->setPosition(Point(5,4), Orientation::HORIZONTAL);

    board.positionTroop(troop);
    board.removeTroop(troop);

    CHECK_FALSE(board.doesPositionContainsTroop(Point(5,4)));
}

TEST_CASE("Check if points are in or out of boundaries") {
    Board board(10,10);
    CHECK_FALSE(board.isPointWithinBoundaries(Point(10,5)));
    CHECK_FALSE(board.isPointWithinBoundaries(Point(5,10)));
    CHECK(board.isPointWithinBoundaries(Point(1,2)));
    CHECK(board.isPointWithinBoundaries(Point(4,5)));
}

TEST_CASE("Add multiple troops and get troop vector") {
    Board board(10,10);

    CHECK(board.getTroops().size() == 0);

    std::shared_ptr<Troop> a(new Submarine()), b(new Submarine());
    a->setPosition(Point(1,1), Orientation::VERTICAL);
    b->setPosition(Point(1,2), Orientation::HORIZONTAL);
    board.positionTroop(a);
    board.positionTroop(b);

    std::vector<std::shared_ptr<Troop>> vector = board.getTroops();
    CHECK(vector[0].get() == a.get());
    CHECK(vector[1].get() == b.get());
}

TEST_CASE("Get a position without a troop and add a troop to it afterwards") {
    Board board(10,10);
    std::shared_ptr<Position> a = board.getPosition(2,1);

    CHECK_FALSE(a->hasTroop());

    std::shared_ptr<Submarine> sub(new Submarine());
    sub->setPosition(Point(2,1), Orientation::HORIZONTAL);
    board.positionTroop(sub);

    CHECK(a->hasTroop());
    CHECK(a->getTroop().get() == sub.get());
}

TEST_CASE("Trying to get a point out of boundaries") {
    Board board(10,10);
    CHECK_THROWS_AS(board.getPosition(11,5), std::invalid_argument);
    CHECK_THROWS_AS(board.getPosition(5,15), std::invalid_argument);
}

TEST_CASE("Trying to get a troop with an out of bounds point") {
    Board board(10,10);
    CHECK_THROWS_AS(board.doesPositionContainsTroop(Point(11,1)), std::invalid_argument);
    CHECK_THROWS_AS(board.doesPositionContainsTroop(Point(1,-1)), std::invalid_argument);
}

TEST_CASE("Checking if a position out of bounds is valid, then a valid one") {
    Board board(10,10);
    std::shared_ptr<Troop> troop(new Submarine());
    troop->setPosition(Point(11,0), Orientation::HORIZONTAL);
    CHECK_FALSE(board.isPositionValid(troop->getOccupiedPositions()));
    troop->setPosition(Point(1,0), Orientation::HORIZONTAL);
    CHECK(board.isPositionValid(troop->getOccupiedPositions()));
}

TEST_CASE("Checking if position containing a troop is invalid") {
    Board board(10,10);
    std::shared_ptr<Troop> troop1(new Submarine());
    troop1->setPosition(Point(5,6), Orientation::HORIZONTAL);
    board.positionTroop(troop1);
    std::vector<Point> v = {Point(5,6)};
    CHECK_FALSE(board.isPositionValid(v));
}

TEST_CASE("Trying to position 2 troops on conflicting positions") {
    Board board(10,10);
    std::shared_ptr<Troop> troop1(new Submarine());
    troop1->setPosition(Point(5,0), Orientation::HORIZONTAL);
    board.positionTroop(troop1);
    std::shared_ptr<Troop> troop2(new Submarine());
    troop2->setPosition(Point(5,0), Orientation::HORIZONTAL);
    CHECK_THROWS_AS(board.positionTroop(troop2), std::invalid_argument);
}

TEST_CASE("Trying to position a troop that has not yet been positioned") {
    Board board(10,10);
    std::shared_ptr<Troop> troop1(new Submarine());
    CHECK_THROWS_AS(board.positionTroop(troop1), std::invalid_argument);
}