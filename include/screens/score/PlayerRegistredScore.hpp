#ifndef PLAYER_REGISTRED_SCORE_HPP
#define PLAYER_REGISTRED_SCORE_HPP

#include <string>
#include <vector>
#include <memory>

#include "raylib.h"

#include "View.hpp"
#include "Text.hpp"

#include "Score.hpp"

namespace Views {
    class PlayerRegistredScore : public View {
        private:
            std::unique_ptr<Components::Text> playerNameLabel = nullptr;
            std::vector<std::unique_ptr<Components::Text>> scoreLabels;

            std::string playerName = "";
            Score playerScore;

        public:
            /**
             * @brief Create the section that displays the score of a player in a match.
             */
            PlayerRegistredScore();

            /**
             * @brief Destroy the Player Registred Score view.
             */
            virtual ~PlayerRegistredScore();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Update the view values based on the playerName and playerScore.
             * 
             * @param playerName is the name of the player that will be displayed on the view.
             * @param playerScore is the score of the player that will be displayed on the view.
             */
            void update(const std::string playerName, const Score playerScore);

            /**
             * @brief Get the player name attribute.
             * 
             * @return Player name attribute value.
             */
            std::string getPlayerName() const;

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
             * @brief Position player name.
             */
            void positionPlayerNameLabel();

            /**
             * @brief Define the player name text size.
             */
            void definePlayerNameTextSize();
            
            /**
             * @brief Position player score.
             */
            void positionPlayerScoreLabels();

            /**
             * @brief Define the score text size.
             */
            void defineScoreLabelsTextSize();

            /**
             * @brief Get score margin left value.
             * 
             * @return Score margin left value.
             */
            float getLabelMarginLeft() const;

            /**
             * @brief Set the playerName attribute that will be displayed.
             * 
             * @param matchResult is the new value to the attribute.
             */
            void setPlayerName(const std::string playerName);

            /**
             * @brief Set the playerScore attribute that will be displayed.
             * 
             * @param playerScore is the new value to the attribute.
             */
            void setPlayerScore(const Score playerScore);
    };   
}

#endif
