#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <memory>

#include "Match.hpp"
#include "Player.hpp"

#include "GameParameters.hpp"

class GameManager {
    private:
        /**
         * Instance is a static member to guarantee only one match being played
         */
        static std::shared_ptr<GameManager> instance;
        
        /**
         * Other game instances and parameters for correct flow of the game.
         * 
         */
        std::shared_ptr<Match> match = nullptr;
        bool player1HasPositionedTroops = false;
        bool player2HasPositionedTroops = false;

        GameParameters gameParameters;

    public:
        /**
         * Constructs the game manager and initializes the player score.
         * @brief Default constructor.
         * 
         */
        GameManager();
        
        /**
         * @brief Destroy the Game Manager object.
         * 
         */
        virtual ~GameManager();

        /**
         * @brief Starts the game with player positioning, then loads proper screens and begins the game.
         * 
         */
        void startGame();

        /**
         * @brief Ends the game, getting eachs player's stats.
         * 
         */
        void endGame();

        /**
         * @brief Gets the current game parameters.
         * 
         * @return The value of the current game parameters.
         */
        GameParameters getGameParameters() const;

        /**
         * @brief Get the instance of the current game.
         * 
         * @return A pointer referencing the gameManager instance.
         */
        static std::shared_ptr<GameManager> getInstance();        
    
    private:
        /**
         * @brief Initializes the Match object with the default values.
         * 
         */
        void initializeMatch();

        /**
         * @brief Initializes the player's score with the default values.
         * 
         */
        void intializePlayersScore();

        /**
         * @brief Begins the positioning part of the game of a certain player.
         * 
         * @param playerBoard A pointer to the player which will start positioning.
         */
        void startPlayerPositioningTurn(std::shared_ptr<Player> playerBoard);

        /**
         * @brief Writes the current match score to a text file for further usage.
         * 
         */
        void registerScores();

        /**
         * @brief Reset GameManager attributes to default initial values.
         * 
         */
        void resetGameManager();
};

#endif
