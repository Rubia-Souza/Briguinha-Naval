#ifndef IDISPLAY_ICON_HPP
#define IDISPLAY_ICON_HPP

#include <string>
#include "raylib.h"

namespace Components {
    class IDisplayIcon {
        public:
            /**
             * @brief Set the path attribute.
             * 
             * @param path is the new value to path.
             */
            virtual void setIconPath(const std::string path) = 0;

            /**
             * @brief Get the default image path attribute.
             * 
             * @return Default path attribute value.
             */
            virtual std::string getIconPath() const = 0;

            /**
             * @brief Set the Icon Height attribute.
             * 
             * @param height is the new value height.
             */
            virtual void setIconHeight(const float height) = 0;

            /**
             * @brief Get the icon height attribute.
             * 
             * @return Icon height attribute value.
             */
            virtual float getIconHeight() const = 0;

            /**
             * @brief Set the Icon Width attribute.
             * 
             * @param width is the new value width.
             */
            virtual void setIconWidth(const float width) = 0;

            /**
             * @brief Get the icon width attribute.
             * 
             * @return Icon width attribute value.
             */
            virtual float getIconWidth() const = 0;
    };
}

#endif
