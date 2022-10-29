#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include <memory>
#include <string>

#include "Screen.hpp"

#include "Constants.hpp"

namespace Screens {
    class ScreenManager {
        public:
            static const std::string WINDOW_NAME;
            static const float DEFAULT_FPS;

        private:
            static std::shared_ptr<ScreenManager> instance;
            
            std::shared_ptr<Screen> actualScreen = nullptr;
            std::shared_ptr<Screen> lastScreen = nullptr;

            /**
             * @brief Create the Screen Manager singleton.
             */
            ScreenManager();

        public:
            /**
             * @brief Destroy the Screen Manager singleton.
             */
            virtual ~ScreenManager();

            /**
             * @brief Setup the window default values.
             */
            static void initializeWindow();

            /**
             * @brief Close the game window.
             */
            static void closeWindow();

            /**
             * @brief Load a screen that can be rendered.
             * 
             * @param screen is the screen that will be loaded and can be rendered.
             */
            void loadScreen(const std::shared_ptr<Screen> screen);

            /**
             * @brief Render the actual screen that was loaded.
             */
            void renderScreen();

            /**
             * @brief Get the instance of the Screen Manager.
             * 
             * @return The instance of the Screen Manager.
             */
            static std::shared_ptr<ScreenManager> getScreenManager();
        
        private:
            /**
             * @brief Set the window to be fullscreen.
             */
            static void setDisplayToFullScreen();
    };
}

#endif
