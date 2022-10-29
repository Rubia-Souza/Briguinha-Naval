#ifndef CRUSIER_DISPLAY_HPP
#define CRUSIER_DISPLAY_HPP

#include <string>

#include "TroopDisplay.hpp"

#include "Troop.hpp"

namespace Views {
    class CrusierDisplay : public TroopDisplay {
        public:
            /**
             * @brief Create the selection to place Crusier troop.
             * @param amount is the amount of that troop can be placed.
             */
            CrusierDisplay(const unsigned int amount);

            /**
             * @brief Destroy the Crusier Display view.
             */
            virtual ~CrusierDisplay();

            /**
             * @brief Get a Crusier instantiated object.
             * 
             * @return Crusier instance.
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
