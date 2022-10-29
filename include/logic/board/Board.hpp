#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <memory>

#include "Position.hpp"
#include "Troop.hpp"

class Board { 
    private:
        /**
         * Height and width of the board, Matrix of Position pointers representing the board, along with vector of troop pointers.
         */
        int height = 0;
        int width = 0;

        std::vector<std::vector<std::shared_ptr<Position>>> board;
        std::vector<std::shared_ptr<Troop>> troops;

    public:
        /**
         * Construct board with default height and width.
         * @brief Default constructor. 
         * 
         */
        Board();
        
        /**
         * @brief Constructor with specific width and heigth.
         * 
         * @param width The board width.
         * @param height The board heigth.
         */
        Board(const int width, const int height);

        /**
         * @brief Destroy the Board object.
         * 
         */
        virtual ~Board();

        /**
         * @brief Tries to position a troop with a valid positioning and initial point.
         * 
         * @param troop The troop which will be positioned.
         */
        void positionTroop(const std::shared_ptr<Troop> troop);

        /**
         * @brief Removes a troop from all positions in the board.
         * 
         * @param troop A pointer to the troop to be removed.
         */
        void removeTroop(const std::shared_ptr<Troop> troop);
    
        /**
         * @brief Checks if the position the troops intends to occupy is valid.
         * 
         * @param positionCoordinates A vector of points which represents the point which the troop will occupy.
         * @return Whether the positioning is valid.
         */
        bool isPositionValid(const std::vector<Point>& positionCoordinates) const;

        /**
         * @brief Check if a point in the board contains a troop.
         * 
         * @param coodinate The point containing coordinates which will be checked for a troop.
         * @return Whether the point has a troop or not.
         */
        bool doesPositionContainsTroop(const Point coodinate) const;

        /**
         * @brief Check if a point is within the board's boundaries.
         * 
         * @param point The point containing coordinates which will be checked.
         * @return Whether the coordinates in the point are within the board's boundaries.
         */
        bool isPointWithinBoundaries(const Point point) const;

        /**
         * @brief Get the heigth of the board.
         * 
         * @return The value of the board's height.
         */
        int getHeight() const;

        /**
         * @brief Get the width of the board.
         * 
         * @return The value of the board's width.
         */
        int getWidth() const;

        /**
         * @brief Get the troops in the board.
         * 
         * @return All troops positioned in the board.
         */
        std::vector<std::shared_ptr<Troop>> getTroops() const;

        /**
         * @brief Get the reference to a position in the board.
         * 
         * @param x The x value of the position.
         * @param y The y value of the position
         * @return A pointer to the original value of the position object in x and y coordinates.
         */
        std::shared_ptr<Position> getPosition(const int x, const int y) const;

    private:
        /**
         * @brief Initialize the board with positions.
         * 
         */
        void initializeBoardPositions();

        /**
         * @brief Sets the heigth of the board.
         * 
         * @param height The new height of the board.
         */
        void setHeight(const int height);
        
        /**
         * @brief Sets the width of the board.
         * 
         * @param height The new width of the board.
         */
        void setWidth(const int width);
};

#endif