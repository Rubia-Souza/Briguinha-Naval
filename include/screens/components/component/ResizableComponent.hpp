#ifndef RESIZABLE_COMPONENT_HPP
#define RESIZABLE_COMPONENT_HPP

#include "Component.hpp"
#include "IResizable.hpp"

namespace Components {
    class ResizableComponent : public Component, public IResizable {
        public:
            /**
             * @brief Destroy a ResizableComponent component.
             */
            virtual ~ResizableComponent();

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
};

#endif
