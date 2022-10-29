#ifndef POSITIONING_SCREEN_HPP
#define POSITIONING_SCREEN_HPP

#include <string>
#include <memory>
#include "raylib.h"

#include "Screen.hpp"
#include "Text.hpp"

#include "WarningPopUp.hpp"
#include "PositioningBoardDisplay.hpp"
#include "TroopPositioningOption.hpp"

#include "Orientation.hpp"
#include "Player.hpp"

namespace Screens {
    class PositioningScreen : public Screen {
        private:
            static const std::string POPUP_MESSAGE;

            std::unique_ptr<Components::Text> playerName = nullptr;

            std::unique_ptr<Views::PositioningBoardDisplay> board = nullptr;
            std::unique_ptr<Views::TroopPositioningOption> availableTroops = nullptr;
            
            std::unique_ptr<Views::WarningPopUp> popup = nullptr;

            Rectangle background;
            Rectangle foreground;

            std::shared_ptr<Troop> troopToBePositioned = nullptr;
            Orientation troopBuildDirection = HORIZONTAL;
            bool shouldDisplayPopUp = false;

        public:
            /**
             * @brief Create the Positioning Screen window.
             * @param playerPositioningTurn is the player that will start thier positioning turn.
             */
            PositioningScreen(std::shared_ptr<Player> playerPositioningTurn);

            /**
             * @brief Destroy the Positioning Screen.
             */
            virtual ~PositioningScreen();
        
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
             * @brief Check for the event of closing the warning pop up.
             */
            void verifyPopupShouldClose();

            /**
             * @brief Check for the event of the button rotate being clicked.
             */
            void verifyButtonRotateClick();

            /**
             * @brief Check for the event of a troop being selected.
             */
            void verifyTroopSelection();

            /**
             * @brief Check for the event of a troop being positioned.
             */
            void verifyTroopPositioning();

            /**
             * @brief Check for the event of a troop being removed.
             */
            void verifyTroopRemoved();

            /**
             * @brief Check for the event of the end of positioning turn button being clicked.
             */
            void verifyEndPositioningTurnCilck();

            /**
             * @brief Clear any unecessary marked position.
             */
            void clearBoard();

            /**
             * @brief Handle exception of a troop being incorrectly positioned.
             */
            void handleInvalidPositionException();

            /**
             * @brief Build background style.
             */
            void buildBackground();

            /**
             * @brief Render background.
             */
            void renderBackground();

            /**
             * @brief Build positioning board style.
             */
            void buildBoard();

            /**
             * @brief Build player name style.
             */
            void buildPlayerName();

            /**
             * @brief Build available selectable troops style.
             */
            void buildAvailableTroops();
    };
}

#endif
