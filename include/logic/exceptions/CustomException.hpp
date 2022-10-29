#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <string>
#include <stdexcept>

class CustomException : public std::exception {
    protected:
        /**
         * String of the message associated with the exception.
         * 
         */
        std::string message = "";

    public:
        /**
         * @brief Constructs new CustomException object.
         * 
         * @param message The message associated with the object.
         */
        CustomException(const std::string message);
        
        /**
         * @brief Destroy the Custom Exception object.
         * 
         */
        virtual ~CustomException();
        
        /**
         * @brief Get the exception message.
         * 
         * @return A string with the value of the message.
         */
        std::string getMessage() const;
};

#endif
