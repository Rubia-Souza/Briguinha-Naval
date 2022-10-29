#ifndef GAME_SCORE_DISPLAY_HPP
#define GAME_SCORE_DISPLAY_HPP

#include <string>
#include <vector>
#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "TextIcon.hpp"

#include "Score.hpp"

namespace Views {
    class GameScoreDisplay : public View {
        private:
            std::vector<std::shared_ptr<Components::TextIcon>> labels;
            std::shared_ptr<Score> playerScore = nullptr;

        public:
            /**
             * @brief Create the Game Score of a player based on a logic score.
             * @param score is the logic score that will base the display.
             */
            GameScoreDisplay(const std::shared_ptr<Score> score);

            /**
             * @brief Destroy the Game Score view.
             */
            virtual ~GameScoreDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Update score labels values.
             */
            void updateLabels();

            /**
             * @brief Get the player score attribute.
             * 
             * @return Player score attribute copy.
             */
            Score getPlayerScore() const;

        protected:
            /**
             * @brief Update all inner components positions.
             */
            virtual void updateInnerComponentsPositions() override;

            /**
             * @brief Define the width of the view.
             */
            virtual void findWidth() override;

            /**
             * @brief Define the height of the view.
             */
            virtual void findHeight() override;

        private:
            /**
             * @brief Set the score labels text and icon sizes.
             */
            void defineLabelsSizes();

            /**
             * @brief Position all score labels.
             */
            void poisitionLabels();

            /**
             * @brief Set the playerScore attribute.
             * 
             * @param score is the new value to the attribute.
             */
            void setPlayerScore(const std::shared_ptr<Score> score);
    };
}

#endif
