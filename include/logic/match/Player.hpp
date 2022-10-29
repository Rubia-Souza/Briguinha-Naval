#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <memory>

#include "Board.hpp"
#include "Score.hpp"

class Player{
    private:
        /**
         * Player name, along with the score and board associated with it.
         * 
         */
        std::string name = "";
        std::shared_ptr<Score> score = nullptr;
        std::shared_ptr<Board> board = nullptr;
        
    public:
        /**
         * Construct a player with default name.
         * @brief Default constructor.
         * 
         */
        Player();
        
        /**
         * Construct a player with a custom name.
         * @brief Construct a new Player object given a name.
         * 
         * @param name The name which will be associated to the player.
         */
        Player(const std::string name);

        /**
         * @brief Destroy the Player object.
         * 
         */
        virtual ~Player();
        
        /**
         * @brief Set a new name of the player.
         * 
         * @param name The new name of the player.
         */
        void setName(const std::string name);
        
        /**
         * @brief Get the player name attribute.
         * 
         * @return The value of a string with the player name.
         */
        std::string getName() const;

        /**
         * @brief Get the player score.
         * 
         * @return A pointer to the original score of the player.
         */
        std::shared_ptr<Score> getScore() const;

        /**
         * @brief Get the player board.
         * 
         * @return A pointer to the original board of the player.
         */
        std::shared_ptr<Board> getBoard() const;
};

#endif