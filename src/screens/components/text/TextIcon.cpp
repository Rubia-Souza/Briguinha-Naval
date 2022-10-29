#include "TextIcon.hpp"

#include "Text.hpp"
#include "Image.hpp"

#include "Screen.hpp"

#include "StyleFunctions.hpp"

Components::TextIcon::TextIcon(const std::string iconPath, const std::string text) :
    text(new Components::Text(text)),
    icon(new Components::Image(iconPath)) {
    setXPosition(0.0);
    setYPosition(0.0);

    updateSizes();
}

Components::TextIcon::~TextIcon() {}

void Components::TextIcon::render() {
    icon->render();
    text->render();

    return;
}

#pragma region .: Styles :.

void Components::TextIcon::findWidth() {
    width = icon->getWidth() + text->getWidth() + getIconMarginRight();
    return;
}

void Components::TextIcon::findHeight() {
    height = (icon->getHeight() > text->getHeight()) ? icon->getHeight() : text->getHeight();
    return;
}

void Components::TextIcon::updateSizes() {
    findHeight();
    findWidth();

    return;
}

void Components::TextIcon::updateInnerComponentsPositions() {
    icon->setXPosition(getXPosition());
    icon->setYPosition(getYPosition());

    text->setXPosition(icon->getXPosition() + icon->getWidth() + getIconMarginRight());
    text->setYPosition(icon->getYPosition() + (icon->getHeight() - text->getHeight()) / 2);

    return;
}

float Components::TextIcon::getIconMarginRight() const {
    return percentOf(0.9, Screens::Screen::getDisplayWidth());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Components::TextIcon::setText(const std::string text) {
    this->text->setText(text);
    updateSizes();
    updateInnerComponentsPositions();
    return;
}

std::string Components::TextIcon::getText() const {
    return text->getText();
}

void Components::TextIcon::setFontSize(const float fontSize) {
    text->setFontSize(fontSize);
    updateSizes();
    updateInnerComponentsPositions();
    return;
}

float Components::TextIcon::getFontSize() const {
    return text->getFontSize();
}

void Components::TextIcon::setFontFamily(const Font font) {
    text->setFontFamily(font);
    updateSizes();
    updateInnerComponentsPositions();
    return;
}

Font Components::TextIcon::getFontFamily() const {
    return text->getFontFamily();
}

void Components::TextIcon::setTextColor(const Color color) {
    text->setTextColor(color);
    return;
}

Color Components::TextIcon::getTextColor() const {
    return text->getTextColor();
}

void Components::TextIcon::setIconPath(const std::string path) {
    icon->setPath(path);
    updateSizes();
    updateInnerComponentsPositions();
    return;
}

std::string Components::TextIcon::getIconPath() const {
    return icon->getPath();
}

void Components::TextIcon::setIconHeight(const float height) {
    icon->setHeight(height);
    updateSizes();
    return;
}

float Components::TextIcon::getIconHeight() const {
    return icon->getHeight();
}

void Components::TextIcon::setIconWidth(const float width) {
    icon->setWidth(width);
    updateSizes();
    return;
}

float Components::TextIcon::getIconWidth() const {
    return icon->getWidth();
}

#pragma endregion
