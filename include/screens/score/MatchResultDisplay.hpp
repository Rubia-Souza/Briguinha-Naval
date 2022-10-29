#ifndef MATCH_RESULT_DISPLAY_HPP
#define MATCH_RESULT_DISPLAY_HPP

#include <memory>
#include "raylib.h"

#include "View.hpp"
#include "Text.hpp"

#include "MatchResults.hpp"

#include "PlayerRegistredScore.hpp"

namespace Views {
    class MatchResultDisplay : public View {
        private:
            std::unique_ptr<Components::Text> title = nullptr;
            std::unique_ptr<Components::Text> matchDateTime = nullptr;

            std::unique_ptr<PlayerRegistredScore> player1RegistredScore = nullptr;
            std::unique_ptr<PlayerRegistredScore> player2RegistredScore = nullptr;

            Rectangle leftDivisionLine;
            Rectangle rightDivisionLine;
            MatchResults matchResult;

        public:
            /**
             * @brief Create the section that displays a complete match results.
             */
            MatchResultDisplay();

            /**
             * @brief Destroy the Match Result Display view.
             */
            virtual ~MatchResultDisplay();
            
            /**
             * @brief Render the view in the interface.
             */
            virtual void render() override;

            /**
             * @brief Update the view values based on the matchResults.
             * 
             * @param matchResult is the results of the mach that will be displayed on the view.
             */
            void update(const MatchResults matchResult);
        
            /**
             * @brief Get the match results attribute.
             * 
             * @return Match results attribute copy.
             */
            MatchResults getMatchResult() const;

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
             * @brief Build title style.
             */
            void buildTitle();

            /**
             * @brief Position title.
             */
            void positionTitle();

            /**
             * @brief Render title.
             */
            void renderTitle();

            /**
             * @brief Build date and time from title style.
             */
            void buildMatchDateTime();

            /**
             * @brief Build left and right division lines.
             */
            void buildDivisionLines();
            
            /**
             * @brief Position player registred scores.
             */
            void positionScores();

            /**
             * @brief Get title font size value.
             * 
             * @return Title font size value.
             */
            float getTitleFontSize() const;

            /**
             * @brief Set the matchResults attribute.
             * 
             * @param matchResult is the new value to the attribute.
             */
            void setMatchResult(const MatchResults matchResult);
    };
}

#endif
