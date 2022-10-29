#ifndef BUTTON_TEXT_ICON_HPP
#define BUTTON_TEXT_ICON_HPP

#include <memory>
#include <string>
#include "raylib.h"

#include "Button.hpp"
#include "TextIcon.hpp"

#include "IDisplayText.hpp"
#include "IDisplayIcon.hpp"

#include "Colors.hpp"

namespace Components {
    class ButtonTextIcon : public Button, public IDisplayIcon, public IDisplayText {
        private:
            std::shared_ptr<TextIcon> content = nullptr;
            
            Color textColor = DEFAULT_WHITE;
            Color mouseHoverTextColor = DEFAULT_WHITE;

        public:
            /**
             * Constructs the ButtonTextIcon component.
             * @brief Default constructor.
             * @param iconPath is the path to the icon that will be dsplayed
             * @param label is the text that will be displayed after the icon
             */
            ButtonTextIcon(const std::string iconPath, const std::string label);

            /**
             * @brief Destroy the ButtonTextIcon component.
             */
            virtual ~ButtonTextIcon();

            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

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

            /**
             * @brief Set the path attribute.
             * 
             * @param path is the new value to path.
             */
            virtual void setIconPath(const std::string path) override;

            /**
             * @brief Get the icon path attribute.
             * 
             * @return Icon path attribute value.
             */
            virtual std::string getIconPath() const override;

            /**
             * @brief Set the Icon Height attribute.
             * 
             * @param height is the new value height.
             */
            virtual void setIconHeight(const float height) override;

            /**
             * @brief Get the icon height attribute.
             * 
             * @return Icon height attribute value.
             */
            virtual float getIconHeight() const override;

            /**
             * @brief Set the Icon Width attribute.
             * 
             * @param width is the new value width.
             */
            virtual void setIconWidth(const float width) override;

            /**
             * @brief Get the icon width attribute.
             * 
             * @return Icon width attribute value.
             */
            virtual float getIconWidth() const override;

            /**
             * @brief Set the text content.
             * 
             * @param text is the text that will be displayed.
             */
            virtual void setText(const std::string content) override;

            /**
             * @brief Get the text that the button display.
             * 
             * @return Text content attribute value.
             */
            virtual std::string getText() const override;
            
            /**
             * @brief Set the font size attribute.
             * 
             * @param fontSize is the new value to the font size.
             */
            virtual void setFontSize(const float fontSize) override;

            /**
             * @brief Get the font size attribute.
             * 
             * @return Font size attribute value.
             */
            virtual float getFontSize() const override;
            
            /**
             * @brief Set the font family attribute.
             * 
             * @param font is the new font family.
             */
            virtual void setFontFamily(const Font font) override;

            /**
             * @brief Get the font family attribute.
             * 
             * @return Font family attribute value.
             */
            virtual Font getFontFamily() const override;

            /**
             * @brief Set the color attribute.
             * 
             * @param color is the new text color.
             */
            virtual void setTextColor(const Color color) override;

            /**
             * @brief Get the text color attribute.
             * 
             * @return Text color attribute value.
             */
            virtual Color getTextColor() const override;

            /**
             * @brief Set the color of the text when the mouse is over.
             * 
             * @param color is the new value to color the text will be rendered when the mouse is over.
             */
            virtual void setMouseHoverTextColor(const Color color);

            /**
             * @brief Get the text color when the mouse is hover the button.
             * 
             * @return Text color hover attribute value.
             */
            virtual Color getMouseHoverTextColor() const;

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
            virtual void updateInnerComponentsPositions();
        
        private:
            /**
             * @brief Update the component height attribute.
             */
            void updateHeight();

            /**
             * @brief Update the component width attribute.
             */
            void updateWidth();

            /**
             * @brief Get button default width size value.
             * 
             * @return Button default width size value.
             */
            static float getDefaultWidth();

            /**
             * @brief Get button default height size value.
             * 
             * @return Button default height size value.
             */
            static float getDefaultHeight();
    };
}

#endif
