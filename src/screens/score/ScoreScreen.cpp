#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "raylib.h"

#include "ScoreScreen.hpp"
#include "ScreenManager.hpp"
#include "TitleScreen.hpp"

#include "Text.hpp"
#include "Image.hpp"
#include "ButtonText.hpp"
#include "ButtonIcon.hpp"

#include "MatchResultDisplay.hpp"

#include "MatchResults.hpp"
#include "TxtReader.hpp"

#include "StyleFunctions.hpp"
#include "AssetsPaths.hpp"
#include "Constants.hpp"
#include "Colors.hpp"

Screens::ScoreScreen::ScoreScreen() :
    backgroundImage(new Components::Image(Backgrounds::MAIN)),
    title(new Components::Text()),
    matchsResultDisplay(new Views::MatchResultDisplay()),
    buttonNext(new Components::ButtonIcon(Icons::RIGHT_ARROW_BLACK)),
    buttonPrevius(new Components::ButtonIcon(Icons::LEFT_ARROW_BLACK)),
    buttonVoltar(new Components::ButtonText()),
    emptyScoreRegisterText(new Components::Text()) {
    loadMatchResults();
    if(matchsResults.size() != 0) {
        matchsResultDisplay->update(matchsResults[0]);
    }

    buildBackground();
    buildTitle();

    buildEmptyScoreRegistrText();

    buildMatchsResultsDisplays();
    buildButtonsNextPrevius();

    buildButtonVoltar();
}

Screens::ScoreScreen::~ScoreScreen() {}

void Screens::ScoreScreen::renderScreen() {
    renderBackground();

    title->render();

    if(matchsResults.size() == 0) {
        emptyScoreRegisterText->render();
    }
    else {
        matchsResultDisplay->render();
        buttonNext->render();
        buttonPrevius->render();
    }

    buttonVoltar->render();

    return;
}

void Screens::ScoreScreen::handleEvents() {
    if(buttonVoltar->checkClick()) {
        std::shared_ptr<Screen> titleScreen(new TitleScreen());
        ScreenManager::getScreenManager()->loadScreen(titleScreen);
    }

    if(matchsResults.size() == 0) {
        return;
    }
    
    if(buttonNext->checkClick()) {
        handleButtonNextClick();
    }

    if(buttonPrevius->checkClick()) {
        handleButtonPreviusClick();
    }

    return;
}

void Screens::ScoreScreen::loadMatchResults() {
    try {
        std::unique_ptr<TxtReader> reader(new TxtReader(SCORE_SAVE_FILE_NAME));
        matchsResults = reader->getMatches();
    }
    catch(std::invalid_argument& exception) {
        matchsResults.clear();
    }

    return;    
}

void Screens::ScoreScreen::handleButtonNextClick() {
    actualMatchIndex++;
    
    if(actualMatchIndex >= matchsResults.size()) {
        actualMatchIndex = 0;
    }

    matchsResultDisplay->update(matchsResults[actualMatchIndex]);
    return;
}

void Screens::ScoreScreen::handleButtonPreviusClick() {
    if(actualMatchIndex == 0) {
        actualMatchIndex = matchsResults.size() - 1;
    }
    else {
        actualMatchIndex--;
    }

    matchsResultDisplay->update(matchsResults[actualMatchIndex]);
    return;
}

#pragma region .: Styles :.

void Screens::ScoreScreen::renderBackground() {
    Color backgroundColor = DEFAULT_BALCK;
    backgroundColor.a = 240;

    backgroundImage->render();
    DrawRectangleRec(background, backgroundColor);

    return;
}

void Screens::ScoreScreen::buildBackground() {
    backgroundImage->setXPosition(0.0);
    backgroundImage->setYPosition(0.0);

    backgroundImage->setWidth(getDisplayWidth());
    backgroundImage->setHeight(getDisplayHeight());

    background.height = getDisplayHeight();
    background.width = percentOf(54, getDisplayWidth());

    background.y = 0;
    background.x = (getDisplayWidth() - background.width) / 2;

    return;
}

void Screens::ScoreScreen::buildTitle() {
    const std::string LABEL = "Placar";
    const float MARGIN_TOP = percentOf(6.6, getDisplayHeight());

    title->setText(LABEL);
    title->setFontSize(Components::Text::getDefaultTitleSize());
    title->setXPosition((getDisplayWidth() - title->getWidth()) / 2);
    title->setYPosition(MARGIN_TOP);
    
    return;
}

