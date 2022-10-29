#ifndef WARNING_POP_UP_HPP
#define WARNING_POP_UP_HPP

#include <string>
#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "Text.hpp"
#include "ButtonText.hpp"

namespace Views {
    class WarningPopUp : public View {
        private:
            std::unique_ptr<Components::Text> headerTitle = nullptr;
            std::unique_ptr<Components::Text> messageDisplay = nullptr;
            std::unique_ptr<Components::ButtonText> buttonExit = nullptr;

            Rectangle header;
            Rectangle background;
            Rectangle mask;

            std::string message = "";

        public:
            /**
             * @brief Create an Pop-up window displaying an warning message to the user.
             * @param message is the message that will be displayed in the Pop-up.
             */
            WarningPopUp(const std::string message);

            /**
             * @brief Destroy the Warning Pop Up view.
             */
            virtual ~WarningPopUp();

            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Checks if the exit button was clicked.
             * 
             * @return Boolean that indicates if the exit button was clicked.
             */
            bool checkExit();
        
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
             * @brief Build background mask style.
             */
            void buildMask();

            /**
             * @brief Position background mask.
             */
            void positionMask();

            /**
             * @brief Render background mask.
             */
            void renderMask();

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
             * @brief Build header style.
             */
            void buildHeader();

            /**
             * @brief Position header.
             */
            void positionHeader();

            /**
             * @brief Render header.
             */
            void renderHeader();

            /**
             * @brief Build message style.
             */
            void buildMassageDisplay();

            /**
             * @brief Position message.
             */
            void positionMessageDisplay();

            /**
             * @brief Build exit button style.
             */
            void buildExitButton();

            /**
             * @brief Position exit button.
             */
            void positionExitButton();
    };
}


#endif
