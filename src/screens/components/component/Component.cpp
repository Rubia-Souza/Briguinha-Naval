#include "Component.hpp"

#include "raylib.h"

const float Components::Component::DEFAUT_INITIAL_WIDTH = 1;
const float Components::Component::DEFAUT_INITIAL_HEIGHT = 1;
const Vector2 Components::Component::DEFAULT_INITIAL_POSITION = { 0, 0 };

Components::Component::~Component() {}

#pragma region .: Gets-Sets :.

float Components::Component::getWidth() const {
    return width;
}

float Components::Component::getHeight() const {
    return height;
}

void Components::Component::setXPosition(const float xPosition) {
    this->position.x = xPosition;
    return;
}

float Components::Component::getXPosition() const {
    return position.x;
}

void Components::Component::setYPosition(const float yPosition) {
    this->position.y = yPosition;
    return;
}

float Components::Component::getYPosition() const {
    return position.y;
}

void Components::Component::setPosition(const float xPosition, const float yPosition) {
    setXPosition(xPosition);
    setYPosition(yPosition);

    return;
}

void Components::Component::setPosition(const Vector2 position) {
    this->position = position;
    return;
}

Vector2 Components::Component::getPosition() const {
    return position;
}

#pragma endregion
