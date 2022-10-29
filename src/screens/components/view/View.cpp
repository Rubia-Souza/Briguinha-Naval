#include "View.hpp"

#include "raylib.h"

Views::View::~View() {}

#pragma region .: Gets-Sets :.

void Views::View::setXPosition(const float xPosition) {
    Components::Component::setXPosition(xPosition);
    updateInnerComponentsPositions();
    return;
}

void Views::View::setYPosition(const float yPosition) {
    Components::Component::setYPosition(yPosition);
    updateInnerComponentsPositions();
    return;
}

void Views::View::setPosition(const float xPosition, const float yPosition) {
    Components::Component::setPosition(xPosition, yPosition);
    updateInnerComponentsPositions();
    return;
}

void Views::View::setPosition(const Vector2 position) {
    Components::Component::setPosition(position);
    updateInnerComponentsPositions();
    return;
}

#pragma endregion
