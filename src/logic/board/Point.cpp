#include "Point.hpp"
#include <stdexcept>

Point::Point(const int x, const int y) {
    setX(x);
    setY(y);
}

Point::Point(const Point& point) {
    setX(point.getX());
    setY(point.getY());
}

Point::~Point() {}

#pragma region .: Gets-Sets :.

void Point::setX(const int x) {
    if(x < 0) throw std::invalid_argument("Point cannot have negative x");
    this->x = x;
    return;
}

int Point::getX() const {
    return x;
}

void Point::setY(const int y) {
    if(y < 0) throw std::invalid_argument("Point cannot have negative y");
    this->y = y;
    return;
}

int Point::getY() const {
    return y;
}

#pragma endregion

#pragma region .: Operators :.

bool Point::operator==(const Point& other) const {
    return this->getX() == other.getX() && this->getY() == other.getY();
}

bool Point::operator<(const Point& other) const {
    if(this->getX() == other.getX()) {
        return this->getY() < other.getY();
    }

    return this->getX() < other.getX();
}

Point Point::operator+(const Point& other) const {
    return Point(this->getX() + other.getX(), this->getY() + other.getY());
}

#pragma endregion
