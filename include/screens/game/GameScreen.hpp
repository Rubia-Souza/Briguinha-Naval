#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <memory>

#include "Screen.hpp"

#include "Text.hpp"
#include "ButtonTextIcon.hpp"

#include "PositionDisplay.hpp"

#include "GameBoardDisplay.hpp"
#include "GameScoreDisplay.hpp"

#include "Match.hpp"

namespace Screens {
    class GameScreen : public Screen {
        private:
            std::unique_ptr<Components::Text> player1Name = nullptr;
            std::unique_ptr<Views::GameBoardDisplay> player1Board = nullptr;
            std::unique_ptr<Components::ButtonTextIcon> player1RevealTroopsButton = nullptr;
            std::unique_ptr<Views::GameScoreDisplay> player1ScoreDisplay = nullptr;

            std::unique_ptr<Components::Text> player2Name = nullptr;
            std::unique_ptr<Views::GameBoardDisplay> player2Board = nullptr;
            std::unique_ptr<Components::ButtonTextIcon> player2RevealTroopsButton = nullptr;
            std::unique_ptr<Views::GameScoreDisplay> player2ScoreDisplay = nullptr;
            
            std::shared_ptr<Match> match = nullptr;

            Rectangle divisionLine;
            Rectangle background;
            Rectangle foreground;

            bool isTroopsRevealed = false;

        public:
            /**
             * @brief Create Game Screen.
             * @param match is the actual game match data.
             */
            GameScreen(std::shared_ptr<Match> match);

            /**
             * @brief Destroy the Game Screen.
             */
            virtual ~GameScreen();

            /**
             * @brief Get the actual match attribute.
             * 
             * @return Actual match attribute copy.
             */
            Match getActualMatch() const;
        
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
             * @brief Checks for any click in the passed board.
             * 
             * @param board is the board that will have any click event attached to it.
             */
            void verifyPlayerBoardClick(const std::unique_ptr<Views::GameBoardDisplay>& board);

            /**
             * @brief Checks for any click in the passed button.
             * 
             * @param playerRevealTroopsButton is the button that will have any click event attached to it.
             */
            void verifyPlayerRevealTroopsClick(const std::unique_ptr<Components::ButtonTextIcon>& playerRevealTroopsButton, const std::unique_ptr<Views::GameBoardDisplay>& board);

            /**
             * @brief Checks if the target position had a troop on it.
             * 
             * @param target is the position that was clicked.
             */
            void checkTroopHit(Views::PositionDisplay& target);

            /**
             * @brief Increment the amount of total shots a player has done.
             */
            void incrementPlayerShots();

            /**
             * @brief Setup the interface for the next player turn.
             */
            void passTurn();

            /**
             * @brief Setup the interface for the player 1 turn.
             */
            void startPlayer1Turn();

            /**
             * @brief Setup the interface for the player 2 turn.
             */
            void startPlayer2Turn();

            /**
             * @brief Build background styles.
             */
            void buildBackground();

            /**
             * @brief Render the background.
             */
            void renderBackground();

            /**
             * @brief Build player 1 name styles.
             */
            void buildPlayer1Name();

            /**
             * @brief Build player 1 board styles.
             */
            void buildPlayer1Board();

            /**
             * @brief Build player 1 reveal troops button styles.
             */
            void buildPlayer1RevealTroopsButton();

            /**
             * @brief Build player 1 score styles.
             */
            void buildPlayer1ScoreDisplay();

            /**
             * @brief Build division line.
             */
            void buildDivisionLine();

            /**
             * @brief Render the division line.
             */
            void renderDivisionLine();
        
            /**
             * @brief Build player 2 name styles.
             */
            void buildPlayer2Name();

            /**
             * @brief Build player 2 board styles.
             */
            void buildPlayer2Board();

            /**
             * @brief Build player 1 reveal troops button styles.
             */
            void buildPlayer2RevealTroopsButton();

            /**
             * @brief Build player 2 score styles.
             */
            void buildPlayer2ScoreDisplay();

            /**
             * @brief Get player name margin top style value.
             * 
             * @return Player name margin top style value.
             */
            float getPlayerNameMarginTop() const;

            /**
             * @brief Get board margin top style value.
             * 
             * @return Board margin top style value.
             */
            float getBoardMarginTop() const;

            /**
             * @brief Get reveal button icon height style value.
             * 
             * @return Reveal button icon height style value.
             */
            float getRevealButtonIconHeight() const;

            /**
             * @brief Get reveal button icon width style value.
             * 
             * @return Reveal button icon width style value.
             */
            float getRevealButtonIconWidth() const;

            /**
             * @brief Get reveal button font size style value.
             * 
             * @return Reveal button font size style value.
             */
            float getRevealButtonFontSize() const;

            /**
             * @brief Get reveal button width style value.
             * 
             * @return Reveal button width style value.
             */
            float getRevealButtonWidth() const;

            /**
             * @brief Get reveal button height style value.
             * 
             * @return Reveal button height style value.
             */
            float getRevealButtonHeight() const;

            /**
             * @brief Get reveal button y offset style value.
             * 
             * @return Reveal button y offset style value.
             */
            float getRevealButtonYOffset() const;

            /**
             * @brief Get score display margin top style value.
             * 
             * @return Reveal score display margin top style value.
             */
            float getPlayerScoreDisplayMarginTop() const;

            /**
             * @brief Concat playerName with a * that will be indicate actual player turn.
             * 
             * @param playerName is the player that has the actual turn.
             * 
             * @return playerName concatenated name with *.
             */
            std::string buildPlayerTurnMark(const std::string playerName) const;

            /**
             * @brief Set the match attribute.
             * 
             * @param match is the new value to the attribute.
             */
            void setActualMatch(const std::shared_ptr<Match> match);
    };
}

#endif
