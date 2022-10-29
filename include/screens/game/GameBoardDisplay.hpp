#ifndef GAME_BOARD_DISPLAY_HPP
#define GAME_BOARD_DISPLAY_HPP

#include <memory>
#include <vector>

#include "BoardDisplay.hpp"
#include "GamePositionDisplay.hpp"

#include "Board.hpp"

namespace Views {
    class GameBoardDisplay : public BoardDisplay {
        public:
            /**
             * @brief Create the Game Board of a player with a new logic board.
             * @param amountHorizontalCells is the amount of horizontal cells that the board has.
             * @param amountVerticalCells is the amount of vertical cells that the board has.
             */
            GameBoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells);

            /**
             * @brief Create the Game Board of a player based on a existing logic board.
             * @param logicBoard is logic part of the board.
             */
            GameBoardDisplay(std::shared_ptr<Board> logicBoard);

            /**
             * @brief Destroy the Game Board view.
             */
            virtual ~GameBoardDisplay();

            /**
             * @brief Enable all click detection on the board.
             */
            void enable();

            /**
             * @brief Disable all click detection on the board.
             */
            void disable();

            /**
             * @brief Set all positions to show their troops if they have one.
             */
            void revealTroops();

            /**
             * @brief Set all positions to hide their troops it they have one.
             */
            void hideTroops();

            /**
             * @brief Get the board cells as game cells objects.
             * 
             * @return Matrix of the board cells as game cells.
             */
            std::vector<std::vector<std::shared_ptr<Views::GamePositionDisplay>>> getCellsAsGameCells() const;
        
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
