#include <string>
#include <memory>

#include "raylib.h"

#include "TitleScreen.hpp"
#include "Screen.hpp"
#include "ScreenManager.hpp"
#include "ScoreScreen.hpp"

#include "Text.hpp"
#include "Image.hpp"
#include "ButtonText.hpp"

#include "GameManager.hpp"

#include "Colors.hpp"
#include "Constants.hpp"
#include "AssetsPaths.hpp"

#include "StyleFunctions.hpp"

#define DEFAULT_OPACITY 240

Screens::TitleScreen::TitleScreen() :
    titleFirstPart(new Components::Text()),
    titleSecondPart(new Components::Text()),
    buttonJogar(new Components::ButtonText()),
    buttonPlacar(new Components::ButtonText()),
    buttonSair(new Components::ButtonText()),
    backgroundImage(new Components::Image(Backgrounds::MAIN)) {
    buildBackgroundImage();

    buildTitle();

    buildJogarButton();
    buildPlacarButton();
    buildSairButton();    
}

Screens::TitleScreen::~TitleScreen() {}

void Screens::TitleScreen::renderScreen() {
    backgroundImage->render();

    renderTitle();

    buttonJogar->render();
    buttonPlacar->render();
    buttonSair->render();
    return;
}

void Screens::TitleScreen::handleEvents() {
    if(buttonJogar->checkClick()) {
        GameManager::getInstance()->startGame();
    }

    if(buttonPlacar->checkClick()) {
        std::shared_ptr<Screen> scoreScreen(new ScoreScreen());
        ScreenManager::getScreenManager()->loadScreen(scoreScreen);
    }

    if(buttonSair->checkClick()) {
        ScreenManager::getScreenManager()->closeWindow();
    }

    return;
}

#pragma region .: Styles :.

void Screens::TitleScreen::renderTitle() {
    Color backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = DEFAULT_OPACITY;

    DrawRectangleRec(titleBackground, backgroundColor);
    titleFirstPart->render();
    titleSecondPart->render();

    return;
}

void Screens::TitleScreen::buildBackgroundImage() {
    backgroundImage->setXPosition(0.0);
    backgroundImage->setYPosition(0.0);

    backgroundImage->setWidth(getDisplayWidth());
    backgroundImage->setHeight(getDisplayHeight());

    return;
}

void Screens::TitleScreen::buildTitle() {
    const std::string TITLE_FIRST_TEXT = "Briguinha";
    const std::string TITLE_SECOND_PART = "Naval";
    const float TITLE_FONT_SIZE = percentOf(9, getDisplayHeight());

    const float TITLE_MARGIN_TOP = percentOf(12, getDisplayHeight());
    const float BACKGROUND_MARGIN_TOP = percentOf(12, getDisplayHeight());

    titleFirstPart->setText(TITLE_FIRST_TEXT);
    titleFirstPart->setFontSize(TITLE_FONT_SIZE);

    titleSecondPart->setText(TITLE_SECOND_PART);
    titleSecondPart->setFontSize(TITLE_FONT_SIZE);

    titleBackground.width = getDisplayWidth();
    titleBackground.height = titleFirstPart->getHeight() + titleSecondPart->getHeight() + TITLE_MARGIN_TOP;
    titleBackground.x = 0.0;
    titleBackground.y = BACKGROUND_MARGIN_TOP;

    titleFirstPart->setXPosition((getDisplayWidth() - titleFirstPart->getWidth()) / 2);
    titleFirstPart->setYPosition(titleBackground.y + (titleBackground.height - titleFirstPart->getHeight() - titleSecondPart->getHeight()) / 2);

    titleSecondPart->setXPosition((getDisplayWidth() - titleSecondPart->getWidth()) / 2);
    titleSecondPart->setYPosition(titleFirstPart->getYPosition() + (titleBackground.height - titleSecondPart->getHeight()) / 2);

    return;
}

