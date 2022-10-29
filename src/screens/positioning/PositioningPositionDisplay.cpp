#include "./PositioningPositionDisplay.hpp"

#include "Point.hpp"
#include "Colors.hpp"

Views::PositioningPositionDisplay::PositioningPositionDisplay(const Point boardCoordinates) : 
    PositionDisplay(boardCoordinates) {
    setXPosition(0.0);
    setYPosition(0.0);
}

Views::PositioningPositionDisplay::PositioningPositionDisplay(std::shared_ptr<Position> position) : 
    PositionDisplay(position) {
    setXPosition(0.0);
    setYPosition(0.0);
}

Views::PositioningPositionDisplay::~PositioningPositionDisplay() {}

void Views::PositioningPositionDisplay::render() {
    Color renderedBackgroundColor;
    if(isMarked()) {
        renderedBackgroundColor = getMarkedColor();
    }
    else if (containsTroop()) {
        renderedBackgroundColor = BRIGHT_GREEN;
    }
    else if (checkMouseOver()) {
        renderedBackgroundColor = hoveredBackgroundColor;
    }
    else {
        renderedBackgroundColor = backgroundColor;
    }

    DrawRectangleRec(background, renderedBackgroundColor);
    
    if(containsTroop()) {
        troopImage->render();
    }
    
    return;
}

bool Views::PositioningPositionDisplay::checkMouseEnter() {
    if(checkMouseOver() && !mouseHasEntered) {
        mouseHasEntered = true;
        return true;
    }

    return false;
}

bool Views::PositioningPositionDisplay::checkMouseExit() {
    if(!checkMouseOver() && mouseHasEntered) {
        mouseHasEntered = false;
        return true;
    }

    return false;
}

bool Views::PositioningPositionDisplay::checkMouseRightClick() {
    return (checkMouseOver() && IsMouseButtonReleased(MOUSE_BUTTON_RIGHT));
}

#pragma region .: Gets-Sets :.

void Views::PositioningPositionDisplay::setMarked(const bool marked) {
    this->marked = marked;
    return;
}

bool Views::PositioningPositionDisplay::isMarked() const {
    return marked;
}

void Views::PositioningPositionDisplay::setMarkedColor(const Color color) {
    markedColor = color;
    return;
}

Color Views::PositioningPositionDisplay::getMarkedColor() const {
    return markedColor;
}

#pragma endregion
