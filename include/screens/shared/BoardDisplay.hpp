#ifndef BOARD_DISPLAY_HPP
#define BOARD_DISPLAY_HPP

#include <memory>
#include <vector>
#include "raylib.h"

#include "View.hpp"
#include "Image.hpp"
#include "PositionDisplay.hpp"

#include "Board.hpp"

namespace Views {
    class BoardDisplay : public View {
        protected:
            std::unique_ptr<Components::Image> background = nullptr;
            std::vector<std::vector<std::shared_ptr<PositionDisplay>>> cells;

            unsigned int amountHorizontalCells = 0;
            unsigned int amountVerticalCells = 0;

            std::shared_ptr<Board> logicBoard = nullptr;

        public:
            /**
             * @brief Create the basic template for the troop display with a new logic position.
             * @param amountHorizontalCells is the amount of horizontal cells that the board has.
             * @param amountVerticalCells is the amount of vertical cells that the board has.
             */
            BoardDisplay(const unsigned int amountHorizontalCells, const unsigned int amountVerticalCells);

            /**
             * @brief Create the basic template for the troop display with a new logic position.
             * @param logicBoard is logic part of the board.
             */
            BoardDisplay(std::shared_ptr<Board> logicBoard);

            /**
             * @brief Destroy the Board Display view.
             */
            virtual ~BoardDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;
            
            /**
             * @brief Get the amount of horizontal cells the board has.
             * 
             * @return The amount of horizontal cells the board has.
             */
            unsigned int getAmountHorizontalCells() const;

            /**
             * @brief Get the amount of vertical cells the board has.
             * 
             * @return The amount of vertical cells the board has.
             */
            unsigned int getAmountVerticalCells() const;

            /**
             * @brief Get the board cells objects.
             * 
             * @return Matrix of the board cells.
             */
            std::vector<std::vector<std::shared_ptr<PositionDisplay>>> getCells() const;
        
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

            /**
             * @brief Instantiate the board cells components.
             */
            virtual void initializeCells() = 0;

            /**
             * @brief Build background style.
             */
            void buildBackground();
        
        private:
            /**
             * @brief Position background.
             */
            void positionBackground();

            /**
             * @brief Position board cells.
             */
            void positionCells();

            /**
             * @brief Get board padding value.
             * 
             * @return Board padding value.
             */
            float getBoardPadding() const;

            /**
             * @brief Get spacing between cells value.
             * 
             * @return Spacing between cells value.
             */
            float getCellsSpacing() const;

            /**
             * @brief Get height of the board without background value.
             * 
             * @return Height of the board without background value.
             */
            float getCellsMatrixHeight() const;

            /**
             * @brief Get width of the board without background value.
             * 
             * @return Width of the board without background value.
             */
            float getCellsMatrixWidth() const;

            /**
             * @brief Set the amount of horizontal cells that the board has.
             * 
             * @param amountHorizontalCells is the new amount of horizontal cells of the board.
             */
            void setAmountHorizontalCells(const unsigned int amountHorizontalCells);

            /**
             * @brief Set the amount of vertical cells that the board has.
             * 
             * @param amountVerticalCells is the new amount of vertical cells of the board.
             */
            void setAmountVerticalCells(const unsigned int amountVerticalCells);
    };
}

#endif