void Screens::TitleScreen::buildJogarButton() {
    const std::string LABEL = "Jogar!!";
    const float MARGIN_TOP = percentOf(21, getDisplayHeight());

    buttonJogar->setText(LABEL);

    Color backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = DEFAULT_OPACITY;

    Color backgroundHoverColor = DEFAULT_WHITE;
    backgroundHoverColor.a = DEFAULT_OPACITY;

    buttonJogar->setBackgroundColor(backgroundColor);
    buttonJogar->setMouseHoverBackgroundColor(backgroundHoverColor);

    buttonJogar->setTextColor(DEFAULT_WHITE);
    buttonJogar->setMouseHoverTextColor(DEFAULT_BALCK);
    buttonJogar->setFontSize(Components::Text::getDefaultFontSize());

    buttonJogar->setWidth(getDefaultButtonWidth());
    buttonJogar->setHeight(getDefaultButtonHeight());

    buttonJogar->setXPosition((getDisplayWidth() - buttonJogar->getWidth()) / 2);
    buttonJogar->setYPosition(titleBackground.y + titleBackground.height + MARGIN_TOP);

    return;
}

void Screens::TitleScreen::buildPlacarButton() {
    const std::string LABEL = "Placar";
    buttonPlacar->setText(LABEL);

    Color backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = DEFAULT_OPACITY;

    Color backgroundHoverColor = DEFAULT_WHITE;
    backgroundHoverColor.a = DEFAULT_OPACITY;

    buttonPlacar->setBackgroundColor(backgroundColor);
    buttonPlacar->setMouseHoverBackgroundColor(backgroundHoverColor);

    buttonPlacar->setTextColor(DEFAULT_WHITE);
    buttonPlacar->setMouseHoverTextColor(DEFAULT_BALCK);
    buttonPlacar->setFontSize(Components::Text::getDefaultFontSize());

    buttonPlacar->setWidth(getDefaultButtonWidth() - getReducedButtonWidth());
    buttonPlacar->setHeight(getDefaultButtonHeight());

    buttonPlacar->setXPosition((getDisplayWidth() - buttonPlacar->getWidth()) / 2);
    buttonPlacar->setYPosition(buttonJogar->getYPosition() + buttonJogar->getHeight() + getButtonMarginBotton());

    return;
}

void Screens::TitleScreen::buildSairButton() {
    const std::string LABEL = "Sair";
    buttonSair->setText(LABEL);

    Color backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = DEFAULT_OPACITY;

    Color backgroundHoverColor = DEFAULT_WHITE;
    backgroundHoverColor.a = DEFAULT_OPACITY;

    buttonSair->setBackgroundColor(backgroundColor);
    buttonSair->setMouseHoverBackgroundColor(backgroundHoverColor);

    buttonSair->setTextColor(DEFAULT_WHITE);
    buttonSair->setMouseHoverTextColor(DEFAULT_BALCK);
    buttonSair->setFontSize(Components::Text::getDefaultFontSize());

    buttonSair->setWidth(getDefaultButtonWidth() - (2.1 * getReducedButtonWidth()));
    buttonSair->setHeight(getDefaultButtonHeight());

    buttonSair->setXPosition((getDisplayWidth() - buttonSair->getWidth()) / 2);
    buttonSair->setYPosition(buttonPlacar->getYPosition() + buttonPlacar->getHeight() + getButtonMarginBotton());
    
    return;
}

float Screens::TitleScreen::getDefaultButtonWidth() const {
    return percentOf(18, getDisplayWidth());
}

float Screens::TitleScreen::getDefaultButtonHeight() const {
    return percentOf(6, getDisplayHeight());
}

float Screens::TitleScreen::getButtonMarginBotton() const {
    return percentOf(2.1, getDisplayHeight());
}

float Screens::TitleScreen::getReducedButtonWidth() const {
    return percentOf(1.2, getDisplayWidth());
}

#pragma endregion
