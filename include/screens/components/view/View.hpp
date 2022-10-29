#ifndef VIEW_HPP
#define VIEW_HPP

#include "raylib.h"

#include "Component.hpp"

namespace Views {
    class View : public Components::Component {
        public:
            /**
             * @brief Destroy a View component.
             */
            virtual ~View();

            /**
             * @brief Set the x position attribute.
             * 
             * @param xPosition is the new value to x axis in the position.
             */
            virtual void setXPosition(const float xPosition) override;

            /**
             * @brief Set the y position attribute.
             * 
             * @param yPosition is the new value to y axis in the position.
             */
            virtual void setYPosition(const float yPosition) override;

            /**
             * @brief Set the x position attribute.
             * 
             * @param xPosition is the new value to x axis in the position.
             * @param yPosition is the new value to y axis in the position.
             */
            virtual void setPosition(const float xPosition, const float yPosition) override;

            /**
             * @brief Set the position attribute.
             * 
             * @param position is the new value to the position.
             */
            virtual void setPosition(const Vector2 position) override;
        
        protected:
            /**
             * @brief Update all inner components positions.
             */
            virtual void updateInnerComponentsPositions() = 0;

            /**
             * @brief Define the width of the view.
             */
            virtual void findWidth() = 0;

            /**
             * @brief Define the height of the view.
             */
            virtual void findHeight() = 0;
    };
}

#endif
