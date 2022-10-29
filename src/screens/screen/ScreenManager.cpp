#include <memory>
#include <string>
#include "raylib.h"

#include "ScreenManager.hpp"
#include "AssetsPaths.hpp"

const std::string Screens::ScreenManager::WINDOW_NAME = PROJECT_NAME;
const float Screens::ScreenManager::DEFAULT_FPS = 60;
std::shared_ptr<Screens::ScreenManager> Screens::ScreenManager::instance = nullptr;

Screens::ScreenManager::ScreenManager() {}

Screens::ScreenManager::~ScreenManager() {}

void Screens::ScreenManager::initializeWindow() {
    InitWindow(0, 0, WINDOW_NAME.c_str());

    setDisplayToFullScreen();
    SetTargetFPS(DEFAULT_FPS);

    Image gameLogo = LoadImage(Icons::LOGO.c_str());
    SetWindowIcon(gameLogo);

    return;
}

void Screens::ScreenManager::setDisplayToFullScreen() {
    const unsigned int displayWidth = GetScreenWidth();
    const unsigned int displayHeight = GetScreenHeight();

    SetWindowMinSize(displayWidth, displayHeight);
    SetWindowSize(displayWidth, displayHeight);
    
    if(!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    return;
}

void Screens::ScreenManager::closeWindow() {
    CloseWindow(); // TODO: Verificar erro que ocorre ao encerrar a execução desta forma
    return;
}

void Screens::ScreenManager::loadScreen(const std::shared_ptr<Screen> screen) {
    lastScreen = actualScreen;
    actualScreen = screen;
    return;
}

void Screens::ScreenManager::renderScreen() {
    if(lastScreen.use_count() == 1) {
        lastScreen.reset();
    }

    if(actualScreen != nullptr) {
        actualScreen->render();
    }

    return;
}

#pragma region .: Gets-Sets :.

std::shared_ptr<Screens::ScreenManager> Screens::ScreenManager::getScreenManager() {
    if(instance == nullptr) {
        instance = std::unique_ptr<Screens::ScreenManager>(new Screens::ScreenManager());
    }

    return instance;
}

#pragma endregion