void Screens::ScoreScreen::buildMatchsResultsDisplays() {
    const float MARGIN_TOP = percentOf(9, getDisplayHeight());

    matchsResultDisplay->setXPosition(title->getXPosition() + (title->getWidth() - matchsResultDisplay->getWidth()) / 2);
    matchsResultDisplay->setYPosition(title->getYPosition() + title->getHeight() + MARGIN_TOP);

    return;
}

void Screens::ScoreScreen::buildButtonsNextPrevius() {
    const float BUTTON_SIZE = percentOf(4.8, getDisplayHeight());
    const float ICON_SIZE = percentOf(4.2, getDisplayHeight());
    const float BUTTON_NEXT_MARGIN_RIGHT = percentOf(4.2, getDisplayWidth());
    const float BUTTON_NEXT_MARGIN_TOP = percentOf(2.7, getDisplayHeight());
    const float BUTTON_PREVIUS_MARGIN_RIGHT = percentOf(1.5, getDisplayWidth());

    buttonNext->setBackgroundColor(DEFAULT_WHITE);
    buttonPrevius->setBackgroundColor(DEFAULT_WHITE);

    buttonNext->setMouseHoverBackgroundColor(LIGHT_GRAY);
    buttonPrevius->setMouseHoverBackgroundColor(LIGHT_GRAY);

    buttonNext->setHeight(BUTTON_SIZE);
    buttonNext->setIconHeight(ICON_SIZE);
    buttonNext->setWidth(BUTTON_SIZE);
    buttonNext->setIconWidth(ICON_SIZE);

    buttonPrevius->setHeight(BUTTON_SIZE);
    buttonPrevius->setIconHeight(ICON_SIZE);
    buttonPrevius->setWidth(BUTTON_SIZE);
    buttonPrevius->setIconWidth(ICON_SIZE);

    buttonNext->setXPosition(background.x + background.width - buttonNext->getWidth() - BUTTON_NEXT_MARGIN_RIGHT);
    buttonNext->setYPosition(matchsResultDisplay->getYPosition() + matchsResultDisplay->getHeight() + BUTTON_NEXT_MARGIN_TOP);

    buttonPrevius->setXPosition(buttonNext->getXPosition() - buttonPrevius->getWidth() - BUTTON_PREVIUS_MARGIN_RIGHT);
    buttonPrevius->setYPosition(buttonNext->getYPosition());

    return;
}

void Screens::ScoreScreen::buildButtonVoltar() {
    const std::string LABEL = "Voltar";
    const float BUTTON_VOLTAR_MARGIN_BOTTOM = percentOf(3, getDisplayWidth());

    buttonVoltar->setText(LABEL);
    buttonVoltar->setFontSize(Components::Text::getDefaultFontSize());
    buttonVoltar->setTextColor(DEFAULT_BALCK);

    buttonVoltar->setWidth(percentOf(12, getDisplayWidth()));
    buttonVoltar->setHeight(percentOf(6.6, getDisplayHeight()));

    buttonVoltar->setXPosition(background.x + (background.width - buttonVoltar->getWidth()) / 2);
    buttonVoltar->setYPosition(getDisplayHeight() - buttonVoltar->getHeight() - BUTTON_VOLTAR_MARGIN_BOTTOM);

    buttonVoltar->setBackgroundColor(DEFAULT_WHITE);
    buttonVoltar->setMouseHoverTextColor(DEFAULT_BALCK);
    buttonVoltar->setMouseHoverBackgroundColor(LIGHT_GRAY);

    return;
}

void Screens::ScoreScreen::buildEmptyScoreRegistrText() {
    const std::string LABEL = "Nao ha nenhum registro de jogos";

    emptyScoreRegisterText->setText(LABEL);
    emptyScoreRegisterText->setFontSize(Components::Text::getDefaultFontSize());
    emptyScoreRegisterText->setTextColor(DEFAULT_WHITE);

    emptyScoreRegisterText->setXPosition(background.x + (background.width - emptyScoreRegisterText->getWidth()) / 2);
    emptyScoreRegisterText->setYPosition(background.y + (background.height - emptyScoreRegisterText->getHeight()) / 2);

    return;
}

#pragma endregion
