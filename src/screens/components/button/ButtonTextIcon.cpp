#include <iostream>
#include <string>
#include "raylib.h"

#include "ButtonTextIcon.hpp"

#include "Button.hpp"
#include "Screen.hpp"
#include "TextIcon.hpp"

#include "StyleFunctions.hpp"

Components::ButtonTextIcon::ButtonTextIcon(const std::string iconPath, const std::string label) :
    content(new Components::TextIcon(iconPath, label)) {
    setWidth(getDefaultWidth());
    setHeight(getDefaultHeight());

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::ButtonTextIcon::~ButtonTextIcon() {}

void Components::ButtonTextIcon::render() {
    Components::Button::render();
    Color renderedTextColor;

    if(checkMouseOver()) {
        renderedTextColor = getMouseHoverTextColor();
    }
    else {
        renderedTextColor = getTextColor();
    }

    content->setTextColor(renderedTextColor);
    content->render();
    return;
}

#pragma region .: Styles :.

void Components::ButtonTextIcon::updateInnerComponentsPositions() {
    background.x = getXPosition();
    background.y = getYPosition();

    content->setXPosition(background.x + (background.width - content->getWidth()) / 2);
    content->setYPosition(background.y + (background.height - content->getHeight()) / 2);

    return;
}

void Components::ButtonTextIcon::updateHeight() {
    if(content->getHeight() > getHeight()) {
        height = content->getHeight();
    }

    return;
}

void Components::ButtonTextIcon::updateWidth() {
    if(content->getWidth() > getWidth()) {
        width = content->getWidth();
    }

    return;
}

float Components::ButtonTextIcon::getDefaultWidth() {
    return percentOf(6, Screens::Screen::getDisplayWidth());
}

float Components::ButtonTextIcon::getDefaultHeight() {
    return percentOf(6, Screens::Screen::getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Components::ButtonTextIcon::setHeight(const float height) {
    this->height = (height < content->getHeight()) ? content->getHeight() : height;
    background.height = this->height;
    
    return;
}

void Components::ButtonTextIcon::setWidth(const float width) {
    this->width = (width < content->getWidth()) ? content->getWidth() : width;
    background.width = this->width;
    
    return;
}

void Components::ButtonTextIcon::setIconPath(const std::string path) {
    content->setIconPath(path);
    return;
}

std::string Components::ButtonTextIcon::getIconPath() const {
    return content->getIconPath();
}

void Components::ButtonTextIcon::setIconHeight(const float height) {
    if(height > getHeight()) {
        setHeight(height);
    }

    content->setIconHeight(height);
    return;
}

float Components::ButtonTextIcon::getIconHeight() const {
    return content->getIconHeight();
}

void Components::ButtonTextIcon::setIconWidth(const float width) { 
    if(width > getWidth()) {
        setWidth(width);
    }

    content->setIconWidth(width);
    return;
}

float Components::ButtonTextIcon::getIconWidth() const {
    return content->getIconWidth();
}

void Components::ButtonTextIcon::setText(const std::string content) {
    this->content->setText(content);
    
    updateHeight();
    updateWidth();

    return;
}

std::string Components::ButtonTextIcon::getText() const {
    return content->getText();
}

void Components::ButtonTextIcon::setFontSize(const float fontSize) {
    content->setFontSize(fontSize);
    
    updateHeight();
    updateWidth();

    return;
}

float Components::ButtonTextIcon::getFontSize() const {
    return content->getFontSize();
}

void Components::ButtonTextIcon::setFontFamily(const Font font) {
    content->setFontFamily(font);
    
    updateHeight();
    updateWidth();

    return;
}

Font Components::ButtonTextIcon::getFontFamily() const {
    return content->getFontFamily();
}

void Components::ButtonTextIcon::setTextColor(const Color color) {
    textColor = color;
    return;
}

Color Components::ButtonTextIcon::getTextColor() const {
    return textColor;
}

void Components::ButtonTextIcon::setMouseHoverTextColor(const Color color) {
    mouseHoverTextColor = color;
    return;
}

Color Components::ButtonTextIcon::getMouseHoverTextColor() const {
    return mouseHoverTextColor;
}

void Components::ButtonTextIcon::setXPosition(const float xPosition) {
    position.x = xPosition;
    updateInnerComponentsPositions();

    return;
}

void Components::ButtonTextIcon::setYPosition(const float yPosition) {
    position.y = yPosition;
    updateInnerComponentsPositions();

    return;
}

void Components::ButtonTextIcon::setPosition(const float xPosition, const float yPosition) {
    position.x = xPosition;
    position.y = yPosition;
    updateInnerComponentsPositions();

    return;
}

void Components::ButtonTextIcon::setPosition(const Vector2 position) {
    this->position = position;
    updateInnerComponentsPositions();

    return;
}

#pragma endregion
