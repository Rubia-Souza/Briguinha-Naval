#ifndef SCREEN_HPP
#define SCREEN_HPP

namespace Screens {
    class Screen {
        protected:
            bool isWindowActive = true;

        public:
            /**
             * @brief Destroy the Screen object.
             */
            virtual ~Screen();

            /**
             * @brief Define the basic setup to render a screen with raylib.
             */
            virtual void render();

            /**
             * @brief Checks if the window is active.
             * 
             * @return Boolean indicates if the window should be rendered.
             */
            bool isActive() const;

            /**
             * @brief Get the display window height.
             * 
             * @return The window display height value.
             */
            static float getDisplayHeight();

            /**
             * @brief Get the display width.
             * 
             * @return The window display width value.
             */
            static float getDisplayWidth();
        
        protected:
            /**
             * @brief Render the window in the interface.
             */
            virtual void renderScreen() = 0;

            /**
             * @brief Handle any event that can be trigged in the interface.
             */
            virtual void handleEvents() = 0;
    };
}

#endif
