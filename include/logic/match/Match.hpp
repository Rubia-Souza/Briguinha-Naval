#ifndef MATCH_HPP
#define MATCH_HPP

#include <string>
#include <memory>

#include "Player.hpp"
#include "MatchResults.hpp"

class Match {
    private:
        /**
         * The id of the match in the format "yyyy/mm/dd-hh:mm:ss", the number of the current turn and a pointer to the 2 players of the match.
         */
        std::string id = "";
        unsigned int currentTurn = 0;
        std::shared_ptr<Player> player1 = nullptr;
        std::shared_ptr<Player> player2 = nullptr;

    public:
        /**
         * Creates the id, and both players' names.
         * @brief Default constructor.
         * 
         */
        Match();

        /**
         * @brief Destroy the Match object.
         * 
         */
        virtual ~Match();

        /**
         * @brief Finish the actual turn and start the next one.
         * 
         */
        void passTurn();

        /**
         * @brief Checks if it's the player 1 turn.
         * 
         * @return an boolean that says if it's player 1 turn or not.
         */
        bool isPlayer1Turn() const;

        /**
         * @brief Checks if it's the player 2 turn.
         * 
         * @return an boolean that says if it's player 2 turn or not.
         */
        bool isPlayer2Turn() const;
        
        /**
         * @brief Update the player 1 score when making an play.
         * 
         * @param wasTroopDestroyed If the troop was destroyed.
         */
        void incrementPlayer1Score(const bool wasTroopDestroyed);

        /**
         * @brief Increment the total amount of shots the player 1 has done.
         * 
         */
        void incrementPlayer1AmountShots();
        
        /**
         * @brief Update the player 2 score when making an play.
         * 
         * @param wasTroopDestroyed If the troop was destroyed.
         */
        void incrementPlayer2Score(const bool wasTroopDestroyed);

        /**
         * @brief Increment the total amount of shots the player 2 has done.
         * 
         */
        void incrementPlayer2AmountShots();

        /**
         * @brief Gets the player1 attribute by reference.
         * 
         * @return A pointer containing the original player1 attribute.
         */
        std::shared_ptr<Player> getPlayer1() const;
        
        /**
         * @brief Gets the player2 attribute by reference.
         * 
         * @return A pointer containing the original player2 attribute.
         */
        std::shared_ptr<Player> getPlayer2() const;

        /**
         * @brief Get the matchResults affiliated to the current match.
         * 
         * @return A matchResults attribute with relevant match data for storage.
         */
        MatchResults getResults() const;

        /**
         * @brief Verify if the game has reach it's end.
         * 
         * @return an boolean that says if the game has ended or not.
         */
        bool hasGameFinished() const;

    private:
        /**
         * @brief Creates a match id for the current match.
         * 
         * @return A correctly formatted string identifying the match that will start.
         */
        std::string createMatchId() const;
};

#endif