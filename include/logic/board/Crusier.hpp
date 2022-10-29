#ifndef CRUSIER_HPP
#define CRUSIER_HPP

#include <string>

#include "Troop.hpp"
#include "Point.hpp"

class Crusier : public Troop {    
    public:
        /**
         * Crusier standard troop health.
         * 
         */
        static const unsigned int INITIAL_HEALTH;

        /**
         * @brief Get the standard crusier name.
         * 
         * @return A string with the standard crusier name.
         */
        static std::string getTroopName();

        /**
         * Construct a new crusier with default health values.
         * @brief Default constructor.
         * 
         */
        Crusier();

        /**
         * @brief Destroy the Crusier object.
         * 
         */
        virtual ~Crusier();

        /**
         * @brief Get the initial health attribute.
         * 
         * @return Initial health attribute value.
         */
        virtual unsigned int getInitialHealth() const override;

    protected:
        /**
         * @brief Positions the crusier horizontally.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionHorizontally(const Point initialPosition) override;
        
        /**
         * @brief Positions the crusier vertically.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionVertically(const Point initialPosition) override;
};

#endif
