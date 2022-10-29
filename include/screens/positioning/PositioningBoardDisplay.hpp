#ifndef POSITIONING_BOARD_DISPLAY_HPP
#define POSITIONING_BOARD_DISPLAY_HPP

#include <memory>
#include <vector>
#include "raylib.h"

#include "BoardDisplay.hpp"
#include "PositioningPositionDisplay.hpp"

#include "Board.hpp"
#include "Point.hpp"
#include "Troop.hpp"

namespace Views {
    class PositioningBoardDisplay : public BoardDisplay {
        public:
            /**
             * @brief Create the Positioning Board of a player with a new logic board.
             * @param amountHorizontalCells is the amount of horizontal cells that the board has.
             * @param amountVerticalCells is the amount of vertical cells that the board has.
             */
            PositioningBoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells);

            /**
             * @brief Create the Positioning Board of a player based on a existing logic board.
             * @param logicBoard is logic part of the board.
             */
            PositioningBoardDisplay(std::shared_ptr<Board> logicBoard);

            /**
             * @brief Destroy the Positioning Board view.
             */
            virtual ~PositioningBoardDisplay();
        
            /**
             * @brief Position a troop in some board positions based on it's shape.
             * 
             * @param troop is a pointer to the troop that will be positioned.
             */
            void positionTroop(const std::shared_ptr<Troop> troop);

            /**
             * @brief Remove the troop from this position.
             * 
             * @param troop is a pointer to the troop that will be removed from the board.
             */
            void removeTroop(const std::shared_ptr<Troop> troop);

            /**
             * @brief Set a group of position as marked.
             * 
             * @param points is the coordinates of the positions that will be marked.
             */
            void markPositions(const std::vector<Point>& points);

            /**
             * @brief Unmark a group of positions.
             * 
             * @param points is the coordinates of the positions that will be unmarked.
             */
            void unmarkPositions(const std::vector<Point>& points);

            /**
             * @brief Unmark a specific position.
             * 
             * @param point is the coordinate of the position that will be unmarked.
             */
            void unmarkPosition(const Point point);

            /**
             * @brief Get the board cells as positioning cells objects.
             * 
             * @return Matrix of the board cells as positioning cells.
             */
            std::vector<std::vector<std::shared_ptr<PositioningPositionDisplay>>> getCellsAsPositioningCells() const;
        
        protected:
            /**
             * @brief Instantiate the board cells components.
             */
            virtual void initializeCells() override;

        private:
            /**
             * @brief Build view component styles.
             */
            void buildComponent();
    };
}

#endif
