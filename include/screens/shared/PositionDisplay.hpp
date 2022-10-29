#ifndef POSITION_DISPLAY_HPP
#define POSITION_DISPLAY_HPP

#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "Image.hpp"
#include "IClickable.hpp"

#include "Position.hpp"
#include "Point.hpp"

#include "Colors.hpp"

namespace Views {
    class PositionDisplay : public View, public Components::IClickable {
        protected:
            std::unique_ptr<Components::Image> troopImage = nullptr;

            Rectangle background;
            Color backgroundColor = DEFAULT_BALCK;
            Color hoveredBackgroundColor = DEFAULT_BALCK;

            std::shared_ptr<Position> position = nullptr;

        public:
            /**
             * @brief Create the basic template for the troop display with a new logic position.
             * @param boardCoordinates is the coordinates that the position is placed.
             */
            PositionDisplay(const Point boardCoordinates);

            /**
             * @brief Create the basic template for the troop display with a new logic position.
             * @param position is the logic position that will base the display.
             */
            PositionDisplay(std::shared_ptr<Position> position);

            /**
             * @brief Destroy the Position Display view.
             */
            virtual ~PositionDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() = 0;

            /**
             * @brief Check if the position was clicked.
             * 
             * @return Boolean that indicates if the position was clicked.
             */
            virtual bool checkClick() override;

            /**
             * @brief Check if the mouse is over the position display.
             * 
             * @return Boolean that indicates if the mouse is over the position display.
             */
            virtual bool checkMouseOver() override;

            /**
             * @brief Get the coodinates the position is place.
             * 
             * @return Coordinates attribute copy.
             */
            Point getCoordinates() const;

            /**
             * @brief Set the troop that is in the position.
             * 
             * @param troop is the troop that will be placed at the position.
             */
            void setTroop(const std::shared_ptr<Troop> troop);

            /**
             * @brief Get the troop in the position.
             * 
             * @return Troop pointer that is in the position.
             */
            std::shared_ptr<Troop> getTroop() const;

            /**
             * @brief Set the troop image that will be displayed on this position.
             * 
             * @param path is the path to the troop part image.
             */
            void setTroopImage(const std::string path);

            /**
             * @brief Set the troop image that will be displayed on this position.
             * 
             * @param troop is the troop in this position.
             */
            void setTroopImage(const std::shared_ptr<Troop> troop);

            /**
             * @brief Check if the position contains a troop.
             * 
             * @return Boolean that indicates if the position contains a troop.
             */
            bool containsTroop() const;
        
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
             * @brief Build view component styles.
             */
            void buildComponent();
            
            /**
             * @brief Build background style.
             */
            void buildBackground();

            /**
             * @brief Position background.
             */
            void positionBackground();

            /**
             * @brief Build troop image style.
             */
            void buildTroopImage();
            
            /**
             * @brief Position troop image.
             */
            void positionTroopImage();
        
        protected:
            /**
             * @brief Get image within the position size value.
             * 
             * @return Image within the position size value.
             */
            float getDefaultImageSize() const;
    };
}

#endif
