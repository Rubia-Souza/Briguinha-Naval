#ifndef ICLICKABLE_HPP
#define ICLICKABLE_HPP

namespace Components {
    class IClickable {
        protected:
            bool enabled = true;

        public:
            /**
             * @brief Check if the troop display was clicked.
             * 
             * @return Boolean that indicates if the troop display was clicked.
             */
            virtual bool checkClick() = 0;
            
            /**
             * @brief Check if the mouse is over the troop display.
             * 
             * @return Boolean that indicates if the mouse is over the troop display.
             */
            virtual bool checkMouseOver() = 0;

            /**
             * @brief Set the enabled attribute.
             * 
             * @param enabled is the new value to the attribute.
             */
            virtual void setEnabled(const bool enabled);

            /**
             * @brief Checks if the button is enable.
             * 
             * @return Enabled attribute value.
             */
            virtual bool isEnabled() const;
    };
}

#endif
