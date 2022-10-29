#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "raylib.h"

#include "Component.hpp"
#include "ResizableComponent.hpp"
#include "IClickable.hpp"

namespace Components {
    class Button : public ResizableComponent, public IClickable {
        public:
            static const Color DEFAULT_BACKGROUND_COLOR;

        protected:
            Rectangle background;
            Color backgroundColor = DEFAULT_BACKGROUND_COLOR;
            Color mouseHoverBackgroundColor = DEFAULT_BACKGROUND_COLOR;

        public:
            /**
             * Constructs the Button component.
             * @brief Default constructor.
             */
            Button();

            /**
             * @brief Destroy the Button component.
             */
            virtual ~Button();

            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

            /**
             * @brief Check if the troop display was clicked.
             * 
             * @return Boolean that indicates if the troop display was clicked.
             */
            virtual bool checkClick() override;

            /**
             * @brief Check if the mouse is over the troop display.
             * 
             * @return Boolean that indicates if the mouse is over the troop display.
             */
            virtual bool checkMouseOver() override;

            /**
             * @brief Set the background color attribute.
             * 
             * @param color is the new color of the background.
             */
            void setBackgroundColor(const Color color);

            /**
             * @brief Get the background color attribute.
             * 
             * @return Background color attribute value.
             */
            Color getBackgroundColor() const;

            /**
             * @brief Set the background color when the mouse is over the button.
             * 
             * @param color is the new color of the background when the mouse is over the button.
             */
            void setMouseHoverBackgroundColor(const Color color);

            /**
             * @brief Get the background color attribute when the mouse is over.
             * 
             * @return Background color attribute value when the mouse is over.
             */
            Color getMouseHoverBackgroundColor() const;

            /**
             * @brief Set the height attribute.
             * 
             * @param height is the new value to height.
             */
            virtual void setHeight(const float height) = 0;

            /**
             * @brief Set the width attribute.
             * 
             * @param width is the new value to width.
             */
            virtual void setWidth(const float width) = 0;
    };
}

#endif
