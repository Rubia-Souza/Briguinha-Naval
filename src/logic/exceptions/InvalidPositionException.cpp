#include <string>

#include "InvalidPositionException.hpp"
#include "CustomException.hpp"

InvalidPositionException::InvalidPositionException(const std::string message) : CustomException(message) {}

InvalidPositionException::~InvalidPositionException() {}
