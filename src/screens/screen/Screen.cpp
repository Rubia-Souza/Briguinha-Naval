#include "./Screen.hpp"

#include "raylib.h"

Screens::Screen::~Screen() {}

void Screens::Screen::render() {
    BeginDrawing();
        ClearBackground(GetColor(0x052c46ff)); 

        if(isWindowActive) {
            renderScreen();
            handleEvents();
        }
    EndDrawing();
    return;
}

#pragma region .: Gets-Sets :.

bool Screens::Screen::isActive() const {
    return isWindowActive;
}

float Screens::Screen::getDisplayHeight() {
    return GetScreenHeight();
}

float Screens::Screen::getDisplayWidth() {
    return GetScreenWidth();
}

#pragma endregion
