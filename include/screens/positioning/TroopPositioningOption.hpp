#ifndef TROOP_POSITIONING_OPTION_HPP
#define TROOP_POSITIONING_OPTION_HPP

#include <string>
#include <memory>
#include <vector>
#include "raylib.h"

#include "View.hpp"
#include "ButtonIcon.hpp"
#include "ButtonText.hpp"

#include "TroopDisplay.hpp"

namespace Views {
    class TroopPositioningOption : public View {
        private:
            std::vector<std::shared_ptr<TroopDisplay>> availableTroops;
            std::unique_ptr<Components::ButtonIcon> buttonRotate = nullptr;
            std::unique_ptr<Components::ButtonText> buttonEndPositioningTurn = nullptr;

            Rectangle background;

        public:
            /**
             * @brief Create the section that displays all troops that can be positioned.
             */
            TroopPositioningOption();

            /**
             * @brief Destroy the Troop Positioning Options view.
             */
            virtual ~TroopPositioningOption();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Check if the button rotate was clicked.
             * 
             * @return Boolean that indicates if the rotate button was clicked.
             */
            bool checkButtonRotateClick();

            /**
             * @brief Check if the button that end the positioning turn was clicked.
             * 
             * @return Boolean that indicates if the button that end the positioning turn was clicked.
             */
            bool checkButtonEndPositioningTurn();

            /**
             * @brief Decrement the amount of available troops that can be placed based on it's type name.
             * 
             * @param troopType is the type of the troop that will have it's amount decremented.
             */
            void decrementTroopAmount(const std::string troopType);

            /**
             * @brief Increment the amount of available troops that can be placed based on it's type name.
             * 
             * @param troopType is the type of the troop that will have it's amount incremented.
             */
            void incrementTroopAmount(const std::string troopType);
            
            /**
             * @brief Checks if all the troops was positioned.
             * 
             * @return Boolean that the verifies if the player has positioned all the troops.
             */
            bool hasPositionedAllTroops() const;

            /**
             * @brief Get the all troops that can be selected.
             * 
             * @return Vector of all troops that can be selected.
             */
            std::vector<std::shared_ptr<TroopDisplay>> getSelectableTroops() const;

        protected:
            /**
             * @brief Update all inner components positions.
             */
            virtual void updateInnerComponentsPositions() override;

            /**
             * @brief Define the width of the view.
             */
            virtual void findWidth() override;

            /**
             * @brief Define the height of the view.
             */
            virtual void findHeight() override;
        
        private:
            /**
             * @brief Build background style.
             */
            void buildBackground();

            /**
             * @brief Position background.
             */
            void positionBackground();

            /**
             * @brief Render background.
             */
            void renderBackground();

            /**
             * @brief Build troops diplays views.
             */
            void buildTroopDisplays();

            /**
             * @brief Build button rotate style.
             */
            void buildButtonRotate();

            /**
             * @brief Position button rotate.
             */
            void positionButtonRotate();

            /**
             * @brief Build end positioning turn button style.
             */
            void buildButtonEndPositioningTurn();

            /**
             * @brief Position end positioning turn button.
             */
            void positionButtonEndPositioningTurn();

            /**
             * @brief Position selectable troops display sections.
             */
            void positionTroopsDisplays();
    };
}

#endif
