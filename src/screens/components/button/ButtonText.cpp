#include <memory>
#include <string>
#include "raylib.h"

#include "ButtonText.hpp"

#include "Component.hpp"
#include "Text.hpp"

#include "Colors.hpp"

Components::ButtonText::ButtonText() :
    text(new Text()) {
    setDefaultValues();
}

Components::ButtonText::ButtonText(const std::string labelText) :
    text(new Text(labelText)) {
    setDefaultValues();
}

Components::ButtonText::~ButtonText() {}

void Components::ButtonText::render() {
    Components::Button::render();

    if(checkMouseOver()) {
        text->setTextColor(getMouseHoverTextColor());
    }
    else {
        text->setTextColor(getTextColor());
    }

    text->setXPosition(background.x + (background.width - text->getWidth()) / 2);
    text->setYPosition(background.y + (background.height - text->getHeight()) / 2);
    
    text->render();
    return;
}

#pragma region .: Gets-Sets :.

void Components::ButtonText::setDefaultValues() {
    setFontFamily(Text::getDefaultFontFamily());
    setFontSize(Text::getDefaultFontSize());
    setTextColor(Text::DEFAULT_COLOR);
    setMouseHoverTextColor(Text::DEFAULT_COLOR);

    setXPosition(0.0);
    setYPosition(0.0);

    return;
}

void Components::ButtonText::setText(const std::string text) {
    this->text->setText(text);
    return;
}

std::string Components::ButtonText::getText() const {
    return text->getText();
}

void Components::ButtonText::setFontSize(const float fontSize) {
    text->setFontSize(fontSize);
    return;
}

float Components::ButtonText::getFontSize() const {
    return text->getFontSize();
}

void Components::ButtonText::setFontFamily(const Font font) {
    this->text->setFontFamily(font);
    return;
}

Font Components::ButtonText::getFontFamily() const {
    return text->getFontFamily();
}

void Components::ButtonText::setTextColor(const Color color) {
    this->textColor = color;
    return;
}

Color Components::ButtonText::getTextColor() const {
    return textColor;
}

void Components::ButtonText::setMouseHoverTextColor(const Color color) {
    this->mouseHoverTextColor = color;
    return;
}

Color Components::ButtonText::getMouseHoverTextColor() const {
    return mouseHoverTextColor;
}

void Components::ButtonText::setHeight(const float height) {
    if(text->getHeight() > height) {
        this->height = text->getHeight();
        return;
    }

    this->height = height;
    return;
}

void Components::ButtonText::setWidth(const float width) {
    if(text->getWidth() > width) {
        this->width = text->getWidth();
        return;
    }

    this->width = width;
    return;
}

#pragma endregion
