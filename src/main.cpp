#include <memory>
#include "raylib.h"

#include "TitleScreen.hpp"
#include "ScreenManager.hpp"

int main() {
    Screens::ScreenManager::initializeWindow();

    std::shared_ptr<Screens::Screen> screen(new Screens::TitleScreen());
    Screens::ScreenManager::getScreenManager()->loadScreen(screen);

    while(!WindowShouldClose()) {
        Screens::ScreenManager::getScreenManager()->renderScreen();
    }

    return 0;
}
