#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <fstream>

class FileHandler {
    protected:
        /**
         * The char placeholder for future replacement on strings to bypass reading strings for a stream with spaces, and the file stream which will be used.
         * 
         */
        static const char PLACEHOLDERCHAR;
        std::fstream file;

    public:
        /**
         * Constructs given a name and interacting mode.
         * @brief Construct a new FileHandler object.
         * 
         * @param name The name of the file to be interacted with.
         * @param mode The mode of reading the file, available modes are reading ('r'), writing ('w'), and appending ('a').
         */
        FileHandler(const std::string name, const char mode);
        
        /**
         * @brief Destroy the File Handler object. Closes the file.
         * 
         */
        ~FileHandler();
};

#endif