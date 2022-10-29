#ifndef END_GAME_SCREEN_HPP
#define END_GAME_SCREEN_HPP

#include <memory>
#include <string>
#include <vector>
#include "raylib.h"

#include "Screen.hpp"
#include "ButtonText.hpp"
#include "Text.hpp"
#include "Image.hpp"

#include "Player.hpp"
#include "Colors.hpp"

#include "EndGameScoreDisplay.hpp"

namespace Screens {
    class EndGameScreen : public Screen {
        private:
            std::unique_ptr<Components::Image> backgroundImage = nullptr;

            std::unique_ptr<Components::Text> player1Name = nullptr;
            std::unique_ptr<Components::Text> player1Status = nullptr;
            std::unique_ptr<Views::EndGameScoreDisplay> player1ScoreDisplay = nullptr;

            std::unique_ptr<Components::Text> player2Name = nullptr;
            std::unique_ptr<Components::Text> player2Status = nullptr;
            std::unique_ptr<Views::EndGameScoreDisplay> player2ScoreDisplay = nullptr;

            std::unique_ptr<Components::ButtonText> buttonVoltar = nullptr;

            Rectangle backgroundMask;
            Color backgroundMaskColor = DEFAULT_BALCK;
            
            Rectangle mainContentBackground;
            Color mainContentBackgroundColor = DEFAULT_BALCK;

            Rectangle divisionLine;
            
            Player player1;
            Player player2;

        public:
            /**
             * @brief Create End Game Screen.
             * @param player1 is the player 1 data.
             * @param player2 is the player 2 data.
             */
            EndGameScreen(const Player& player1, const Player& player2);

            /**
             * @brief Destroy the End Game Screen.
             */
            virtual ~EndGameScreen();

            /**
             * @brief Get the player 1 data.
             * 
             * @return Player 1 data copy.
             */
            Player getPlayer1() const;

            /**
             * @brief Get the player 2 data.
             * 
             * @return Player 2 data copy.
             */
            Player getPlayer2() const;
        
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
             * @brief Render the division line.
             */
            void renderDivisionLine();

            /**
             * @brief Render the screen background.
             */
            void renderBackground();

            /**
             * @brief Build background styles.
             */
            void buildBackgroundImage();

            /**
             * @brief Build player 1 title styles.
             */
            void buildPlayer1SectionTitle();

            /**
             * @brief Render the player 1 title.
             */
            void renderPlayer1SectionTitle();

            /**
             * @brief Build player 1 score styles.
             */
            void buildPlayer1ScoreDisplay();

            /**
             * @brief Build division line.
             */
            void buildDivisionLine();

            /**
             * @brief Build player 2 title styles.
             */
            void buildPlayer2SectionTitle();

            /**
             * @brief Render the player 2 title.
             */
            void renderPlayer2SectionTitle();

            /**
             * @brief Build player 2 score styles.
             */
            void buildPlayer2ScoreDisplay();

            /**
             * @brief Build back button styles.
             */
            void buildButtonVoltar();

            /**
             * @brief Set the player1Score attribute.
             * 
             * @param player1Score is the new value to the attribute.
             */
            void setPlayer1(const Player& player1Score);

            /**
             * @brief Set the player2Score attribute.
             * 
             * @param player2Score is the new value to the attribute.
             */
            void setPlayer2(const Player& player2Score);

            /**
             * @brief Get player name margin top style value.
             * 
             * @return Player name margin top style value.
             */
            float getPlayerNameMarginTop() const;

            /**
             * @brief Get player status font size style value.
             * 
             * @return Player status font size style value.
             */
            float getPlayerStatusFontSize() const;

            /**
             * @brief Get player status margin top style value.
             * 
             * @return Player status margin top style value.
             */
            float getPlayerStatusMarginTop() const;

            /**
             * @brief Get player score margin top style value.
             * 
             * @return Player score margin top style value.
             */
            float getPlayerScoreMarginTop() const;

            /**
             * @brief Identify if the player has won the game or not to select wich status display under the name.
             * 
             * @param playerScore is the player score that will be reference to check if the player has won.
             * 
             * @return "Vitoria!" if the player has won the game otherwise return "Derrota".
             */
            std::string getStatusText(const Score playerScore) const;

            /**
             * @brief Identify if the player has won the game or not to select the color of the status display under the name.
             * 
             * @param playerScore is the player score that will be reference to check if the player has won.
             * 
             * @return Golen color if the player has won the game, otherwise return red color.
             */
            Color getStatusColor(const Score playerScore) const;
    };
}

#endif
