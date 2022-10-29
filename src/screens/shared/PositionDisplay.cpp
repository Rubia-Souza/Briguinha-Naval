#include "PositionDisplay.hpp"

#include "Screen.hpp"

#include "Point.hpp"
#include "Position.hpp"

#include "Colors.hpp"
#include "StyleFunctions.hpp"

Views::PositionDisplay::PositionDisplay(const Point boardCoordinates) :
    troopImage(new Components::Image()),
    position(new Position(boardCoordinates.getX(), boardCoordinates.getY())) {
    buildComponent();
}

Views::PositionDisplay::PositionDisplay(std::shared_ptr<Position> position) :
    troopImage(new Components::Image()),
    position(position) {
    buildComponent();
}

void Views::PositionDisplay::buildComponent() {
    buildBackground();
    buildTroopImage();

    setXPosition(0.0);
    setYPosition(0.0);

    findHeight();
    findWidth();

    return;
}

Views::PositionDisplay::~PositionDisplay() {}

bool Views::PositionDisplay::checkClick() {
    return (checkMouseOver() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

bool Views::PositionDisplay::checkMouseOver() {
    return (isEnabled() && CheckCollisionPointRec(GetMousePosition(), background));
}

#pragma region .: Styles :.

void Views::PositionDisplay::updateInnerComponentsPositions() {
    positionBackground();
    positionTroopImage();

    return;
}

void Views::PositionDisplay::findWidth() {
    this->width = background.width;
    return;
}

void Views::PositionDisplay::findHeight() {
    this->height = background.height;
    return;
}

void Views::PositionDisplay::buildBackground() {
    const float BACKGROUND_SIZE = percentOf(4.2, Screens::Screen::getDisplayHeight());

    background.height = BACKGROUND_SIZE;
    background.width = BACKGROUND_SIZE;

    backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = 153;

    hoveredBackgroundColor = TRANSPERENT_BLACK;

    return;
}

void Views::PositionDisplay::positionBackground() {
    background.x = getXPosition();
    background.y = getYPosition();

    return;
}

void Views::PositionDisplay::buildTroopImage() {
    troopImage->setHeight(getDefaultImageSize());
    troopImage->setWidth(getDefaultImageSize());

    return;
}

void Views::PositionDisplay::positionTroopImage() {
    troopImage->setXPosition(background.x + (background.width - troopImage->getWidth()) / 2);
    troopImage->setYPosition(background.y + (background.height - troopImage->getHeight()) / 2);
    
    return;
}

float Views::PositionDisplay::getDefaultImageSize() const {
    return percentOf(3.6, Screens::Screen::getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

Point Views::PositionDisplay::getCoordinates() const {
    return Point(position->getX(), position->getY());
}

void Views::PositionDisplay::setTroop(const std::shared_ptr<Troop> troop) {
    position->setTroop(troop);
    return;
}

std::shared_ptr<Troop> Views::PositionDisplay::getTroop() const {
    return position->getTroop();
}

void Views::PositionDisplay::setTroopImage(const std::shared_ptr<Troop> troop) {
    std::string path = troop->getImageInPoint(getCoordinates());
    setTroopImage(path);

    return;
}

void Views::PositionDisplay::setTroopImage(const std::string path) {
    troopImage->setPath(path);
    return;
}

bool Views::PositionDisplay::containsTroop() const {
    return (position->getTroop() != nullptr);
}

#pragma endregion
