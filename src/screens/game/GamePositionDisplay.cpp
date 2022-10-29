#include <memory>

#include "GamePositionDisplay.hpp"

#include "Image.hpp"
#include "Screen.hpp"
#include "PositionDisplay.hpp"

#include "Colors.hpp"
#include "AssetsPaths.hpp"
#include "StyleFunctions.hpp"

Views::GamePositionDisplay::GamePositionDisplay(const Point boardCoordinates) :
    PositionDisplay(boardCoordinates),
    hitImage(new Components::Image()) {
    buildComponent();
}

Views::GamePositionDisplay::GamePositionDisplay(std::shared_ptr<Position> position) :
    PositionDisplay(position),
    hitImage(new Components::Image()) {
    buildComponent();
}

Views::GamePositionDisplay::~GamePositionDisplay() {}

void Views::GamePositionDisplay::buildComponent() {
    if(containsTroop()) {
        hitImage->setPath(Icons::RED_X);
        buildHitImage();

        setTroopImage(getTroop());
    }

    setXPosition(0.0);
    setYPosition(0.0);

    return;
}

void Views::GamePositionDisplay::render() {
    if(containsTroop()) {
        handleTroopRender();
    }
    else {
        handleDefaultRender();
    }
    
    return;
}

void Views::GamePositionDisplay::handleTroopRender() {
    Color renderedBackgroundColor;
    if(shouldRevealTroop()) {
        renderedBackgroundColor = BRIGHT_GREEN;
        DrawRectangleRec(background, renderedBackgroundColor);
        troopImage->render();
        return;
    }

    if(!wasClicked) {
        handleDefaultRender();
        return;
    }
    else {
        renderedBackgroundColor = TRANSPERENT_WHITE;
        DrawRectangleRec(background, renderedBackgroundColor);
        troopImage->render();
        hitImage->render();
        return;
    }

    return;
}

void Views::GamePositionDisplay::handleDefaultRender() {
    Color renderedBackgroundColor;

    if(wasClicked) {
        renderedBackgroundColor = TRANSPERENT_WHITE;
    }
    else if(checkMouseOver()) {
        renderedBackgroundColor = hoveredBackgroundColor;
    }
    else {
        renderedBackgroundColor = backgroundColor;
    }

    DrawRectangleRec(background, renderedBackgroundColor);
    return;
}

bool Views::GamePositionDisplay::checkClick() {
    if(!wasClicked && PositionDisplay::checkClick()) {
        wasClicked = true;
        return true;
    }

    return false;
}

#pragma region .: Styles :.

void Views::GamePositionDisplay::updateInnerComponentsPositions() {
    PositionDisplay::updateInnerComponentsPositions();
    positionHitImage();

    return;
}

void Views::GamePositionDisplay::buildHitImage() {
    if(!containsTroop()) {
        return;
    }

    hitImage->setHeight(getDefaultImageSize() - percentOf(1, Screens::Screen::getDisplayHeight()));
    hitImage->setWidth(getDefaultImageSize() - percentOf(1, Screens::Screen::getDisplayHeight()));
    return;
}

void Views::GamePositionDisplay::positionHitImage() {
    if(!containsTroop()) {
        return;
    }

    hitImage->setXPosition(background.x + (background.width - hitImage->getWidth()) / 2);
    hitImage->setYPosition(background.y + (background.height - hitImage->getHeight()) / 2);
    return;
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::GamePositionDisplay::setRevealTroop(const bool option) {
    this->revealTroop = option;
    return;
}

bool Views::GamePositionDisplay::shouldRevealTroop() const {
    return revealTroop;
}

#pragma endregion
