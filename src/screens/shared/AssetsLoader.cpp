#include <string>
#include <memory>
#include <map>
#include "raylib.h"

#include "AssetsLoader.hpp"

std::shared_ptr<AssetsLoader> AssetsLoader::instance = nullptr;

AssetsLoader::AssetsLoader() {}

AssetsLoader::~AssetsLoader() {
    unloadFonts();
    unloadImages();
}

Texture2D AssetsLoader::loadImage(const std::string path) {
    if(images.find(path) == images.end()) {
        images.insert(std::pair<std::string, Texture2D>(path, LoadTexture(path.c_str())));
    }

    return images.at(path);
}

Font AssetsLoader::loadFont(const std::string path) {
    if(fonts.find(path) == fonts.end()) {
        fonts.insert(std::pair<std::string, Font>(path, LoadFont(path.c_str())));
    }
    
    return fonts.at(path);
}

std::shared_ptr<AssetsLoader> AssetsLoader::getAssetLoader() {
    if(instance == nullptr) {
        instance = std::shared_ptr<AssetsLoader>(new AssetsLoader());
    }

    return instance;
}

void AssetsLoader::unloadImages() {
    std::map<std::string, Texture2D>::iterator iterator;

    for(iterator = images.begin(); iterator != images.end(); iterator++) {
        UnloadTexture(iterator->second);
    }
    images.clear();

    return;
}

void AssetsLoader::unloadFonts() {
    std::map<std::string, Font>::iterator iterator;

    for(iterator = fonts.begin(); iterator != fonts.end(); iterator++) {
        UnloadFont(iterator->second);
    }
    fonts.clear();

    return;
}
