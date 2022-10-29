#ifndef POSITION_HPP
#define POSITION_HPP

#include <memory>

#include "Point.hpp"
#include "Troop.hpp"

class Position : public Point {
    private:
        std::shared_ptr<Troop> troop = nullptr;

    public:
        /**
         * @brief Construct a new Position object.
         * 
         * @param x x position in a plane or matrix.
         * @param y y position in a plane or matrix.
         */
        Position(const int x, const int y);
        
        /**
         * @brief Position destructor
         */
        virtual ~Position();

        /**
         * @brief Set the troop attribute.
         * 
         * @param troop A shared pointer to the troop attribute.
         */
        void setTroop(std::shared_ptr<Troop> troop);
        
        /**
         * @brief Get the troop attribute.
         * 
         * @return A shared pointer to the troop attribute.
         */
        std::shared_ptr<Troop> getTroop() const;
        
        /**
         * @brief Verify if the position has a troop on it.
         * 
         * @return an boolean that says the position contains an troop;
         */
        bool hasTroop() const;
};

#endif