#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

#include "FileHandler.hpp"

const char FileHandler::PLACEHOLDERCHAR = '$';

FileHandler::FileHandler(const std::string name, const char mode) {
    if(mode == 'r') {
        file.open(name, std::fstream::in);

        if(!file) { 
            throw std::invalid_argument("File sent for reading does not exist");
        }
    }
    else if(mode == 'w') {
        file.open(name, std::fstream::out);
    }
    else if(mode == 'a') {
        file.open(name, std::fstream::in | std::fstream::app);
    }
    else {
        throw std::invalid_argument("Invalid mode selected"); 
    }
}

FileHandler::~FileHandler() {
    file.close();
}
