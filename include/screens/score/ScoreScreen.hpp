#ifndef SCORE_SCREEN_HPP
#define SCORE_SCREEN_HPP

#include <vector>
#include <memory>
#include "raylib.h"

#include "Screen.hpp"

#include "Text.hpp"
#include "Image.hpp"
#include "ButtonText.hpp"
#include "ButtonIcon.hpp"

#include "MatchResults.hpp"

#include "MatchResultDisplay.hpp"

namespace Screens {
    class ScoreScreen : public Screen {
        private:
            std::unique_ptr<Components::Image> backgroundImage = nullptr;
            std::unique_ptr<Components::Text> title = nullptr;

            std::unique_ptr<Views::MatchResultDisplay> matchsResultDisplay = nullptr;

            std::unique_ptr<Components::ButtonIcon> buttonNext = nullptr;
            std::unique_ptr<Components::ButtonIcon> buttonPrevius = nullptr;
            std::unique_ptr<Components::ButtonText> buttonVoltar = nullptr;

            std::unique_ptr<Components::Text> emptyScoreRegisterText = nullptr;
            
            std::vector<MatchResults> matchsResults;
            Rectangle background;

            unsigned int actualMatchIndex = 0;

        public:
            /**
             * @brief Create the Score Screen window.
             */
            ScoreScreen();

            /**
             * @brief Destroy the Score Screen.
             */
            virtual ~ScoreScreen();
        
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
             * @brief Try to load any match results from the score save file.
             */
            void loadMatchResults();

            /**
             * @brief Handle the button next click event.
             */
            void handleButtonNextClick();

            /**
             * @brief Handle the button previus click event.
             */
            void handleButtonPreviusClick();

            /**
             * @brief Build background style.
             */
            void buildBackground();

            /**
             * @brief Render background.
             */
            void renderBackground();

            /**
             * @brief Build title.
             */
            void buildTitle();

            /**
             * @brief Build match results view.
             */
            void buildMatchsResultsDisplays();

            /**
             * @brief Build next and previus button.
             */
            void buildButtonsNextPrevius();

            /**
             * @brief Build back button.
             */
            void buildButtonVoltar();

            /**
             * @brief Build empty score text.
             */
            void buildEmptyScoreRegistrText();
    };   
}

#endif
