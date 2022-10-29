#ifndef MATCH_RESULTS_HPP
#define MATCH_RESULTS_HPP

#include <string>

#include "Score.hpp"

class MatchResults {
    private:
        /**
         * All stats of a match. Id is composed of the date and time in the format "yyyy/mm/dd-hh:mm:ss".
         * Each player has a score associated.
         */
        std::string id = "";
        std::string player1Name = "";
        std::string player2Name = "";
        Score player1Score;
        Score player2Score;

    public:
        /**
         * Construct a standard MatchResults object, with all values blank.
         * @brief Standard constructor.
         * 
         */
        MatchResults();

        /**
         * @brief Construct a new matchResults object with pre-determined values.
         * 
         * @param player1Name The name of the 1st player.
         * @param player1Score The score associated to the first player.
         * @param player2Name The name of the second player.
         * @param player2Score The score associated with the second player.
         * @param id The id of the match in the correct format.
         */
        MatchResults(const std::string player1Name, const Score player1Score, const std::string player2Name, const Score player2Score, const std::string id);

        /**
         * @brief Destroy the Match Results object.
         * 
         */
        virtual ~MatchResults();

        /**
         * @brief Set the 1st player name.
         * 
         * @param name The new name associated to the first player.
         */
        void setPlayer1Name(const std::string name);

        /**
         * @brief Get the 1st player name.
         *
         * @return A string with the value of the first player name.
         */
        std::string getPlayer1Name() const;
        
        /**
         * @brief Set the score associated to the 1st player.
         * 
         * @param score The new score that will be associated to the first player.
         */
        void setPlayer1Score(const Score score);

        /**
         * @brief Get the score associated to the first player.
         * 
         * @return The value of the score instance associated to the first player.
         */
        Score getPlayer1Score() const;

        /**
         * @brief Set the 2nd player name.
         * 
         * @param name The new name associated to the second player.
         */
        void setPlayer2Name(const std::string name);

        /**
         * @brief Get the 2nd player name.
         *
         * @return A string with the value of the second player name.
         */
        std::string getPlayer2Name() const;
        
        /**
         * @brief Set the score associated to the 2nd player.
         * 
         * @param score The new score that will be associated to the second player.
         */
        void setPlayer2Score(const Score score);

        /**
         * @brief Get the score associated to the second player.
         * 
         * @return The value of the score instance associated to the second player.
         */
        Score getPlayer2Score() const;

        /**
         * @brief Set a new id of a match.
         * 
         * @param id The new id of the match in the correct format.
         */
        void setId(const std::string id);
        
        /**
         * @brief Get the id of the matchResult.
         * 
         * @return A string with the value of the id of a matchResult.
         */
        std::string getId() const;
};

#endif