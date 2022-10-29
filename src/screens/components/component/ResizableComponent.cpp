#include "ResizableComponent.hpp"

Components::ResizableComponent::~ResizableComponent() {}

#pragma region .: Gets-Sets :.

void Components::ResizableComponent::setHeight(const float height) {
    this->height = height;
    return;   
}

void Components::ResizableComponent::setWidth(const float width) {
    this->width = width;
    return;
}

#pragma endregion
