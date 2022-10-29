#include <string>
#include <vector>
#include <memory>
#include "raylib.h"

#include "GameScoreDisplay.hpp"

#include "Screen.hpp"
#include "TextIcon.hpp"

#include "Score.hpp"

#include "StyleFunctions.hpp"
#include "ScoreFormatter.hpp"

#include "AssetsPaths.hpp"
#include "Colors.hpp"

const std::string LABEL_NAVIOS_DESTRUIDOS = "Navios Destruidos:";
const std::string LABEL_NAVIOS_RESTANTES = "Navios Restantes:";
const std::string LABEL_NAVIOS_PERDIDOS = "Navios Perdidos:";

Views::GameScoreDisplay::GameScoreDisplay(const std::shared_ptr<Score> score) {
    setPlayerScore(score);

    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::EXPLOSION, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_DESTRUIDOS, getPlayerScore().getDestroyedTroops()))));
    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::HEART, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_RESTANTES, getPlayerScore().getRemainingTroops()))));
    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::SKULL, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_PERDIDOS, getPlayerScore().getLostTroops()))));
    defineLabelsSizes();

    setXPosition(0.0);
    setYPosition(0.0);

    findWidth();
    findHeight();
}

Views::GameScoreDisplay::~GameScoreDisplay() {}

void Views::GameScoreDisplay::render() {
    for(auto&& label : labels) {
        label->render();
    }
    
    return;
}

#pragma region .: Styles :.

void Views::GameScoreDisplay::updateInnerComponentsPositions() {
    poisitionLabels();

    return;
}

void Views::GameScoreDisplay::findWidth() {
    float highestWidth = 0.0;

    for(auto&& label : labels) {
        if(highestWidth < label->getWidth()) {
            highestWidth = label->getWidth();
        }
    }

    width = highestWidth;
    return;
}

void Views::GameScoreDisplay::findHeight() {
    if(labels.size() <= 0) {
        return;
    }

    height = abs(labels[labels.size()-1]->getYPosition() - labels[0]->getYPosition() + labels[labels.size()-1]->getHeight());
    return;
}

void Views::GameScoreDisplay::defineLabelsSizes() {
    const float ICON_SIZE = percentOf(4.2, Screens::Screen::getDisplayHeight());

    for(auto&& label : labels) {
        label->setFontSize(Components::Text::getDefaultFontSize());
        label->setTextColor(DEFAULT_BALCK);

        label->setIconWidth(ICON_SIZE);
        label->setIconHeight(ICON_SIZE);
    }

    return;
}

void Views::GameScoreDisplay::poisitionLabels() {
    if(labels.size() <= 0) {
        return;
    }

    const float LABEL_MARGIN_BOTTOM = percentOf(2.7, Screens::Screen::getDisplayHeight());

    labels[0]->setXPosition(getXPosition());
    labels[0]->setYPosition(getYPosition());

    for(unsigned int i = 1; i < labels.size(); i++) {
        labels[i]->setXPosition(labels[i-1]->getXPosition());
        labels[i]->setYPosition(labels[i-1]->getYPosition() + labels[i-1]->getHeight() + LABEL_MARGIN_BOTTOM);
    }

    return;
}

void Views::GameScoreDisplay::updateLabels() {
    labels[0]->setText(ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_DESTRUIDOS, getPlayerScore().getDestroyedTroops()));
    labels[1]->setText(ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_RESTANTES, getPlayerScore().getRemainingTroops()));
    labels[2]->setText(ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_PERDIDOS, getPlayerScore().getLostTroops()));

    return;
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::GameScoreDisplay::setPlayerScore(const std::shared_ptr<Score> score) {
    playerScore = score;
    return;
}

Score Views::GameScoreDisplay::getPlayerScore() const {
    return *playerScore;
}

#pragma endregion
