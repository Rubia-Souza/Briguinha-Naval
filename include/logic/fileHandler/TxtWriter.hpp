#ifndef TXTWRITER_HPP
#define TXTWRITER_HPP

#include <string>

#include "FileHandler.hpp"
#include "MatchResults.hpp"

class TxtWriter : public FileHandler {
    public:
        /**
         * Construct a TxtWriter instance with a file name.
         * @brief Construct a new Txt Writer object.
         * 
         * @param name Name of the file which will be written to.
         */
        TxtWriter(const std::string name);

        /**
         * @brief Destroy the Txt Writer object.
         * 
         */
        ~TxtWriter();
        
        /**
         * @brief Write a matchResults instance to the opened file.
         * 
         * @param match The matchResults which values will be written to the file.
         */
        void writeResults(const MatchResults& match);
    
    private:
        /**
         * @brief Convert a score and a name to a standard string, for future reading.
         * 
         * @param name The name of the player associated to the score.
         * @param score The score which will be saved to the file.
         * @return A string with the player name and the score attributes (in its header declaration order), separated by spaces.
         */
        std::string getScoreString(const std::string name, const Score score) const;

        /**
         * @brief Converts a player name to a new string for proper future reading.
         * 
         * @param name A string with the player name.
         * @return A string with the player name, with spaces replaced by PLACEHOLDERCHAR.
         */
        std::string parsePlayerName(std::string name) const;
};

#endif