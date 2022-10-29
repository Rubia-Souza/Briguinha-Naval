#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include <string>

#include "Troop.hpp"
#include "Point.hpp"

class Submarine : public Troop {    
    public:
        /**
         * Submarine standard troop health.
         * 
         */
        static const unsigned int INITIAL_HEALTH;

        /**
         * @brief Get the standard submarine name.
         * 
         * @return A string with the standard submarine name.
         */
        static std::string getTroopName();

        /**
         * Construct a new submarine with default health values.
         * @brief Default constructor.
         * 
         */
        Submarine();

        /**
         * @brief Destroy the Submarine object.
         * 
         */
        virtual ~Submarine();

        /**
         * @brief Get the initial health attribute.
         * 
         * @return Initial health attribute value.
         */
        virtual unsigned int getInitialHealth() const override;
    
    protected:
        /**
         * @brief Positions the submarine horizontally.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionHorizontally(const Point initialPosition) override;
        
        /**
         * @brief Positions the submarine vertically.
         * 
         * @param initialPosition The point which corresponds to the initial position of the positioning.
         */
        virtual void positionVertically(const Point initialPosition) override;

        /**
         * @brief Associate points where the troop was positioned to it's images paths.
         */
        virtual void buildImagesMap(const std::string troopName) override;
};

#endif