#ifndef BUTTON_TEXT_HPP
#define BUTTON_TEXT_HPP

#include <memory>
#include <string>
#include "raylib.h"

#include "Button.hpp"
#include "Text.hpp"
#include "IDisplayText.hpp"

namespace Components {
    class ButtonText : public Button, public IDisplayText {
        private:
            std::unique_ptr<Text> text = nullptr;
            
            Color textColor = Text::DEFAULT_COLOR;
            Color mouseHoverTextColor = Text::DEFAULT_COLOR;

        public:
            /**
             * Constructs the ButtonText component.
             * @brief Default constructor.
             */
            ButtonText();

            /**
             * @brief Constructs the ButtonText component recieving the text of it.
             * @param labelText is the text within the button
             */
            ButtonText(const std::string labelText);

            /**
             * @brief Destroy the ButtonText component.
             */
            virtual ~ButtonText();

            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

            /**
             * @brief Set the text content.
             * 
             * @param text is the text that will be displayed.
             */
            void setText(const std::string text) override;

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
             * @brief Set the color of the text when the mouse is over.
             * 
             * @param color is the new value to color the text will be rendered when the mouse is over.
             */
            void setMouseHoverTextColor(const Color color);

            /**
             * @brief Get the text color when the mouse is hover the button.
             * 
             * @return Text color hover attribute value.
             */
            Color getMouseHoverTextColor() const;

            /**
             * @brief Set the height attribute.
             * 
             * @param height is the new value to height.
             */
            virtual void setHeight(const float height) override;

            /**
             * @brief Set the width attribute.
             * 
             * @param width is the new value to width.
             */
            virtual void setWidth(const float width) override;
        
        private:
            /**
             * @brief Set the component attributes to the default values.
             */
            void setDefaultValues();
    };
}

#endif
