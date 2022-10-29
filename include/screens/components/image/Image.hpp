#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include "raylib.h"

#include "ResizableComponent.hpp"

namespace Components {
    class Image : public ResizableComponent {
        public:
            static const float DEFAULT_WIDTH;
            static const float DEFAULT_HEIGHT;

        private:
            std::string path = "";
            Texture2D content;

        public:
            /**
             * @brief Default constructor.
             */
            Image();

            /**
             * @brief Constructs the Image component defining it's path.
             * @param path is the path to the image that will be displayed.
             */
            Image(const std::string path);

            /**
             * @brief Constructs the Image component defining it's height and width.
             * @param path is the path to the image that will be displayed.
             * @param height is the height of the image.
             * @param width is the width of the image.
             */
            Image(const std::string path, const float height, const float width);

            /**
             * @brief Destroy the Image component.
             */
            virtual ~Image();

            /**
             * @brief Render the component in the interface.
             */
            virtual void render();

            /**
             * @brief Set the path attribute.
             * 
             * @param path is the new value to path.
             */
            void setPath(const std::string path);

            /**
             * @brief Get the image path attribute.
             * 
             * @return Image path attribute value.
             */
            std::string getPath() const;

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
             * @brief Load the image from the path in the content attribute.
             */
            void loadImage();

            /**
             * @brief Unload the actual image and loads the image in the path keeping the width and height.
             */
            void updateImage();
    };
}

#endif
