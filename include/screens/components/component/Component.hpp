#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "raylib.h"

namespace Components {
    class Component {
        public:
            static const float DEFAUT_INITIAL_WIDTH;
            static const float DEFAUT_INITIAL_HEIGHT;
            static const Vector2 DEFAULT_INITIAL_POSITION;

        protected:
            float width = DEFAUT_INITIAL_WIDTH;
            float height = DEFAUT_INITIAL_HEIGHT;
            Vector2 position = DEFAULT_INITIAL_POSITION;

        public:
            /**
             * @brief Destroy the Component.
             */
            virtual ~Component();

            /**
             * @brief Define the render contract of components.
             */
            virtual void render() = 0;

            /**
             * @brief Get the width attribute.
             * 
             * @return Width attribute value.
             */
            virtual float getWidth() const;

            /**
             * @brief Get the height attribute.
             * 
             * @return Height attribute value.
             */
            virtual float getHeight() const;
        
            /**
             * @brief Set the x position attribute.
             * 
             * @param xPosition is the new value to x axis in the position.
             */
            virtual void setXPosition(const float xPosition);

            /**
             * @brief Get the X position attribute.
             * 
             * @return X position attribute value.
             */
            virtual float getXPosition() const;

            /**
             * @brief Set the y position attribute.
             * 
             * @param yPosition is the new value to y axis in the position.
             */
            virtual void setYPosition(const float yPosition);

            /**
             * @brief Get the Y position attribute.
             * 
             * @return Y position attribute value.
             */
            virtual float getYPosition() const;

            /**
             * @brief Set the x position attribute.
             * 
             * @param xPosition is the new value to x axis in the position.
             * @param yPosition is the new value to y axis in the position.
             */
            virtual void setPosition(const float xPosition, const float yPosition);

            /**
             * @brief Set the position attribute.
             * 
             * @param position is the new value to the position.
             */
            virtual void setPosition(const Vector2 position);

            /**
             * @brief Get the position attribute.
             * 
             * @return position attribute value.
             */
            virtual Vector2 getPosition() const;
    };
}

#endif
