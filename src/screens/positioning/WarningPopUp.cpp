#include <string>
#include "raylib.h"

#include "WarningPopUp.hpp"

#include "Screen.hpp"
#include "View.hpp"
#include "Text.hpp"
#include "ButtonText.hpp"

#include "StyleFunctions.hpp"
#include "Colors.hpp"

Views::WarningPopUp::WarningPopUp(const std::string message) :
    headerTitle(new Components::Text()),
    messageDisplay(new Components::Text()),
    buttonExit(new Components::ButtonText()) {
    this->message = message;

    buildMask();
    buildBackground();
    buildHeader();
    buildMassageDisplay();
    buildExitButton();

    findHeight();
    findWidth();

    setXPosition((Screens::Screen::getDisplayWidth() - getWidth()) / 2);
    setYPosition((Screens::Screen::getDisplayHeight() - getHeight()) / 2);
}

Views::WarningPopUp::~WarningPopUp() {}

void Views::WarningPopUp::render() {
    renderMask();
    renderBackground();

    renderHeader();
    messageDisplay->render();
    buttonExit->render();

    return;
}

bool Views::WarningPopUp::checkExit() {
    return buttonExit->checkClick();
}

#pragma region .: Styles :.

void Views::WarningPopUp::updateInnerComponentsPositions() {
    positionMask();
    positionBackground();
    positionHeader();
    positionMessageDisplay();
    positionExitButton();
    
    return;
}

void Views::WarningPopUp::findWidth() {
    this->width = background.width;
    return;
}

void Views::WarningPopUp::findHeight() {
    this->height = background.height;
    return;
}

void Views::WarningPopUp::buildMask() {
    mask.height = Screens::Screen::getDisplayHeight();
    mask.width = Screens::Screen::getDisplayWidth();

    return;
}

void Views::WarningPopUp::positionMask() {
    mask.x = 0;
    mask.y = 0;

    return;
}

void Views::WarningPopUp::renderMask() {
    Color maskColor = DEFAULT_BALCK;
    maskColor.a = 230;

    DrawRectangleRec(mask, maskColor);
    return;
}

void Views::WarningPopUp::buildBackground() {
    background.height = percentOf(36, Screens::Screen::getDisplayHeight());
    background.width = percentOf(81, Screens::Screen::getDisplayWidth());

    return;
}

void Views::WarningPopUp::positionBackground() {
    background.x = getXPosition();
    background.y = getYPosition();

    return;
}

void Views::WarningPopUp::renderBackground() {
    DrawRectangleRec(background, DEFAULT_WHITE);
    return;
}

void Views::WarningPopUp::buildHeader() {
    const float FONT_SIZE = percentOf(5.1, Screens::Screen::getDisplayHeight());
    const std::string POPUP_HEADER_TEXT = "AVISO!";

    header.width = percentOf(100, background.width);
    header.height = percentOf(9, Screens::Screen::getDisplayHeight());

    headerTitle->setTextColor(DEFAULT_WHITE);
    headerTitle->setFontSize(FONT_SIZE);
    headerTitle->setText(POPUP_HEADER_TEXT);

    return;
}

void Views::WarningPopUp::positionHeader() {
    header.x = background.x;
    header.y = background.y;

    headerTitle->setXPosition(header.x + (header.width - headerTitle->getWidth()) / 2);
    headerTitle->setYPosition(header.y + (header.height - headerTitle->getHeight()) / 2);

    return;
}

void Views::WarningPopUp::renderHeader() {
    DrawRectangleRec(header, BRIGHT_RED);
    headerTitle->render();

    return;
}

void Views::WarningPopUp::buildMassageDisplay() {
    const float FONT_SIZE = percentOf(2.1, Screens::Screen::getDisplayHeight());

    messageDisplay->setTextColor(DEFAULT_BALCK);
    messageDisplay->setFontSize(FONT_SIZE);
    messageDisplay->setText(message);

    return;
}

void Views::WarningPopUp::positionMessageDisplay() {
    messageDisplay->setXPosition(background.x + (background.width - messageDisplay->getWidth()) / 2);
    messageDisplay->setYPosition(background.y + (background.height - messageDisplay->getHeight()) / 2);

    return;
}

void Views::WarningPopUp::buildExitButton() {
    const std::string LABEL = "Fechar";

    buttonExit->setBackgroundColor(DEFAULT_BALCK);

    Color hoverColor = DEFAULT_BALCK;
    hoverColor.a = 230;
    buttonExit->setMouseHoverBackgroundColor(hoverColor);

    buttonExit->setTextColor(DEFAULT_WHITE);
    buttonExit->setMouseHoverTextColor(DEFAULT_WHITE);

    buttonExit->setHeight(percentOf(6, Screens::Screen::getDisplayHeight()));
    buttonExit->setWidth(percentOf(15, Screens::Screen::getDisplayWidth()));

    buttonExit->setFontSize(Components::Text::getDefaultFontSize());
    buttonExit->setText(LABEL);

    return;
}

void Views::WarningPopUp::positionExitButton() {
    const float MARGIN_BOTTON = percentOf(6, background.height);

    buttonExit->setXPosition(background.x + (background.width - buttonExit->getWidth()) / 2);
    buttonExit->setYPosition(background.y + background.height - buttonExit->getHeight() - MARGIN_BOTTON);

    return;
}

#pragma endregion
