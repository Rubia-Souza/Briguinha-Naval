#include <string>
#include <vector>
#include <memory>
#include "raylib.h"

#include "EndGameScoreDisplay.hpp"

#include "Screen.hpp"
#include "TextIcon.hpp"

#include "Score.hpp"

#include "StyleFunctions.hpp"
#include "ScoreFormatter.hpp"
#include "AssetsPaths.hpp"

Views::EndGameScoreDisplay::EndGameScoreDisplay(const Score score) {
    const std::string LABEL_NAVIOS_DESTRUIDOS = "Navios Destruidos:";
    const std::string LABEL_NAVIOS_RESTANTES = "Navios Restantes:";
    const std::string LABEL_NAVIOS_PERDIDOS = "Navios Perdidos:";
    const std::string LABEL_PRECISAO = "Precisao:";

    setPlayerScore(score);

    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::EXPLOSION, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_DESTRUIDOS, getPlayerScore().getDestroyedTroops()))));
    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::HEART, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_RESTANTES, getPlayerScore().getRemainingTroops()))));
    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::SKULL, ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_PERDIDOS, getPlayerScore().getLostTroops()))));
    labels.push_back(std::shared_ptr<Components::TextIcon>(new Components::TextIcon(Icons::AIM, ScoreFormatter::buildProportionLabel(LABEL_PRECISAO, getPlayerScore().getHitShoots(), getPlayerScore().getTotalAmountShoots()))));
    defineLabelsSizes();

    setXPosition(0.0);
    setYPosition(0.0);

    findWidth();
    findHeight();
}

Views::EndGameScoreDisplay::~EndGameScoreDisplay() {}

void Views::EndGameScoreDisplay::render() {
    for(auto&& label : labels) {
        label->render();
    }
    
    return;
}

#pragma region .: Styles :.

void Views::EndGameScoreDisplay::updateInnerComponentsPositions() {
    poisitionLabels();

    return;
}

void Views::EndGameScoreDisplay::findWidth() {
    float highestWidth = 0.0;

    for(auto&& label : labels) {
        if(highestWidth < label->getWidth()) {
            highestWidth = label->getWidth();
        }
    }

    width = highestWidth;
    return;
}

void Views::EndGameScoreDisplay::findHeight() {
    if(labels.size() <= 0) {
        return;
    }

    height = abs(labels[labels.size()-1]->getYPosition() - labels[0]->getYPosition() + labels[labels.size()-1]->getHeight());
    return;
}

void Views::EndGameScoreDisplay::defineLabelsSizes() {
    const float ICON_SIZE = percentOf(5.1, Screens::Screen::getDisplayHeight());

    for(auto&& label : labels) {
        label->setFontSize(Components::Text::getDefaultFontSize());

        label->setIconWidth(ICON_SIZE);
        label->setIconHeight(ICON_SIZE);
    }

    return;
}

void Views::EndGameScoreDisplay::poisitionLabels() {
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

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::EndGameScoreDisplay::setPlayerScore(const Score score) {
    playerScore = score;
    return;
}

Score Views::EndGameScoreDisplay::getPlayerScore() const {
    return playerScore;
}

#pragma endregion
