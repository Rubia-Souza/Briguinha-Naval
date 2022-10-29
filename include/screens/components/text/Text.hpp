#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include "raylib.h"

#include "Component.hpp"
#include "IDisplayText.hpp"

namespace Components {
    class Text : public Component, public IDisplayText {
        public:
            static const float DEFAULT_FONT_SPACING;
            static const Color DEFAULT_COLOR;

            static Font getDefaultFontFamily();
            static float getDefaultFontSize();
            static float getDefaultTitleSize();

        private:
            std::string content = "";
            float fontSize = getDefaultFontSize();
            Color textColor = DEFAULT_COLOR;
            Font fontFamily;

        public:
            /**
             * Constructs the Text component.
             * @brief Default constructor.
             */
            Text();

            /**
             * @brief Constructs the Text component defining the text that will be displayed.
             * @param content is the text that will be displayed.
             */
            Text(const std::string content);

            /**
             * @brief Constructs the Text component defining the text that will be displayed and it's size.
             * @param content is the text that will be displayed.
             * @param fontSize is the size of fontn in the text.
             */
            Text(const std::string content, const float fontSize);

            /**
             * @brief Constructs the Text component defining the text that will be displayed and it's color.
             * @param content is the text that will be displayed.
             * @param textColor is the color that the text will be displayed.
             */
            Text(const std::string content, const Color textColor);

            /**
             * @brief Constructs the Text component defining the text that will be displayed and it's font family.
             * @param content is the text that will be displayed.
             * @param fontFamily is the text font style/family.
             */
            Text(const std::string content, const Font fontFamily);

            /**
             * @brief Constructs the Text component defining the text that will be displayed, it's size and color.
             * @param content is the text that will be displayed.
             * @param fontSize is the size of fontn in the text.
             * @param textColor is the color that the text will be displayed.
             */
            Text(const std::string content, const float fontSize, const Color textColor);

            /**
             * @brief Constructs the Text component defining the text that will be displayed, it's size and font family.
             * @param content is the text that will be displayed.
             * @param fontSize is the size of fontn in the text.
             * @param fontFamily is the text font style/family.
             */
            Text(const std::string content, const float fontSize, const Font fontFamily);

            /**
             * @brief Constructs the Text component defining the text that will be displayed, it's color and font family.
             * @param content is the text that will be displayed.
             * @param textColor is the color that the text will be displayed.
             * @param fontFamily is the text font style/family.
             */
            Text(const std::string content, const Color textColor, const Font fontFamily);

            /**
             * @brief Constructs the Text component defining the text that will be displayed, it's size, color and font family.
             * @param content is the text that will be displayed.
             * @param fontSize is the size of fontn in the text.
             * @param textColor is the color that the text will be displayed.
             * @param fontFamily is the text font style/family.
             */
            Text(const std::string content, const float fontSize, const Color textColor, const Font fontFamily);
            
            /**
             * @brief Destroy the Text component.
             */
            virtual ~Text();
            
            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

            /**
             * @brief Set the text content.
             * 
             * @param text is the text that will be displayed.
             */
            void setText(const std::string content) override;

            /**
             * @brief Get the text that the button display.
             * 
             * @return Text attribute value.
             */
            std::string getText() const override;

            /**
             * @brief Set the font size attribute.
             * 
             * @param fontSize is the new value to the font size.
             */
            void setFontSize(const float fontSize) override;

            /**
             * @brief Get the font size attribute.
             * 
             * @return Font size attribute value.
             */
            float getFontSize() const override;
            
            /**
             * @brief Set the font family attribute.
             * 
             * @param font is the new font family.
             */
            void setFontFamily(const Font font) override;

            /**
             * @brief Get the font family attribute.
             * 
             * @return Font family attribute value.
             */
            Font getFontFamily() const override;

            /**
             * @brief Set the color attribute.
             * 
             * @param color is the new text color.
             */
            void setTextColor(const Color color) override;

            /**
             * @brief Get the text color attribute.
             * 
             * @return Text color attribute value.
             */
            Color getTextColor() const override;

            /**
             * @brief Get the text dimensions attribute.
             * 
             * @return Text dimensions attribute value.
             */
            Vector2 getDimensions() const;
        
        private:
            /**
             * @brief Redefine the width and height of the component.
             */
            void updateTextSize();
    };
}

#endif
