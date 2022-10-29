#include "raylib.h"

#include "Button.hpp"
#include "Component.hpp"

#include "Colors.hpp"

const Color Components::Button::DEFAULT_BACKGROUND_COLOR = DEFAULT_BALCK;

Components::Button::Button() {
    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Button::~Button() {}

void Components::Button::render() {
    background.x = getXPosition();
    background.y = getYPosition();
    background.height = getHeight();
    background.width = getWidth();

    Color renderedBackgroundColor;
    if(checkMouseOver()) {
        renderedBackgroundColor = getMouseHoverBackgroundColor();
    }
    else {
        renderedBackgroundColor = getBackgroundColor();
    }

    DrawRectangleRec(background, renderedBackgroundColor);
    return;
}

bool Components::Button::checkClick() {
    return (checkMouseOver() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

bool Components::Button::checkMouseOver() {
    return (isEnabled() && CheckCollisionPointRec(GetMousePosition(), background));
}

#pragma region .: Gets-Sets :.

void Components::Button::setBackgroundColor(const Color color) {
    this->backgroundColor = color;
    return;
}

Color Components::Button::getBackgroundColor() const {
    return backgroundColor;
}

void Components::Button::setMouseHoverBackgroundColor(const Color color) {
    this->mouseHoverBackgroundColor = color;
    return;
}

Color Components::Button::getMouseHoverBackgroundColor() const {
    return mouseHoverBackgroundColor;
}

#pragma endregion
