#include <string>
#include "raylib.h"

#include "ButtonIcon.hpp"
#include "Button.hpp"

#include "Image.hpp"

Components::ButtonIcon::ButtonIcon(const std::string path) : icon(new Components::Image(path)) {
    setIconPath(path);
    setHoverIconPath(path);

    setHeight(getIconHeight());
    setWidth(getIconWidth());

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::ButtonIcon::ButtonIcon(const std::string path, const float height, const float width) :
    icon(new Components::Image(path, height, width)) {
    setIconPath(path);
    setHoverIconPath(path);

    setHeight(getIconHeight());
    setWidth(getIconWidth());

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::ButtonIcon::~ButtonIcon() {}

void Components::ButtonIcon::render() {
    Components::Button::render();

    icon->setXPosition(background.x + (background.width - icon->getWidth()) / 2);
    icon->setYPosition(background.y + (background.height - icon->getHeight()) / 2);

    if(checkMouseOver() && icon->getPath() != hoveredIconPath) {
        icon->setPath(hoveredIconPath);
    }
    else if(!checkMouseOver() && icon->getPath() != defaultIconPath) {
        icon->setPath(defaultIconPath);
    }

    icon->render();
    return;
}

#pragma region .: Gets-Sets :.

void Components::ButtonIcon::setIconHeight(const float height) {
    if(height > getHeight()) {
        return;
    }
    
    icon->setHeight(height);
    return;
}

float Components::ButtonIcon::getIconHeight() const {
    return icon->getHeight();
}

void Components::ButtonIcon::setIconWidth(const float width) {
    if(width > getWidth()) {
        return;
    }

    icon->setWidth(width);
    return;
}

float Components::ButtonIcon::getIconWidth() const {
    return icon->getWidth();
}

void Components::ButtonIcon::setIconPath(const std::string path) {
    defaultIconPath = path;
    return;
}

std::string Components::ButtonIcon::getIconPath() const {
    return defaultIconPath;
}

void Components::ButtonIcon::setHoverIconPath(const std::string path) {
    hoveredIconPath = path;
    return;
}

std::string Components::ButtonIcon::getHoverIconPath() const {
    return hoveredIconPath;
}

void Components::ButtonIcon::setHeight(const float height) {
    this->height = height;

    if(icon->getHeight() > height) {
        icon->setHeight(height);
        return;
    }
    return;
}

void Components::ButtonIcon::setWidth(const float width) {
    this->width = width;

    if(icon->getWidth() > width) {
        icon->setWidth(width);
        return;
    }
    return;
}

#pragma endregion
