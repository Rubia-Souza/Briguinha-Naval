#include <string>
#include "raylib.h"

#include "AssetsLoader.hpp"

#include "Text.hpp"
#include "Screen.hpp"

#include "StyleFunctions.hpp"
#include "AssetsPaths.hpp"
#include "Colors.hpp"

const float Components::Text::DEFAULT_FONT_SPACING = 1.0;
const Color Components::Text::DEFAULT_COLOR = DEFAULT_WHITE;

Components::Text::Text() {
    setFontFamily(getDefaultFontFamily());
    setFontSize(getDefaultFontSize());
    setTextColor(DEFAULT_COLOR);
    setText("");

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content) {
    setFontFamily(getDefaultFontFamily());
    setFontSize(getDefaultFontSize());
    setTextColor(DEFAULT_COLOR);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const float fontSize) {
    setFontFamily(getDefaultFontFamily());
    setTextColor(DEFAULT_COLOR);
    setFontSize(fontSize);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const Color textColor) {
    setFontFamily(getDefaultFontFamily());
    setFontSize(getDefaultFontSize());
    setTextColor(textColor);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const Font fontFamily) {
    setFontFamily(fontFamily);
    setFontSize(getDefaultFontSize());
    setTextColor(DEFAULT_COLOR);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const float fontSize, const Color textColor) {
    setFontFamily(getDefaultFontFamily());
    setFontSize(fontSize);
    setTextColor(textColor);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const float fontSize, const Font fontFamily) {
    setFontFamily(fontFamily);
    setFontSize(fontSize);
    setTextColor(DEFAULT_COLOR);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const Color textColor, const Font fontFamily) {
    setFontFamily(fontFamily);
    setFontSize(getDefaultFontSize());
    setTextColor(textColor);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::Text(const std::string content, const float fontSize, const Color textColor, const Font fontFamily) {
    setFontFamily(fontFamily);
    setTextColor(textColor);
    setFontSize(fontSize);
    setText(content);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Text::~Text() {}

void Components::Text::render() {
    DrawTextEx(
        getFontFamily(),
        getText().c_str(),
        getPosition(),
        getFontSize(),
        DEFAULT_FONT_SPACING,
        getTextColor()
    );
    return;
}

#pragma region .: Styles :.

void Components::Text::updateTextSize() {
    this->height = getDimensions().y;
    this->width = getDimensions().x;
    return;
}

Vector2 Components::Text::getDimensions() const {
    return MeasureTextEx(
        getFontFamily(),
        getText().c_str(),
        getFontSize(),
        DEFAULT_FONT_SPACING
    );
}

Font Components::Text::getDefaultFontFamily() {
    return AssetsLoader::getAssetLoader()->loadFont(Fonts::PRESS_START_2P);
}

float Components::Text::getDefaultFontSize() {
    return percentOf(2.7, Screens::Screen::getDisplayHeight());
}

float Components::Text::getDefaultTitleSize() {
    return percentOf(6, Screens::Screen::getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Components::Text::setFontSize(const float fontSize) {
    this->fontSize = fontSize;
    updateTextSize();
    return;
}

float Components::Text::getFontSize() const {
    return fontSize;
}

void Components::Text::setTextColor(const Color color) {
    this->textColor = color;
    return;
}

Color Components::Text::getTextColor() const {
    return textColor;
}

void Components::Text::setFontFamily(const Font font) {
    this->fontFamily = font;
    updateTextSize();
    return;
}

Font Components::Text::getFontFamily() const {
    return fontFamily;
}

void Components::Text::setText(const std::string content) {
    this->content = content;
    updateTextSize();
    return;
}

std::string Components::Text::getText() const {
    return content;
}

#pragma endregion
