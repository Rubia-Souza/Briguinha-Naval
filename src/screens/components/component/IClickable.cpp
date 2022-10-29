#include "IClickable.hpp"

#pragma region .: Gets-Sets :.

void Components::IClickable::setEnabled(const bool enabled) {
    this->enabled = enabled;
    return;
}

bool Components::IClickable::isEnabled() const {
    return enabled;
}

#pragma endregion