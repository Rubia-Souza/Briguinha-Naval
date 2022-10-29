#include <string>
#include "raylib.h"

#include "AssetsLoader.hpp"

#include "Image.hpp"

const float Components::Image::DEFAULT_WIDTH = 64;
const float Components::Image::DEFAULT_HEIGHT = 64;

Components::Image::Image() {
    setWidth(DEFAULT_WIDTH);
    setHeight(DEFAULT_HEIGHT);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Image::Image(const std::string path) {
    setPath(path);
    setWidth(DEFAULT_WIDTH);
    setHeight(DEFAULT_HEIGHT);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Image::Image(const std::string path, const float height, const float width) {
    setPath(path);
    setHeight(height);
    setWidth(width);

    setXPosition(0.0);
    setYPosition(0.0);
}

Components::Image::~Image() {}

void Components::Image::render() {
    DrawTextureV(
        content,
        getPosition(),
        WHITE
    );

    return;
}

void Components::Image::loadImage() {
    content = AssetsLoader::getAssetLoader()->loadImage(getPath());
    return;
}

void Components::Image::updateImage() {
    loadImage();

    setHeight(getHeight());
    setWidth(getWidth());

    return;
}

#pragma region .: Gets-Sets :.

void Components::Image::setPath(const std::string path) {
    this->path = path;
    updateImage();

    return;
}

std::string Components::Image::getPath() const {
    return path;
}

void Components::Image::setHeight(const float height) {
    this->height = height;
    content.height = height;

    return;
}

void Components::Image::setWidth(const float width) {
    this->width = width;
    content.width = width;

    return;
}

#pragma endregion
