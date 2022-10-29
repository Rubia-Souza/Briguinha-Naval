#ifndef IRESIZABLE_HPP
#define IRESIZABLE_HPP

namespace Components {
    class IResizable {
        public:
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
