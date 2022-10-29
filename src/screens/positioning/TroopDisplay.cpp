#include <string>
#include <sstream>
#include "raylib.h"

#include "TroopDisplay.hpp"

#include "Text.hpp"
#include "Image.hpp"

#include "Screen.hpp"

#include "StyleFunctions.hpp"
#include "Colors.hpp"

Views::TroopDisplay::TroopDisplay(const unsigned int amount, const std::string troopName, const std::string troopImagePath) :
    amountTroopType(new Components::Text(buildAmountTroopTypeTextLabel(amount, troopName))),
    troopImage(new Components::Image(troopImagePath)) {
    setAmount(amount);
    setTroopName(troopName);

    buildAmountTroopTypeText();
    buildTroopImage();

    setXPosition(0.0);
    setYPosition(0.0);

    findHeight();
    findWidth();

    buildBackground();
}

Views::TroopDisplay::~TroopDisplay() {}

void Views::TroopDisplay::render() {
    renderBackground();
    amountTroopType->render();
    troopImage->render();
    
    return;
}

bool Views::TroopDisplay::checkClick() {
    return (checkMouseOver() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && getAmount() > 0);
}

bool Views::TroopDisplay::checkMouseOver() {
    return (isEnabled() && CheckCollisionPointRec(GetMousePosition(), background));
}

#pragma region .: Styles :.

void Views::TroopDisplay::updateInnerComponentsPositions() {
    poisitionAmountTroopTypeText();
    positionTroopImage();
    positionBackground();

    return;
}

void Views::TroopDisplay::findWidth() {
    this->width = (amountTroopType->getWidth() > troopImage->getWidth()) ? amountTroopType->getWidth() : troopImage->getWidth();
    return;
}

void Views::TroopDisplay::findHeight() {
    this->height = abs(amountTroopType->getYPosition() - troopImage->getYPosition()) + troopImage->getHeight();
    return;
}

void Views::TroopDisplay::buildAmountTroopTypeText() {
    const float FONT_SIZE = percentOf(1.8, Screens::Screen::getDisplayHeight());

    amountTroopType->setFontSize(FONT_SIZE);
    amountTroopType->setTextColor(DEFAULT_WHITE);

    return;
}

std::string Views::TroopDisplay::buildAmountTroopTypeTextLabel(const unsigned int amount, const std::string troopName) const {
    std::stringstream label;
    label.clear();
    label << std::to_string(amount) << "x " << troopName;

    return label.str();
}

void Views::TroopDisplay::poisitionAmountTroopTypeText() {
    amountTroopType->setXPosition(getXPosition());
    amountTroopType->setYPosition(getYPosition());

    return;
}

void Views::TroopDisplay::buildTroopImage() {
    troopImage->setHeight(percentOf(6, Screens::Screen::getDisplayHeight()));
    return;
}

void Views::TroopDisplay::positionTroopImage() {
    const float MARGIN_TOP = percentOf(1.5, Screens::Screen::getDisplayHeight());

    troopImage->setXPosition(amountTroopType->getXPosition() + (amountTroopType->getWidth() - troopImage->getWidth()) / 2);
    troopImage->setYPosition(amountTroopType->getYPosition() + amountTroopType->getHeight() + MARGIN_TOP);

    return;
}

void Views::TroopDisplay::buildBackground() {
    background.width = this->width;
    background.height = this->height;

    background.x = getXPosition();
    background.y = getYPosition();

    return;
}

void Views::TroopDisplay::renderBackground() {
    DrawRectangleRec(background, TRANSPARENT);
    return;
}

void Views::TroopDisplay::positionBackground() {
    background.x = getXPosition();
    background.y = getYPosition();

    return;
}

void Views::TroopDisplay::updateLabelValue() {
    amountTroopType->setText(buildAmountTroopTypeTextLabel(getAmount(), getTroopName()));
    return;
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::TroopDisplay::setAmount(const unsigned int amount) {
    this->amount = amount;
    updateLabelValue();
    return;
}

unsigned int Views::TroopDisplay::getAmount() const {
    return amount;
}

void Views::TroopDisplay::decrementAmount() {
    this->amount = amount - 1;
    updateLabelValue();
    return;
}

void Views::TroopDisplay::incrementAmount() {
    this->amount = amount + 1;
    updateLabelValue();
    return;
}

void Views::TroopDisplay::setTroopName(const std::string troopName) {
    this->troopName = troopName;
    updateLabelValue();
    return;
}

std::string Views::TroopDisplay::getTroopName() const {
    return troopName;
}

void Views::TroopDisplay::setTroopImageWidth(const float width) {
    troopImage->setWidth(width);
    findWidth();
    return;
}

#pragma endregion
