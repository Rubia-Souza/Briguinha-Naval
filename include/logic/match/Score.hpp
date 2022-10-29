#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
    private:
        /**
         * Different stats for a game.
         * 
         */
        int destroyedTroops = 0;
        int remainingTroops = 0;
        int lostTroops = 0;
        int totalAmountShoots = 0;
        int hitShoots = 0;

    public:
        /**
         * Construct a new score object with all values as 0.
         * @brief Default constructor.
         * 
         */
        Score();

        /**
         * @brief Construct a new Score object with custom values.
         * 
         * @param dTroops Number of destroyed troops.
         * @param rTroops Number of remaining troops.
         * @param lTroops Number of lost troops.
         * @param tAShoots Number of the total amount of shoots.
         * @param hShoots Number of the total shoots hit.
         */
        Score(int dTroops, int rTroops, int lTroops, int tAShoots, int hShoots);

        /**
         * @brief Destroy the Score object
         * 
         */
        virtual ~Score();

        /**
         * @brief Determine if the player associated to the score won.
         * 
         * @return Whether the game ended in a win for the player associated.
         */
        bool isWinner() const;

        /**
         * @brief Set the destroyedTroops attribute.
         * 
         * @param value The new value of the destroyedTroops.
         */
        void setDestroyedTroops(const int value);

        /**
         * @brief Increases the number of destroyedTroops by one.
         * 
         */
        void incrementDestroyedTroops();

        /**
         * @brief Get the number of destroyedTroops.
         * 
         * @return The value of destroyedTroops.
         */
        int getDestroyedTroops() const;

        /**
         * @brief Set the remainingTroops attribute.
         * 
         * @param value The new value of the remainingTroops.
         */
        void setRemainingTroops(const int value);

        /**
         * @brief Decreases the number of remainingTroops by one.
         * 
         */
        void decrementRemainingTroops();

        /**
         * @brief Get the number of remainingTroops.
         * 
         * @return The value of remainingTroops.
         */
        int getRemainingTroops() const;

        /**
         * @brief Set the lostTroops attribute.
         * 
         * @param value The new value of the lostTroops.
         */
        void setLostTroops(const int value);

        /**
         * @brief Incrases the number of lostTroops by one.
         * 
         */
        void incrementLostTroops();

        /**
         * @brief Get the number of lostTroops.
         * 
         * @return The value of lostTroops.
         */
        int getLostTroops() const;

        /**
         * @brief Set the totalAmountShoots attribute.
         * 
         * @param value The new value of the hitsShoots.
         */
        void setTotalAmountShoots(const int value);

        /**
         * @brief Incrases the number of totalAmountShoots by one.
         * 
         */
        void incrementTotalAmountShoots();

        /**
         * @brief Get the number of totalAmountShoots.
         * 
         * @return The value of totalAmountShoots.
         */
        int getTotalAmountShoots() const;

        /**
         * @brief Set the hitShoots attribute.
         * 
         * @param value The new value of the hitShoots.
         */
        void setHitShoots(const int value);

        /**
         * @brief Incrases the number of hitShoots by one.
         * 
         */
        void incrementHitShoots();

        /**
         * @brief Get the amount of shots that hit an troop done by the player.
         * 
         * @return int that is the amount of hit shots;
         */
        int getHitShoots() const;

        /**
         * @brief Get the initial amount of ships value.
         * 
         * @return The initial amount of ships value, sum of lost troops and remaining troops.
         */
        int getInitialAmountShips() const;
        
        /**
         * @brief Get the precision of the shoots.
         * 
         * @return The general precision of the shots, division of hit shots by total amount of shoots
         */
        float getPrecision() const;
};

#endif
