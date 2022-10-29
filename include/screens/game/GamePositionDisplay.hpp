#ifndef GAME_POSITION_DISPLAY_HPP
#define GAME_POSITION_DISPLAY_HPP

#include <memory>

#include "Image.hpp"

#include "PositionDisplay.hpp"

namespace Views {
    class GamePositionDisplay : public PositionDisplay {
        private:
            std::unique_ptr<Components::Image> hitImage = nullptr;
            
            bool revealTroop = false;
            bool wasClicked = false;

        public:
            /**
             * @brief Create the Game Position that builds a board of a player with a new logic position.
             * @param boardCoordinates is the coordinates that the position is placed.
             */
            GamePositionDisplay(const Point boardCoordinates);

            /**
             * @brief Create the Game Position that builds a board of a player based on a logic position.
             * @param position is the logic position that will base the display.
             */
            GamePositionDisplay(std::shared_ptr<Position> position);

            /**
             * @brief Destroy the Game Position view.
             */
            virtual ~GamePositionDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Check if the game position was clicked.
             * 
             * @return Boolean that indicates if the game position was clicked.
             */
            virtual bool checkClick() override;

            /**
             * @brief Sets if the position should show the troop.
             * 
             * @param option is the flag to show or not the troop.
             */
            void setRevealTroop(const bool option);

            /**
             * @brief Check if should display the troop position in the game board.
             * 
             * @return Reveal troop attribute value.
             */
            bool shouldRevealTroop() const;
        
        protected:
            /**
             * @brief Update all inner components positions.
             */
            virtual void updateInnerComponentsPositions() override;
        
        private:
            /**
             * @brief Define how the position will be rendered if it have a troop.
             */
            void handleTroopRender();

            /**
             * @brief Define how the position will be rendered if it dosen't have a troop.
             */
            void handleDefaultRender();

            /**
             * @brief Build view component styles.
             */
            void buildComponent();

            /**
             * @brief Build hit image styles.
             */
            void buildHitImage();

            /**
             * @brief Position hit image component.
             */
            void positionHitImage();
    };
}

#endif
