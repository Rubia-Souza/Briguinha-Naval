#ifndef TROOP_DISPLAY_HPP
#define TROOP_DISPLAY_HPP

#include <string>
#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "Text.hpp"
#include "Image.hpp"
#include "IClickable.hpp"

#include "Troop.hpp"

namespace Views {
    class TroopDisplay : public View, public Components::IClickable {
        private:
            std::unique_ptr<Components::Text> amountTroopType = nullptr;
            std::unique_ptr<Components::Image> troopImage = nullptr;
            Rectangle background;

            unsigned int amount = 0;
            std::string troopName = "";

        public:
            /**
             * @brief Create the template of a troop that can be positioned.
             * @param amount is the amount of that troop can be placed.
             * @param troopName is the name of the type of the troop that can be placed.
             * @param troopImagePath is the full sprite of the troop that can be placed.
             */
            TroopDisplay(const unsigned int amount, const std::string troopName, const std::string troopImagePath);

            /**
             * @brief Destroy the Troop Display view.
             */
            virtual ~TroopDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Check if the troop display was clicked.
             * 
             * @return Boolean that indicates if the troop display was clicked.
             */
            virtual bool checkClick() override;

            /**
             * @brief Check if the mouse is over the troop display.
             * 
             * @return Boolean that indicates if the mouse is over the troop display.
             */
            virtual bool checkMouseOver() override;

            /**
             * @brief Set the amount of troops that can be placed.
             * 
             * @param amount is the quantity of troops that can be placed.
             */
            void setAmount(const unsigned int amount);

            /**
             * @brief Get the amount of this troop type that can be placed.
             * 
             * @return Amount of this troop that can be placed.
             */
            unsigned int getAmount() const;

            /**
             * @brief Decrement the amount of available troops that can be placed.
             */
            void decrementAmount();

            /**
             * @brief Increment the amount of available troops that can be placed.
             */
            void incrementAmount();

            /**
             * @brief Set the name of the troop that will be displayed.
             * 
             * @param troopName is the name of the troop that will be displayed.
             */
            void setTroopName(const std::string troopName);

            /**
             * @brief Get the troop name.
             * 
             * @return The troop name value.
             */
            std::string getTroopName() const;

            /**
             * @brief Get the troop class name.
             * 
             * @return The troop class name value.
             */
            virtual std::string getTroopClassName() const = 0;

            /**
             * @brief Get a instantiated object of a troop.
             * 
             * @return Specific troop instance.
             */
            virtual std::shared_ptr<Troop> getTroopInstance() const = 0;

            /**
             * @brief Set the width of the full sprite of the troop diplayed.
             * 
             * @param width is new width.
             */
            void setTroopImageWidth(const float width);

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
             * @brief Update the amount of troop available to be positioned displayed.
             */
            void updateLabelValue();
            
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
             * @brief Build troop name text style.
             */
            void buildAmountTroopTypeText();

            /**
             * @brief Position troop name text.
             */
            void poisitionAmountTroopTypeText();

            /**
             * @brief Build troop sprite image style.
             */
            void buildTroopImage();

            /**
             * @brief Position troop sprite image.
             */
            void positionTroopImage();

            /**
             * @brief Get text with the amount of available troops to be positioned and it's name.
             * 
             * @return Built string of amount of available troops and it's name.
             */
            std::string buildAmountTroopTypeTextLabel(const unsigned int amount, const std::string troopName) const;
    };
}

#endif
