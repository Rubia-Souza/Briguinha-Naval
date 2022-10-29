#include <string>
#include <vector>
#include <memory>

#include "PlayerRegistredScore.hpp"

#include "Screen.hpp"

#include "Text.hpp"

#include "StyleFunctions.hpp"
#include "ScoreFormatter.hpp"

Views::PlayerRegistredScore::PlayerRegistredScore() : playerNameLabel(new Components::Text()) {
    scoreLabels.push_back(std::unique_ptr<Components::Text>(new Components::Text()));
    scoreLabels.push_back(std::unique_ptr<Components::Text>(new Components::Text()));
    scoreLabels.push_back(std::unique_ptr<Components::Text>(new Components::Text()));

    setXPosition(0.0);
    setYPosition(0.0);

    findHeight();
    findWidth();
}

Views::PlayerRegistredScore::~PlayerRegistredScore() {}

void Views::PlayerRegistredScore::render() {
    playerNameLabel->render();

    for(auto&& scoreLabel : scoreLabels) {
        scoreLabel->render();
    }

    return;
}

#pragma region .: Styles :.

void Views::PlayerRegistredScore::update(const std::string playerName, const Score playerScore) {
    const std::string LABEL_NAVIOS_DESTRUIDOS = "*Navios Destruidos:";
    const std::string LABEL_NAVIOS_RESTANTES = "*Navios Restantes:";
    const std::string LABEL_PRECISAO = "*Precisao:";

    setPlayerName(playerName);
    playerNameLabel->setText(playerName);
    definePlayerNameTextSize();

    setPlayerScore(playerScore);
    scoreLabels[0]->setText(ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_DESTRUIDOS, getPlayerScore().getDestroyedTroops()));
    scoreLabels[1]->setText(ScoreFormatter::buildLabelWithValue(LABEL_NAVIOS_RESTANTES, getPlayerScore().getRemainingTroops()));
    scoreLabels[2]->setText(ScoreFormatter::buildProportionLabel(LABEL_PRECISAO, getPlayerScore().getHitShoots(), getPlayerScore().getTotalAmountShoots()));
    defineScoreLabelsTextSize();

    findWidth();
    findHeight();

    return;
}

void Views::PlayerRegistredScore::updateInnerComponentsPositions() {
    positionPlayerNameLabel();
    positionPlayerScoreLabels();

    return;
}

void Views::PlayerRegistredScore::positionPlayerNameLabel() {
    playerNameLabel->setXPosition(getXPosition());
    playerNameLabel->setYPosition(getYPosition());
    
    return;
}

void Views::PlayerRegistredScore::definePlayerNameTextSize() {
    playerNameLabel->setFontSize(Components::Text::getDefaultFontSize());

    return;
}

void Views::PlayerRegistredScore::positionPlayerScoreLabels() {
    const float LABEL_MARGIN_TOP = percentOf(4.2, Screens::Screen::getDisplayHeight());

    scoreLabels[0]->setXPosition(playerNameLabel->getXPosition() + getLabelMarginLeft());
    scoreLabels[0]->setYPosition(playerNameLabel->getYPosition() + LABEL_MARGIN_TOP);

    for(unsigned int i = 1; i < scoreLabels.size(); i++) {
        scoreLabels[i]->setXPosition(scoreLabels[i-1]->getXPosition());
        scoreLabels[i]->setYPosition(scoreLabels[i-1]->getYPosition() + LABEL_MARGIN_TOP);
    }
    
    return;
}

void Views::PlayerRegistredScore::defineScoreLabelsTextSize() {
    for(auto&& scoreLabel : scoreLabels) {
        scoreLabel->setFontSize(Components::Text::getDefaultFontSize());
    }

    return;
}

void Views::PlayerRegistredScore::findWidth() {
    float heighestWidth = playerNameLabel->getWidth();

    for(auto&& scoreLabel : scoreLabels) {
        float labelWidth = getLabelMarginLeft() + scoreLabel->getWidth();

        if(labelWidth > heighestWidth) {
            heighestWidth = labelWidth;
        }
    }

    width = heighestWidth;
    return;
}

void Views::PlayerRegistredScore::findHeight() {
    height = abs(playerNameLabel->getYPosition() - scoreLabels[scoreLabels.size() - 1]->getYPosition()) + scoreLabels[scoreLabels.size() - 1]->getHeight();
    return;
}

float Views::PlayerRegistredScore::getLabelMarginLeft() const {
    return percentOf(1.5, Screens::Screen::getDisplayHeight());
}

#pragma endregion

#pragma region .: Gets-Sets :.

void Views::PlayerRegistredScore::setPlayerName(const std::string playerName) {
    this->playerName = playerName;
    return;
}

std::string Views::PlayerRegistredScore::getPlayerName() const {
    return playerName;
}

void Views::PlayerRegistredScore::setPlayerScore(const Score playerScore) {
    this->playerScore = playerScore;
    return;
}

Score Views::PlayerRegistredScore::getPlayerScore() const {
    return playerScore;
}

#pragma endregion
