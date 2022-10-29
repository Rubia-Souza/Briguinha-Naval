#ifndef POSITIONING_POSITION_DISPLAY_HPP
#define POSITIONING_POSITION_DISPLAY_HPP

#include "raylib.h"

#include "PositionDisplay.hpp"

#include "Point.hpp"
#include "Position.hpp"

#include "Colors.hpp"

namespace Views {
    class PositioningPositionDisplay : public PositionDisplay {
        private:
            bool marked = false;
            Color markedColor = DEFAULT_BALCK;

            bool mouseHasEntered = false;

        public:
            /**
             * @brief Create the Position in the Positioning Board stage with a new logic position.
             * @param boardCoordinates is the coordinates that the position is placed.
             */
            PositioningPositionDisplay(const Point boardCoordinates);

            /**
             * @brief Create the Position in the Positioning Board stage based on a logic position.
             * @param position is the logic position that will base the display.
             */
            PositioningPositionDisplay(std::shared_ptr<Position> position);

            /**
             * @brief Destroy the Positioning Position view.
             */
            virtual ~PositioningPositionDisplay();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Check if the mouse has entered in the positioning position view.
             * 
             * @return Boolean that indicates if mouse has entered in the positioning position view.
             */
            bool checkMouseEnter();

            /**
             * @brief Check if the mouse has leave the positioning position view.
             * 
             * @return Boolean that indicates if mouse has leave the positioning position view.
             */
            bool checkMouseExit();

            /**
             * @brief Check if the right mouse button was clicked over the positioning position view.
             * 
             * @return Boolean that indicates if right mouse button was clicked over the positioning position view.
             */
            bool checkMouseRightClick();

            /**
             * @brief Set if the position is marked in a different color.
             * 
             * @param marked is the new value to the identification flag.
             */
            void setMarked(const bool marked);

            /**
             * @brief Check if a position is marked.
             * 
             * @return Marked attribute value.
             */
            bool isMarked() const;

            /**
             * @brief Set the color that the position will be marked.
             * 
             * @param color is the color that the position will be rendered when marked.
             */
            void setMarkedColor(const Color color);

            /**
             * @brief Get the marked color attribute.
             * 
             * @return Marked color attribute value.
             */
            Color getMarkedColor() const;
    };
}

#endif
