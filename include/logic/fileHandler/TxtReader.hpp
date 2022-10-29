#ifndef TXTREADER_HPP
#define TXTREADER_HPP

#include <string>
#include <vector>

#include "FileHandler.hpp"
#include "MatchResults.hpp"

class TxtReader : public FileHandler {
    public:
        /**
         * Constructs a new object given a file name.
         * @brief Construct a new Txt Reader object.
         * 
         * @param nome The name of the file to be read.
         */
        TxtReader(const std::string nome);

        /**
         * @brief Destroy the Txt Reader object.
         * 
         */
        ~TxtReader();

        /**
         * @brief Finds a matchResults according to an id string.
         * 
         * @param id A string corresponding to the date and time of the match in the format "yyyy/mm/dd-hh:mm:ss".
         * @return matchResults instance with the values corresponding of the matchResults with the same id.
         */
        MatchResults findMatch(const std::string id);
        
        /**
         * @brief Get all the matchResults stored in the file.
         * 
         * @return A vector of matchResults with corresponding matchResults values stored in the text file.
         */
        std::vector<MatchResults> getMatches();
    
    private:
        /**
         * @brief Resets the file position back to zero.
         * 
         */
        void resetFile();

        /**
         * @brief Converts a proper string to a matchResults object instance.
         * 
         * @param line The properly formatted string which will be converted.
         * @return MatchResults A matchResults object instance with the values of a corresponding string.
         */
        MatchResults strToMatchResult(const std::string line) const;

        /**
         * @brief Converts PLACEHOLDERCHAR to a space on a string.
         * 
         * @param name The desired name to be converted.
         * @return A string with the same name, with the respective chars replaced.
         */
        std::string unparseName(std::string name) const;
};

#endif