#ifndef GAME_PARAMETERS_HPP
#define GAME_PARAMETERS_HPP

class GameParameters {
    private:
        /**
         * Constants for the default game size and troops, and sets each troop according to them.
         */
        static const int DEFAULT_AMOUNT_TROOPS;
        static const int DEFAULT_BOARD_AMOUNT_HORIZONTAL_CELLS;
        static const int DEFAULT_BOARD_AMOUNT_VERTICAL_CELLS;

        int amountSubmarineTroops = DEFAULT_AMOUNT_TROOPS;
        int amountCrusierTroops = DEFAULT_AMOUNT_TROOPS;
        int amountBattleshipTroops = DEFAULT_AMOUNT_TROOPS;

        int boardAmountHorizontalCells = DEFAULT_BOARD_AMOUNT_HORIZONTAL_CELLS;
        int boardAmountVerticalCells = DEFAULT_BOARD_AMOUNT_VERTICAL_CELLS;

    public:
        /**
         * Constructs gameParameters, nothing to set here.
         * @brief Default constructor.
         * 
         */
        GameParameters();

        /**
         * @brief Destroy the Game Parameters object.
         * 
         */
        virtual ~GameParameters();

        /**
         * @brief Set the new amount of submarine troops.
         * 
         * @param amountSubmarineTroops The new amount of submarine troops to be used.
         */
        void setAmountSubmarineTroops(const int amountSubmarineTroops);

        /**
         * @brief Get the amount of submarine troops.
         * 
         * @return The value of the amount of submarine troops.
         */
        int getAmountSubmarineTroops() const;

        /**
         * @brief Set the new amount of crusier troops.
         * 
         * @param amountSubmarineTroops The new amount of crusier troops to be used.
         */
        void setAmountCrusierTroops(const int amountCrusierTroops);

        /**
         * @brief Get the amount of crusier troops.
         * 
         * @return The value of the amount of crusier troops.
         */
        int getAmountCrusierTroops() const;

        /**
         * @brief Set the new amount of battleship troops.
         * 
         * @param amountSubmarineTroops The new amount of battleship troops to be used.
         */
        void setAmountBattleshipTroops(const int amountBattleshipTroops);

        /**
         * @brief Get the amount of battleship troops.
         * 
         * @return The value of the amount of battleship troops.
         */
        int getAmountBattleshipTroops() const;

        /**
         * @brief Set the number of horizontal cells on the board.
         * 
         * @param boardAmountHorizontalCells The new value of horizontal cells on the board.
         */
        void setBoardAmountHorizontalCells(const int boardAmountHorizontalCells);

        /**
         * @brief Get the number of horizontal cells on the board.
         * 
         * @return int The value of the number of horizontal cells on the board.
         */
        int getBoardAmountHorizontalCells() const;

        /**
         * @brief Set the number of vertical cells on the board.
         * 
         * @param boardAmountHorizontalCells The new value of vertical cells on the board.
         */
        void setBoardAmountVerticalCells(const int boardAmountVerticalCells);
        
        /**
         * @brief Get the number of vertical cells on the board.
         * 
         * @return int The value of the number of vertical cells on the board.
         */
        int getBoardAmountVerticalCells() const;

        /**
         * @brief Get the total amount of troops a player can have.
         * 
         * @return int that is the total amount of troops a player can have.
         */
        int getTotalAmountOfTroops() const;
};

#endif
