#include <string>
#include <stdexcept>

#include "CustomException.hpp"

CustomException::CustomException(const std::string message) {
    this->message = message;
}

CustomException::~CustomException() {}

#pragma region .: Gets-Sets :.

std::string CustomException::getMessage() const {
    return message;
}

#pragma endregion
