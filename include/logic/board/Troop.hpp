#ifndef TROOP_HPP
#define TROOP_HPP

#include <map>
#include <string>
#include <vector>

#include "Score.hpp"
#include "Point.hpp"
#include "Orientation.hpp"

class Troop {
    protected:
        /**
         * Total ship health, ship shape and corresponding ship images.
         * 
         */
        unsigned int health = 0;
        std::vector<Point> shape;
        std::map<Point, std::string> images;
    
    public:
        /**
         * @brief Get the standard troop name.
         * 
         * @return A string with the standard troop name.
         */
        static std::string getTroopName();
        
        /**
         * Create a new troop given its total health.
         * @brief Construct a new Troop object.
         * 
         * @param health The total health of the ship.
         */
        Troop(const unsigned int health);
        
        /**
         * @brief Destroy the Troop object.
         * 
         */
        virtual ~Troop();

        /**
         * @brief Make the troop take damage, decreasing its health.
         * 
         */
        void takeDamage();
        
        /**
         * @brief Determines if the troop is dead.
         * 
         * @return Whether the troop is dead or not.
         */
        bool isDead() const;

        /**
         * @brief Sets the positioning of the troop
         * 
         * @param initialPosition The initial point position of the desired positioning.
         * @param orientation The orientation of the desired positioning.
         */
        void setPosition(const Point initialPosition, const Orientation orientation);

        /**
         * @brief Get the ocuppied positions points, in order.
         * 
         * @return A vector with the desired occupied positions.
         */
        std::vector<Point> getOccupiedPositions() const;

        /**
         * @brief Get the health attribute.
         * 
         * @return Health attribute value.
         */
        unsigned int getHealth() const;

        /**
         * @brief Get the initial health attribute.
         * 
         * @return Initial health attribute value.
         */
        virtual unsigned int getInitialHealth() const = 0;

        /**
         * @brief Get the images attribute.
         * 
         * @return The images attribute, associates a point with an image path.
         */
        std::map<Point, std::string> getImages() const;

        /**
         * @brief Get the image associated in a certain point.
         * 
         * @param point is the point to get the image associated to it.
         * 
         * @return The path of the image in the passed point if it has one associated to it or a empty string otherwise.
         */
        std::string getImageInPoint(const Point point) const;

        /**
         * @brief Verify if the point is within the troop shape.
         * @param point an point object to be check if is in the troop shape
         * 
         * @return a bool that says if the troop has the passed point.
         */
        bool containsPoint(const Point point) const;

    protected:
        /**
         * @brief Abstract function with the desire to position the troop horizontally.
         * 
         * @param initialPosition The initial point to be start the positioning.
         */
        virtual void positionHorizontally(const Point initialPosition);
        
        /**
         * @brief Abstract function with the desire to position the troop vertically.
         * 
         * @param initialPosition The initial point to be start the positioning.
         */
        virtual void positionVertically(const Point initialPosition);

        /**
         * @brief Associate points where the troop was positioned to it's images paths.
         */
        virtual void buildImagesMap(const std::string folderPathWithSpriteName);
};

#endif