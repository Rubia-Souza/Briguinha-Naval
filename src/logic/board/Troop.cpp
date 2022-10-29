#include <stdexcept>
#include <sstream>

#include "Troop.hpp"
#include "Point.hpp"

#include "Constants.hpp"

std::string Troop::getTroopName() {
    return "Tropa Generica";
}

Troop::Troop(const unsigned int health) : health(health) {}

Troop::~Troop() {}

void Troop::takeDamage() {
    if(isDead()) {
        throw std::logic_error("Ship is already out of health");
    }

    health--;
    return;
}

bool Troop::containsPoint(const Point point) const {
    for(Point coordenate : shape) {
        if(coordenate == point) {
            return true;
        }
    }

    return false;
}

void Troop::positionHorizontally(const Point initialPosition) {
    shape.clear();

    shape.push_back(initialPosition);
    for(unsigned int i = 1; i < getInitialHealth(); i++) {
        shape.push_back(Point(shape[i-1].getX(), shape[i-1].getY() + 1));
    }

    return;
}
        
void Troop::positionVertically(const Point initialPosition) {
    shape.clear();

    shape.push_back(initialPosition);
    for(unsigned int i = 1; i < getInitialHealth(); i++) {
        shape.push_back(Point(shape[i-1].getX() + 1, shape[i-1].getY()));
    }

    return;
}

void Troop::buildImagesMap(const std::string folderPathWithSpriteName) {
    images.clear();

    std::stringstream pattern;
    pattern.clear();
    pattern << folderPathWithSpriteName << "Part";

    std::stringstream fileName;
    for(unsigned int i = 0; i < shape.size(); i++) {
        fileName.str(std::string());
        fileName << pattern.str() << std::to_string(i + 1) << SPRITES_EXTENSION;

        images.insert(std::pair<Point, std::string>(shape[i], fileName.str()));
    }

    return;
}

bool Troop::isDead() const {
    return (health == 0);
}

#pragma region .: Gets-Sets :.

unsigned int Troop::getHealth() const {
    return health;
}

std::map<Point,std::string> Troop::getImages() const {
    return images;
}

std::string Troop::getImageInPoint(const Point point) const {
    if(images.empty() || images.find(point) == images.end()) {
        return "";
    }

    return images.at(point);
}

void Troop::setPosition(const Point initialPosition, const Orientation orientation) {
    if(orientation == HORIZONTAL) {
        positionHorizontally(initialPosition);
    }
    else {
        positionVertically(initialPosition);
    }

    return;
}

std::vector<Point> Troop::getOccupiedPositions() const {
    return shape;
}

#pragma endregion
