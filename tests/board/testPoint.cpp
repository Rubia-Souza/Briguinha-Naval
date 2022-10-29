#include "doctest.hpp"
#include <stdexcept>
#include "Point.hpp"

TEST_CASE("Construct a point with custom values") { 
    Point a(5,8);
    CHECK(a.getX() == 5);
    CHECK(a.getY() == 8);
}

TEST_CASE("Construct a point and changes its values with setters") {
    Point a(5,8);
    a.setX(10);
    a.setY(1);
    CHECK(a.getX() == 10);
    CHECK(a.getY() == 1);
}

TEST_CASE("Overload '==' operator") { 
    Point a(1,2), b(1,2), c(3,7);
    CHECK(a == b);
    CHECK_FALSE(a == c);
}

TEST_CASE("Copy constructor") {
    Point a(1,3);
    Point b = a;
    CHECK(a == b);
}

TEST_CASE("'+' Operator overloader") {
    Point a(0,1), b(1,0);
    CHECK((a + b) == Point(1,1));
}

TEST_CASE("'<' Operator overloader") {
    Point a(1,0), b(1,1), c(0,1), d(1,0);
    CHECK(a < b);
    CHECK_FALSE(a < c);
    CHECK_FALSE(a < d);
}

TEST_CASE("Construct point with negative number") {
    CHECK_THROWS_AS(Point(-1,0), std::invalid_argument);
    CHECK_THROWS_AS(Point(0,-1), std::invalid_argument);
}

TEST_CASE("Set negative values to point") {
    Point a(1,0);
    CHECK_THROWS_AS(a.setX(-1), std::invalid_argument);
    CHECK_THROWS_AS(a.setY(-2), std::invalid_argument);
}