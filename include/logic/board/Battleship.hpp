#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <string>

#include "Troop.hpp"
#include "Point.hpp"

class Battleship : public Troop {
    public:
        /**
         * Battleship standard troop health.
         * 
         */
        static const unsigned int INITIAL_HEALTH;

        /**
         * @brief Get the standard battleship name.
         * 
         * @return A string with the standard battleship name.
         */
        static std::string getTroopName();
        
        /**
         * Construct a new battleship with default health values.
         * @brief Default constructor.
         * 
         */
        Battleship();

        /**
         * @brief Destroy the Battleship object.
         * 
         */
        virtual ~Battleship();

        /**
         * @brief Get the initial health attribute.
         * 
         * @return Initial health attribute value.
         */
        virtual unsigned int getInitialHealth() const override;

    protected:
        /**
         * @brief Positions the battleship horizontally.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionHorizontally(const Point initialPosition) override;
        
        /**
         * @brief Positions the battleship vertically.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionVertically(const Point initialPosition) override;
};

#endif
