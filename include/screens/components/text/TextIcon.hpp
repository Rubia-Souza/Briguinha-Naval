#ifndef TEXT_ICON_HPP
#define TEXT_ICON_HPP

#include <memory>
#include <string>

#include "View.hpp"
#include "IDisplayText.hpp"
#include "IDisplayIcon.hpp"

#include "Text.hpp"
#include "Image.hpp"

namespace Components {
    class TextIcon : public Views::View, public IDisplayText, public IDisplayIcon {
        private:
            std::unique_ptr<Text> text = nullptr;
            std::unique_ptr<Image> icon = nullptr;

        public:
            /**
             * @brief Constructs the TextIcon component defining the icon and text that will be displayed.
             * @param path is the path to the image that will be displayed.
             * @param text is the text that will be displayed.
             */
            TextIcon(const std::string iconPaht, const std::string text);

            /**
             * @brief Destroy a TextIcon component.
             */
            virtual ~TextIcon();
        
            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

            /**
             * @brief Set the text content.
             * 
             * @param text is the text that will be displayed.
             */
            virtual void setText(const std::string text) override;
            
            /**
             * @brief Get the text that the button display.
             * 
             * @return Text attribute value.
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
             * @brief Set the path attribute.
             * 
             * @param path is the new value to path.
             */
            virtual void setIconPath(const std::string path) override;

            /**
             * @brief Get the default image path attribute.
             * 
             * @return Default path attribute value.
             */
            virtual std::string getIconPath() const override;
        
        protected:
            /**
             * @brief Update all inner components positions.
             */
            virtual void updateInnerComponentsPositions() override;

            /**
             * @brief Define the width of the view.
             */
            virtual void findWidth() override;

            /**
             * @brief Define the height of the view.
             */
            virtual void findHeight() override;

        private:
            /**
             * @brief Redefine the width and height of the component.
             */
            void updateSizes();

            /**
             * @brief Get icon margin right value.
             * 
             * @return Icon margin right value.
             */
            float getIconMarginRight() const;
    };
}

#endif
