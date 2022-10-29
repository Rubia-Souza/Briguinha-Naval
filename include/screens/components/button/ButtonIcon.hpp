#ifndef BUTTON_ICON_HPP
#define BUTTON_ICON_HPP

#include <memory>
#include <string>
#include "raylib.h"

#include "Button.hpp"
#include "Image.hpp"

namespace Components {
    class ButtonIcon : public Button {
        private:
            std::unique_ptr<Image> icon = nullptr;
            
            std::string defaultIconPath = "";
            std::string hoveredIconPath = "";

        public:
            /**
             * Constructs the ButtonIcon component.
             * @brief Default constructor.
             * @param path is the path to the icon displayed in the button.
             */
            ButtonIcon(const std::string path);

            /**
             * @brief Constructs the ButtonIcon component defining it height and width.
             * @param path is the path to the icon displayed in the button.
             * @param height is the height of the icon
             * @param width is the width of the icon
             */
            ButtonIcon(const std::string path, const float height, const float width);

            /**
             * @brief Destroy the ButtonIcon component.
             */
            virtual ~ButtonIcon();

            /**
             * @brief Render the component in the interface.
             */
            virtual void render() override;

            /**
             * @brief Set the Icon Height attribute.
             * 
             * @param height is the new value height.
             */
            void setIconHeight(const float height);

            /**
             * @brief Get the icon height attribute.
             * 
             * @return Icon height attribute value.
             */
            float getIconHeight() const;

            /**
             * @brief Set the Icon Width attribute.
             * 
             * @param width is the new value width.
             */
            void setIconWidth(const float width);

            /**
             * @brief Get the icon width attribute.
             * 
             * @return Icon width attribute value.
             */
            float getIconWidth() const;

            /**
             * @brief Set the path attribute.
             * 
             * @param path is the new value to path.
             */
            void setIconPath(const std::string path);

            /**
             * @brief Get the default image path attribute.
             * 
             * @return Default path attribute value.
             */
            std::string getIconPath() const;

            /**
             * @brief Set the path to the icon when the mouse is over.
             * 
             * @param path is the new value to path for the icon when the mouse is over.
             */
            void setHoverIconPath(const std::string path);

            /**
             * @brief Get the image path when the button is hovered.
             * 
             * @return Image path when the button is hovered attribute value.
             */
            std::string getHoverIconPath() const;

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
    };
}

#endif
