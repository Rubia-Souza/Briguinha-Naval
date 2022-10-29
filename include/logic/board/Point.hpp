#ifndef POINT_HPP
#define POINT_HPP

/**
 * @brief Point class used for positioning and board manipulations.
 */
class Point {
    protected:
        /**
         * Representations of x and y positions on a plane/matrix.
         */
        int x = 0;
        int y = 0;
    
    public:
        /**
         * Create a new point given x and y values.
         * @brief Construct a new Point object.
         * 
         * @param x The x position in a plane/matrix.
         * @param y The y position in a plane/matrix.
         */
        Point(const int x, const int y);

        /**
         * Construct a new point given another point object.
         * @brief Copy constructor.
         * 
         * @param point The point which will be copied.
         */
        Point(const Point& point);

        /**
         * @brief Destroy the Point object.
         */
        virtual ~Point();
        
        /**
         * @brief Set value of x.
         * 
         * @param x New value of x.
         */
        void setX(const int x);

        /**
         * @brief Get the value of x.
         * 
         * @return A copy of the value of x.
         */
        int getX() const;

        /**
         * @brief Set the value of y.
         * 
         * @param y New value of y.
         */
        void setY(const int y);

        /**
         * @brief Get the value of y.
         * 
         * @return A copy of the value of y.
         */
        int getY() const;

        /**
         * @brief Equals comparator overloader.
         * 
         * @param other The other point object instance that will be compared.
         * @return Whether x and y on both instances are equal, respectively.
         */
        bool operator==(const Point& other) const;

        /**
         * @brief "<" operator overloader
         * 
         * @param other The other point instance that will be compared.
         * @return true If x is smaller than the other instance. If equal, if y is smaller than the other instance.
         * @return false If x is greater than the other instance. If equal, if y is greater than the other instance.
         */
        bool operator<(const Point& other) const;

        /**
         * @brief "+" operator overloader
         * 
         * @param other The other point object instance that will be added.
         * @return A point instance with x and y values being the sum of both instances x and y values, respectively.
         */
        Point operator+(const Point &other) const;
};

#endif