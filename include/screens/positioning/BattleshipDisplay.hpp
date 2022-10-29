#ifndef BATTLESHIP_DISPLAY_HPP
#define BATTLESHIP_DISPLAY_HPP

#include <string>

#include "TroopDisplay.hpp"

#include "Troop.hpp"

namespace Views {
    class BattleshipDisplay : public TroopDisplay {
        public:
            /**
             * @brief Create the selection to place Battleship troop.
             * @param amount is the amount of that troop can be placed.
             */
            BattleshipDisplay(const unsigned int amount);

            /**
             * @brief Destroy the Battleship Display view.
             */
            virtual ~BattleshipDisplay();

            /**
             * @brief Get a Battleship instantiated object.
             * 
             * @return Battleship instance.
             */
            virtual std::shared_ptr<Troop> getTroopInstance() const override;

            /**
             * @brief Get the troop class name.
             * 
             * @return The troop class name value.
             */
            virtual std::string getTroopClassName() const override;
    };
}

#endif
