#ifndef SUBMARINE_DISPLAY_HPP
#define SUBMARINE_DISPLAY_HPP

#include <string>

#include "TroopDisplay.hpp"

#include "Troop.hpp"

namespace Views {
    class SubmarineDisplay : public TroopDisplay {
        public:
            /**
             * @brief Create the selection to place Submarine troop.
             * @param amount is the amount of that troop can be placed.
             */
            SubmarineDisplay(const unsigned int amount);

            /**
             * @brief Destroy the Submarine Display view.
             */
            virtual ~SubmarineDisplay();

            /**
             * @brief Get a Submarine instantiated object.
             * 
             * @return Submarine instance.
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
