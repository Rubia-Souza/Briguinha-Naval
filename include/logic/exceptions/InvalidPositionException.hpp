#ifndef INVALID_POSITION_EXCEPTION_HPP
#define INVALID_POSITION_EXCEPTION_HPP

#include <string>

#include "CustomException.hpp"

class InvalidPositionException : public CustomException {
    public:
        /**
         * @brief Construct a new InvalidPosition object.
         * 
         * @param message The message associated with the exception.
         */
        InvalidPositionException(const std::string message);
        
        /**
         * @brief Destroy the Invalid Position Exception object.
         * 
         */
        virtual ~InvalidPositionException();
};

#endif
