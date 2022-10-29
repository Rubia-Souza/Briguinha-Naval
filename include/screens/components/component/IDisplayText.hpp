#ifndef IDISPLAY_TEXT_HPP
#define IDISPLAY_TEXT_HPP

#include <string>
#include "raylib.h"

namespace Components {
    class IDisplayText {
        public:
            /**
             * @brief Set the text content.
             * 
             * @param text is the text that will be displayed.
             */
            virtual void setText(const std::string content) = 0;

            /**
             * @brief Get the text that the button display.
             * 
             * @return Text attribute value.
             */
            virtual std::string getText() const = 0;
            
            /**
             * @brief Set the font size attribute.
             * 
             * @param fontSize is the new value to the font size.
             */
            virtual void setFontSize(const float fontSize) = 0;

            /**
             * @brief Get the font size attribute.
             * 
             * @return Font size attribute value.
             */
            virtual float getFontSize() const = 0;
            
            /**
             * @brief Set the font family attribute.
             * 
             * @param font is the new font family.
             */
            virtual void setFontFamily(const Font font) = 0;

            /**
             * @brief Get the font family attribute.
             * 
             * @return Font family attribute value.
             */
            virtual Font getFontFamily() const = 0;

            /**
             * @brief Set the color attribute.
             * 
             * @param color is the new text color.
             */
            virtual void setTextColor(const Color color) = 0;

            /**
             * @brief Get the text color attribute.
             * 
             * @return Text color attribute value.
             */
            virtual Color getTextColor() const = 0;
    };
}

#endif
