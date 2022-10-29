#ifndef TITLE_SCREEN_HPP
#define TITLE_SCREEN_HPP

#include <memory>
#include "raylib.h"

#include "Screen.hpp"

#include "Text.hpp"
#include "Image.hpp"
#include "ButtonText.hpp"

namespace Screens {
    class TitleScreen : public Screen {
        private:
            Rectangle titleBackground;
            std::unique_ptr<Components::Text> titleFirstPart = nullptr;
            std::unique_ptr<Components::Text> titleSecondPart = nullptr;

            std::unique_ptr<Components::ButtonText> buttonJogar = nullptr;
            std::unique_ptr<Components::ButtonText> buttonPlacar = nullptr;
            std::unique_ptr<Components::ButtonText> buttonSair = nullptr;

            std::unique_ptr<Components::Image> backgroundImage = nullptr;

        public:
            /**
             * @brief Create the Title Screen of the game.
             */
            TitleScreen();

            /**
             * @brief Destroy the Title Screen.
             */
            virtual ~TitleScreen();
        
        protected:
            /**
             * @brief Render the window in the interface.
             */
            virtual void renderScreen() override;

            /**
             * @brief Handle any event that can be trigged in the interface.
             */
            virtual void handleEvents() override;

        private:
            /**
             * @brief Build background image styles.
             */
            void buildBackgroundImage();

            /**
             * @brief Build title styles.
             */
            void buildTitle();

            /**
             * @brief Render title styles.
             */
            void renderTitle();

            /**
             * @brief Build play button styles.
             */
            void buildJogarButton();

            /**
             * @brief Build score button styles.
             */
            void buildPlacarButton();

            /**
             * @brief Build exit button styles.
             */
            void buildSairButton();

            /**
             * @brief Get title margin botton value.
             * 
             * @return Title margin botton style value.
             */
            float getTitleMarginBotton() const;

            /**
             * @brief Get button width value.
             * 
             * @return Button width style value.
             */
            float getDefaultButtonWidth() const;

            /**
             * @brief Get button height value.
             * 
             * @return Button height style value.
             */
            float getDefaultButtonHeight() const;

            /**
             * @brief Get button margin botton value.
             * 
             * @return Button margin botton style value.
             */
            float getButtonMarginBotton() const;

            /**
             * @brief Get the amount of reduction of the button width.
             * 
             * @return Amount of reduction of the button width value.
             */
            float getReducedButtonWidth() const;
    };   
}

#endif
