#ifndef END_GAME_SCORE_DISPLAY_HPP
#define END_GAME_SCORE_DISPLAY_HPP

#include <string>
#include <vector>
#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "TextIcon.hpp"

#include "Score.hpp"

namespace Views {
    class EndGameScoreDisplay : public View {
        private:
            std::vector<std::shared_ptr<Components::TextIcon>> labels;
            Score playerScore;

        public:
            /**
             * @brief Create the End Game Score based on a player score.
             */
            EndGameScoreDisplay(const Score score);

            /**
             * @brief Destroy the EndGameScoreDisplay view.
             */
            virtual ~EndGameScoreDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

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
            void setPlayerScore(const Score score);
    };
}

#endif
