# Define configurações do projeto
PROJECT_NAME = BriguinhaNaval

# Define pastas do projeto
EXTERNAL_LIBS_FOLDER = ./include/libs
SRC_FOLDER = ./src
BUILD_FOLDER = ./build
INCLUDE_PATH = ./include

# Define pastas do Raylib
RAYLIB_LIB = ${SRC_FOLDER}/libs
RAYLIB_INCLUDES = ${EXTERNAL_LIBS_FOLDER}

RAYLIB_LINUX_LIB = ${RAYLIB_LIB}/linux
RAYLIB_WINDOWS_LIB = ${RAYLIB_LIB}/windows

# Define o compilador
COMPILER = g++

LINUX_BUILD_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lgcov
WINDOWS_BUILD_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm -lstdc++ -lgcov
COMMON_FLAGS = -std=c++11 -Wall -Wno-unknown-pragmas

BUILD_EXCEPTIONS = ${BUILD_FOLDER}/CustomException.o ${BUILD_FOLDER}/InvalidPositionException.o
BUILD_CLASSES = ${BUILD_FOLDER}/Score.o ${BUILD_FOLDER}/MatchResults.o ${BUILD_FOLDER}/Point.o ${BUILD_FOLDER}/Position.o ${BUILD_FOLDER}/Troop.o ${BUILD_FOLDER}/Submarine.o ${BUILD_FOLDER}/Crusier.o ${BUILD_FOLDER}/Battleship.o ${BUILD_FOLDER}/Match.o ${BUILD_FOLDER}/Board.o ${BUILD_FOLDER}/Player.o ${BUILD_FOLDER}/GameParameters.o ${BUILD_FOLDER}/GameManager.o ${BUILD_FOLDER}/FileHandler.o ${BUILD_FOLDER}/TxtWriter.o ${BUILD_FOLDER}/TxtReader.o
BUILD_UTILS = ${BUILD_FOLDER}/StyleFunctions.o ${BUILD_FOLDER}/ScoreFormatter.o
BUILD_COMPONENTS = ${BUILD_FOLDER}/Component.o ${BUILD_FOLDER}/IClickable.o ${BUILD_FOLDER}/View.o ${BUILD_FOLDER}/ResizableComponent.o ${BUILD_FOLDER}/Image.o ${BUILD_FOLDER}/Text.o ${BUILD_FOLDER}/TextIcon.o ${BUILD_FOLDER}/Button.o ${BUILD_FOLDER}/ButtonText.o ${BUILD_FOLDER}/ButtonIcon.o ${BUILD_FOLDER}/ButtonTextIcon.o
BUILD_VIEWS = ${BUILD_FOLDER}/BoardDisplay.o ${BUILD_FOLDER}/PositionDisplay.o ${BUILD_FOLDER}/AssetsLoader.o

BUILD_SCORE_SCREEN = ${BUILD_FOLDER}/ScoreScreen.o ${BUILD_FOLDER}/MatchResultDisplay.o ${BUILD_FOLDER}/PlayerRegistredScore.o
BUILD_POSITIONING_SCREEN = ${BUILD_FOLDER}/PositioningScreen.o ${BUILD_FOLDER}/PositioningBoardDisplay.o ${BUILD_FOLDER}/PositioningPositionDisplay.o ${BUILD_FOLDER}/TroopPositioningOption.o ${BUILD_FOLDER}/TroopDisplay.o ${BUILD_FOLDER}/SubmarineDisplay.o ${BUILD_FOLDER}/CrusierDisplay.o ${BUILD_FOLDER}/BattleshipDisplay.o ${BUILD_FOLDER}/WarningPopUp.o
BUILD_GAME_SCREEN = ${BUILD_FOLDER}/GamePositionDisplay.o ${BUILD_FOLDER}/GameBoardDisplay.o ${BUILD_FOLDER}/GameScoreDisplay.o ${BUILD_FOLDER}/GameScreen.o
BUILD_END_GAME_SCREEN = ${BUILD_FOLDER}/EndGameScoreDisplay.o ${BUILD_FOLDER}/EndGameScreen.o

BUILD_SCREENS = ${BUILD_FOLDER}/ScreenManager.o ${BUILD_FOLDER}/Screen.o ${BUILD_FOLDER}/TitleScreen.o ${BUILD_SCORE_SCREEN} ${BUILD_POSITIONING_SCREEN} ${BUILD_GAME_SCREEN} ${BUILD_END_GAME_SCREEN}

BUILD_FILES = ${BUILD_EXCEPTIONS} ${BUILD_CLASSES} ${BUILD_UTILS} ${BUILD_COMPONENTS} ${BUILD_VIEWS} ${BUILD_SCREENS}

# Definindo includes de logica
LOGIC_INCLUDE_FOLDER = ./include/logic
LBOARD_I = ${LOGIC_INCLUDE_FOLDER}/board
LEXCEPTIONS_I = ${LOGIC_INCLUDE_FOLDER}/exceptions
LFILEHANDLER_I = ${LOGIC_INCLUDE_FOLDER}/fileHandler
LGAME_I = ${LOGIC_INCLUDE_FOLDER}/game
LMATCH_I = ${LOGIC_INCLUDE_FOLDER}/match
LUTILS_I = ${LOGIC_INCLUDE_FOLDER}/utils

LOGIC_INCLUDE_ALL = -I ${LBOARD_I} -I ${LEXCEPTIONS_I} -I ${LFILEHANDLER_I} -I ${LGAME_I} -I ${LMATCH_I} -I ${LUTILS_I}

#Definindo includes da parte grafica
SCREENS_INCLUDE_FOLDER = ./include/screens
COMPONENTS_FOLDER = ${SCREENS_INCLUDE_FOLDER}/components
SBUTTON_I = ${COMPONENTS_FOLDER}/button
SCOMPONENT_I = ${COMPONENTS_FOLDER}/component
SIMAGE_I = ${COMPONENTS_FOLDER}/image
STEXT_I = ${COMPONENTS_FOLDER}/text
SVIEW_I = ${COMPONENTS_FOLDER}/view
SENDGAME_I = ${SCREENS_INCLUDE_FOLDER}/endGame
SGAME_I = ${SCREENS_INCLUDE_FOLDER}/game
SPOSITIONING_I = ${SCREENS_INCLUDE_FOLDER}/positioning
SSCORE_I = ${SCREENS_INCLUDE_FOLDER}/score
SSCREEN_I = ${SCREENS_INCLUDE_FOLDER}/screen
SSHARED_I = ${SCREENS_INCLUDE_FOLDER}/shared
STITLE_I = ${SCREENS_INCLUDE_FOLDER}/title

SCREENS_INCLUDE_ALL = -I ${SBUTTON_I} -I ${SCOMPONENT_I} -I ${SIMAGE_I} -I ${STEXT_I} -I ${SVIEW_I} -I ${SENDGAME_I} -I ${SGAME_I} -I ${SPOSITIONING_I} -I ${SSCORE_I} -I ${SSCREEN_I} -I ${SSHARED_I} -I ${STITLE_I}

INCLUDES = -I ${RAYLIB_INCLUDES} ${LOGIC_INCLUDE_ALL} ${SCREENS_INCLUDE_ALL}

# Builda projeto
linux_build_${PROJECT_NAME}: ${BUILD_FILES} ${BUILD_FOLDER}/main.o
	${COMPILER} ${BUILD_FILES} ${BUILD_FOLDER}/main.o -L ${RAYLIB_LINUX_LIB} -o ${PROJECT_NAME} ${COMMON_FLAGS} ${LINUX_BUILD_FLAGS}

windows_build_${PROJECT_NAME}: ${BUILD_FILES} ${BUILD_FOLDER}/main.o
	${COMPILER} ${BUILD_FILES} ${BUILD_FOLDER}/main.o -L ${RAYLIB_WINDOWS_LIB} -o ${PROJECT_NAME} ${COMMON_FLAGS} ${WINDOWS_BUILD_FLAGS}

${BUILD_FOLDER}/main.o: ${SRC_FOLDER}/main.cpp
	${COMPILER} ${INCLUDES} -c ${SRC_FOLDER}/main.cpp -o ${BUILD_FOLDER}/main.o ${COMMON_FLAGS}

# Builda telas
END_GAME_DISPLAY_FOLDER = ${SRC_FOLDER}/screens/endGame

${BUILD_FOLDER}/EndGameScoreDisplay.o: ${SENDGAME_I}/EndGameScoreDisplay.hpp ${END_GAME_DISPLAY_FOLDER}/EndGameScoreDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${END_GAME_DISPLAY_FOLDER}/EndGameScoreDisplay.cpp -o ${BUILD_FOLDER}/EndGameScoreDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/EndGameScreen.o: ${SENDGAME_I}/EndGameScreen.hpp ${END_GAME_DISPLAY_FOLDER}/EndGameScreen.cpp
	${COMPILER} ${INCLUDES} -c ${END_GAME_DISPLAY_FOLDER}/EndGameScreen.cpp -o ${BUILD_FOLDER}/EndGameScreen.o ${COMMON_FLAGS}

GAME_DISPLAY_FOLDER = ${SRC_FOLDER}/screens/game

${BUILD_FOLDER}/GameBoardDisplay.o: ${SGAME_I}/GameBoardDisplay.hpp ${GAME_DISPLAY_FOLDER}/GameBoardDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_DISPLAY_FOLDER}/GameBoardDisplay.cpp -o ${BUILD_FOLDER}/GameBoardDisplay.o ${COMMON_FLAGS}	

${BUILD_FOLDER}/GamePositionDisplay.o: ${SGAME_I}/GamePositionDisplay.hpp ${GAME_DISPLAY_FOLDER}/GamePositionDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_DISPLAY_FOLDER}/GamePositionDisplay.cpp -o ${BUILD_FOLDER}/GamePositionDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/GameScoreDisplay.o: ${SGAME_I}/GameScoreDisplay.hpp ${GAME_DISPLAY_FOLDER}/GameScoreDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_DISPLAY_FOLDER}/GameScoreDisplay.cpp -o ${BUILD_FOLDER}/GameScoreDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/GameScreen.o: ${SGAME_I}/GameScreen.hpp ${GAME_DISPLAY_FOLDER}/GameScreen.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_DISPLAY_FOLDER}/GameScreen.cpp -o ${BUILD_FOLDER}/GameScreen.o ${COMMON_FLAGS}

POSITIONING_DISPLAY_FOLDER = ${SRC_FOLDER}/screens/positioning

${BUILD_FOLDER}/BattleshipDisplay.o: ${SPOSITIONING_I}/BattleshipDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/BattleshipDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/BattleshipDisplay.cpp -o ${BUILD_FOLDER}/BattleshipDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/CrusierDisplay.o: ${SPOSITIONING_I}/CrusierDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/CrusierDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/CrusierDisplay.cpp -o ${BUILD_FOLDER}/CrusierDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/PositioningBoardDisplay.o: ${SPOSITIONING_I}/PositioningBoardDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/PositioningBoardDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/PositioningBoardDisplay.cpp -o ${BUILD_FOLDER}/PositioningBoardDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/PositioningPositionDisplay.o: ${SPOSITIONING_I}/PositioningPositionDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/PositioningPositionDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/PositioningPositionDisplay.cpp -o ${BUILD_FOLDER}/PositioningPositionDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/PositioningScreen.o: ${SPOSITIONING_I}/PositioningScreen.hpp ${POSITIONING_DISPLAY_FOLDER}/PositioningScreen.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/PositioningScreen.cpp -o ${BUILD_FOLDER}/PositioningScreen.o ${COMMON_FLAGS}

${BUILD_FOLDER}/SubmarineDisplay.o: ${SPOSITIONING_I}/SubmarineDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/SubmarineDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/SubmarineDisplay.cpp -o ${BUILD_FOLDER}/SubmarineDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/TroopDisplay.o: ${SPOSITIONING_I}/TroopDisplay.hpp ${POSITIONING_DISPLAY_FOLDER}/TroopDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/TroopDisplay.cpp -o ${BUILD_FOLDER}/TroopDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/TroopPositioningOption.o: ${SPOSITIONING_I}/TroopPositioningOption.hpp ${POSITIONING_DISPLAY_FOLDER}/TroopPositioningOption.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/TroopPositioningOption.cpp -o ${BUILD_FOLDER}/TroopPositioningOption.o ${COMMON_FLAGS}

${BUILD_FOLDER}/WarningPopUp.o: ${SPOSITIONING_I}/WarningPopUp.hpp ${POSITIONING_DISPLAY_FOLDER}/WarningPopUp.cpp
	${COMPILER} ${INCLUDES} -c ${POSITIONING_DISPLAY_FOLDER}/WarningPopUp.cpp -o ${BUILD_FOLDER}/WarningPopUp.o ${COMMON_FLAGS}

SCORE_DISPLAY_FOLDER = ${SRC_FOLDER}/screens/score

${BUILD_FOLDER}/MatchResultDisplay.o: ${SSCORE_I}/MatchResultDisplay.hpp ${SCORE_DISPLAY_FOLDER}/MatchResultDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${SCORE_DISPLAY_FOLDER}/MatchResultDisplay.cpp -o ${BUILD_FOLDER}/MatchResultDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/PlayerRegistredScore.o: ${SSCORE_I}/PlayerRegistredScore.hpp ${SCORE_DISPLAY_FOLDER}/PlayerRegistredScore.cpp
	${COMPILER} ${INCLUDES} -c ${SCORE_DISPLAY_FOLDER}/PlayerRegistredScore.cpp -o ${BUILD_FOLDER}/PlayerRegistredScore.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ScoreScreen.o: ${SSCORE_I}/ScoreScreen.hpp ${SCORE_DISPLAY_FOLDER}/ScoreScreen.cpp
	${COMPILER} ${INCLUDES} -c ${SCORE_DISPLAY_FOLDER}/ScoreScreen.cpp -o ${BUILD_FOLDER}/ScoreScreen.o ${COMMON_FLAGS}

SCREEN_FOLDER = ${SRC_FOLDER}/screens/screen

${BUILD_FOLDER}/Screen.o: ${SSCREEN_I}/Screen.hpp ${SCREEN_FOLDER}/Screen.cpp
	${COMPILER} ${INCLUDES} -c ${SCREEN_FOLDER}/Screen.cpp -o ${BUILD_FOLDER}/Screen.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ScreenManager.o: ${SSCREEN_I}/ScreenManager.hpp ${SCREEN_FOLDER}/ScreenManager.cpp
	${COMPILER} ${INCLUDES} -c ${SCREEN_FOLDER}/ScreenManager.cpp -o ${BUILD_FOLDER}/ScreenManager.o ${COMMON_FLAGS}

TITLE_SCREEN_FOLDER = ${SRC_FOLDER}/screens/title

${BUILD_FOLDER}/TitleScreen.o: ${STITLE_I}/TitleScreen.hpp ${TITLE_SCREEN_FOLDER}/TitleScreen.cpp
	${COMPILER} ${INCLUDES} -c ${TITLE_SCREEN_FOLDER}/TitleScreen.cpp -o ${BUILD_FOLDER}/TitleScreen.o ${COMMON_FLAGS}


# Builda views compartilhadas
SHARED_VIEW_FOLDER = ${SRC_FOLDER}/screens/shared

${BUILD_FOLDER}/BoardDisplay.o: ${SSHARED_I}/BoardDisplay.hpp ${SHARED_VIEW_FOLDER}/BoardDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${SHARED_VIEW_FOLDER}/BoardDisplay.cpp -o ${BUILD_FOLDER}/BoardDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/PositionDisplay.o: ${SSHARED_I}/PositionDisplay.hpp ${SHARED_VIEW_FOLDER}/PositionDisplay.cpp
	${COMPILER} ${INCLUDES} -c ${SHARED_VIEW_FOLDER}/PositionDisplay.cpp -o ${BUILD_FOLDER}/PositionDisplay.o ${COMMON_FLAGS}

${BUILD_FOLDER}/AssetsLoader.o: ${SSHARED_I}/AssetsLoader.hpp ${SHARED_VIEW_FOLDER}/AssetsLoader.cpp
	${COMPILER} ${INCLUDES} -c ${SHARED_VIEW_FOLDER}/AssetsLoader.cpp -o ${BUILD_FOLDER}/AssetsLoader.o ${COMMON_FLAGS}

# Builda componentes
COMPONENT_FOLDER = ${SRC_FOLDER}/screens/components/component

${BUILD_FOLDER}/Component.o: ${SCOMPONENT_I}/Component.hpp ${COMPONENT_FOLDER}/Component.cpp
	${COMPILER} ${INCLUDES} -c ${COMPONENT_FOLDER}/Component.cpp -o ${BUILD_FOLDER}/Component.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ResizableComponent.o: ${SCOMPONENT_I}/ResizableComponent.hpp ${COMPONENT_FOLDER}/ResizableComponent.cpp
	${COMPILER} ${INCLUDES} -c ${COMPONENT_FOLDER}/ResizableComponent.cpp -o ${BUILD_FOLDER}/ResizableComponent.o ${COMMON_FLAGS}

${BUILD_FOLDER}/IClickable.o: ${SCOMPONENT_I}/IClickable.hpp ${COMPONENT_FOLDER}/IClickable.cpp
	${COMPILER} ${INCLUDES} -c ${COMPONENT_FOLDER}/IClickable.cpp -o ${BUILD_FOLDER}/IClickable.o ${COMMON_FLAGS}

TEXT_FOLDER = ${SRC_FOLDER}/screens/components/text

${BUILD_FOLDER}/Text.o: ${STEXT_I}/Text.hpp ${TEXT_FOLDER}/Text.cpp
	${COMPILER} ${INCLUDES} -c ${TEXT_FOLDER}/Text.cpp -o ${BUILD_FOLDER}/Text.o ${COMMON_FLAGS}

${BUILD_FOLDER}/TextIcon.o: ${STEXT_I}/TextIcon.hpp ${TEXT_FOLDER}/TextIcon.cpp
	${COMPILER} ${INCLUDES} -c ${TEXT_FOLDER}/TextIcon.cpp -o ${BUILD_FOLDER}/TextIcon.o ${COMMON_FLAGS}

BUTTON_FOLDER = ${SRC_FOLDER}/screens/components/button

${BUILD_FOLDER}/Button.o: ${SBUTTON_I}/Button.hpp ${BUTTON_FOLDER}/Button.cpp
	${COMPILER} ${INCLUDES} -c ${BUTTON_FOLDER}/Button.cpp -o ${BUILD_FOLDER}/Button.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ButtonText.o: ${SBUTTON_I}/ButtonText.hpp ${BUTTON_FOLDER}/ButtonText.cpp
	${COMPILER} ${INCLUDES} -c ${BUTTON_FOLDER}/ButtonText.cpp -o ${BUILD_FOLDER}/ButtonText.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ButtonIcon.o: ${SBUTTON_I}/ButtonIcon.hpp ${BUTTON_FOLDER}/ButtonIcon.cpp
	${COMPILER} ${INCLUDES} -c ${BUTTON_FOLDER}/ButtonIcon.cpp -o ${BUILD_FOLDER}/ButtonIcon.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ButtonTextIcon.o: ${SBUTTON_I}/ButtonTextIcon.hpp ${BUTTON_FOLDER}/ButtonTextIcon.cpp
	${COMPILER} ${INCLUDES} -c ${BUTTON_FOLDER}/ButtonTextIcon.cpp -o ${BUILD_FOLDER}/ButtonTextIcon.o ${COMMON_FLAGS}

IMAGE_FOLDER = ${SRC_FOLDER}/screens/components/image

${BUILD_FOLDER}/Image.o: ${SIMAGE_I}/Image.hpp ${IMAGE_FOLDER}/Image.cpp
	${COMPILER} ${INCLUDES} -c ${IMAGE_FOLDER}/Image.cpp -o ${BUILD_FOLDER}/Image.o ${COMMON_FLAGS}

VIEW_FOLDER = ${SRC_FOLDER}/screens/components/view
${BUILD_FOLDER}/View.o: ${SVIEW_I}/View.hpp ${VIEW_FOLDER}/View.cpp
	${COMPILER} ${INCLUDES} -c ${VIEW_FOLDER}/View.cpp -o ${BUILD_FOLDER}/View.o ${COMMON_FLAGS}

# Builda Classes
BOARD_FOLDER = ${SRC_FOLDER}/logic/board

${BUILD_FOLDER}/Board.o: ${LBOARD_I}/Board.hpp ${BOARD_FOLDER}/Board.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Board.cpp -o ${BUILD_FOLDER}/Board.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Point.o: ${LBOARD_I}/Point.hpp ${BOARD_FOLDER}/Point.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Point.cpp -o ${BUILD_FOLDER}/Point.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Position.o: ${LBOARD_I}/Position.hpp ${BOARD_FOLDER}/Position.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Position.cpp -o ${BUILD_FOLDER}/Position.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Battleship.o: ${LBOARD_I}/Battleship.hpp ${BOARD_FOLDER}/Battleship.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Battleship.cpp -o ${BUILD_FOLDER}/Battleship.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Crusier.o: ${LBOARD_I}/Crusier.hpp ${BOARD_FOLDER}/Crusier.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Crusier.cpp -o ${BUILD_FOLDER}/Crusier.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Submarine.o: ${LBOARD_I}/Submarine.hpp ${BOARD_FOLDER}/Submarine.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Submarine.cpp -o ${BUILD_FOLDER}/Submarine.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Troop.o: ${LBOARD_I}/Troop.hpp ${BOARD_FOLDER}/Troop.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_FOLDER}/Troop.cpp -o ${BUILD_FOLDER}/Troop.o ${COMMON_FLAGS} --coverage

FILEHANDLER_FOLDER = ${SRC_FOLDER}/logic/fileHandler

${BUILD_FOLDER}/FileHandler.o: ${LFILEHANDLER_I}/FileHandler.hpp ${FILEHANDLER_FOLDER}/FileHandler.cpp
	${COMPILER} ${INCLUDES} -c ${FILEHANDLER_FOLDER}/FileHandler.cpp -o ${BUILD_FOLDER}/FileHandler.o --coverage

${BUILD_FOLDER}/TxtReader.o: ${LFILEHANDLER_I}/TxtReader.hpp ${FILEHANDLER_FOLDER}/TxtReader.cpp
	${COMPILER} ${INCLUDES} -c ${FILEHANDLER_FOLDER}/TxtReader.cpp -o ${BUILD_FOLDER}/TxtReader.o --coverage

${BUILD_FOLDER}/TxtWriter.o: ${LFILEHANDLER_I}/TxtWriter.hpp ${FILEHANDLER_FOLDER}/TxtWriter.cpp
	${COMPILER} ${INCLUDES} -c ${FILEHANDLER_FOLDER}/TxtWriter.cpp -o ${BUILD_FOLDER}/TxtWriter.o --coverage

GAME_FOLDER = ${SRC_FOLDER}/logic/game

${BUILD_FOLDER}/GameManager.o: ${LGAME_I}/GameManager.hpp ${GAME_FOLDER}/GameManager.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_FOLDER}/GameManager.cpp -o ${BUILD_FOLDER}/GameManager.o ${COMMON_FLAGS}

${BUILD_FOLDER}/GameParameters.o: ${LGAME_I}/GameParameters.hpp ${GAME_FOLDER}/GameParameters.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_FOLDER}/GameParameters.cpp -o ${BUILD_FOLDER}/GameParameters.o ${COMMON_FLAGS} --coverage

MATCH_FOLDER = ${SRC_FOLDER}/logic/match

${BUILD_FOLDER}/Match.o: ${LMATCH_I}/Match.hpp ${MATCH_FOLDER}/Match.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_FOLDER}/Match.cpp -o ${BUILD_FOLDER}/Match.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/MatchResults.o: ${LMATCH_I}/MatchResults.hpp ${MATCH_FOLDER}/MatchResults.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_FOLDER}/MatchResults.cpp -o ${BUILD_FOLDER}/MatchResults.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Player.o: ${LMATCH_I}/Player.hpp ${MATCH_FOLDER}/Player.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_FOLDER}/Player.cpp -o ${BUILD_FOLDER}/Player.o ${COMMON_FLAGS} --coverage

${BUILD_FOLDER}/Score.o: ${LMATCH_I}/Score.hpp ${MATCH_FOLDER}/Score.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_FOLDER}/Score.cpp -o ${BUILD_FOLDER}/Score.o ${COMMON_FLAGS} --coverage

# Builda Exceptions
EXCEPTION_FOLDER = ${SRC_FOLDER}/logic/exceptions

${BUILD_FOLDER}/CustomException.o: ${LEXCEPTIONS_I}/CustomException.hpp ${EXCEPTION_FOLDER}/CustomException.cpp
	${COMPILER} ${INCLUDES} -c ${EXCEPTION_FOLDER}/CustomException.cpp -o ${BUILD_FOLDER}/CustomException.o ${COMMON_FLAGS}

${BUILD_FOLDER}/InvalidPositionException.o: ${LEXCEPTIONS_I}/InvalidPositionException.hpp ${EXCEPTION_FOLDER}/InvalidPositionException.cpp
	${COMPILER} ${INCLUDES} -c ${EXCEPTION_FOLDER}/InvalidPositionException.cpp -o ${BUILD_FOLDER}/InvalidPositionException.o ${COMMON_FLAGS}

# Builda utils
UTILS_FOLDER = ${SRC_FOLDER}/logic/utils
${BUILD_FOLDER}/StyleFunctions.o: ${LUTILS_I}/StyleFunctions.hpp ${UTILS_FOLDER}/StyleFunctions.cpp
	${COMPILER} ${INCLUDES} -c ${UTILS_FOLDER}/StyleFunctions.cpp -o ${BUILD_FOLDER}/StyleFunctions.o ${COMMON_FLAGS}

${BUILD_FOLDER}/ScoreFormatter.o: ${LUTILS_I}/ScoreFormatter.hpp ${UTILS_FOLDER}/ScoreFormatter.cpp
	${COMPILER} ${INCLUDES} -c ${UTILS_FOLDER}/ScoreFormatter.cpp -o ${BUILD_FOLDER}/ScoreFormatter.o ${COMMON_FLAGS}

#Buildando testes
TEST_FOLDER = ./tests

BUILD_TESTES = ${BUILD_FOLDER}/testBoard.o ${BUILD_FOLDER}/testPoint.o ${BUILD_FOLDER}/testPosition.o ${BUILD_FOLDER}/testFileHandler.o ${BUILD_FOLDER}/testTxtWriterTxtReader.o ${BUILD_FOLDER}/testPlayer.o ${BUILD_FOLDER}/testScore.o ${BUILD_FOLDER}/testMatchResults.o ${BUILD_FOLDER}/testSubmarine.o ${BUILD_FOLDER}/testCrusier.o ${BUILD_FOLDER}/testBattleship.o ${BUILD_FOLDER}/testGameParameters.o ${BUILD_FOLDER}/testMatch.o

linux_tests: ${BUILD_FOLDER}/maintests.o ${BUILD_FILES} ${BUILD_TESTES}
	${COMPILER} ${BUILD_FILES} ${BUILD_TESTES} ${BUILD_FOLDER}/maintests.o -L ${RAYLIB_LINUX_LIB} -o test ${COMMON_FLAGS} ${LINUX_BUILD_FLAGS} --coverage

${BUILD_FOLDER}/maintests.o: ${TEST_FOLDER}/maintests.cpp
	${COMPILER} ${INCLUDES} -c ${TEST_FOLDER}/maintests.cpp -o ${BUILD_FOLDER}/maintests.o ${COMMON_FLAGS}

BOARD_TEST_FOLDER = ${TEST_FOLDER}/board

${BUILD_FOLDER}/testBattleship.o: ${LBOARD_I}/Battleship.hpp ${BOARD_FOLDER}/Battleship.cpp ${BOARD_TEST_FOLDER}/testBattleship.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testBattleship.cpp -o ${BUILD_FOLDER}/testBattleship.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testBoard.o: ${LBOARD_I}/Board.hpp ${BOARD_FOLDER}/Board.cpp ${BOARD_TEST_FOLDER}/testBoard.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testBoard.cpp -o ${BUILD_FOLDER}/testBoard.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testCrusier.o: ${LBOARD_I}/Crusier.hpp ${BOARD_FOLDER}/Crusier.cpp ${BOARD_TEST_FOLDER}/testCrusier.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testCrusier.cpp -o ${BUILD_FOLDER}/testCrusier.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testPoint.o: ${LBOARD_I}/Point.hpp ${BOARD_FOLDER}/Point.cpp ${BOARD_TEST_FOLDER}/testPoint.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testPoint.cpp -o ${BUILD_FOLDER}/testPoint.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testPosition.o: ${LBOARD_I}/Position.hpp ${BOARD_FOLDER}/Position.cpp ${BOARD_TEST_FOLDER}/testPosition.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testPosition.cpp -o ${BUILD_FOLDER}/testPosition.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testSubmarine.o: ${LBOARD_I}/Submarine.hpp ${BOARD_FOLDER}/Submarine.cpp ${BOARD_TEST_FOLDER}/testSubmarine.cpp
	${COMPILER} ${INCLUDES} -c ${BOARD_TEST_FOLDER}/testSubmarine.cpp -o ${BUILD_FOLDER}/testSubmarine.o ${COMMON_FLAGS}

GAME_TEST_FOLDER = ${TEST_FOLDER}/game

${BUILD_FOLDER}/testGameParameters.o: ${LGAME_I}/GameParameters.hpp ${GAME_FOLDER}/GameParameters.cpp ${GAME_TEST_FOLDER}/testGameParameters.cpp
	${COMPILER} ${INCLUDES} -c ${GAME_TEST_FOLDER}/testGameParameters.cpp -o ${BUILD_FOLDER}/testGameParameters.o ${COMMON_FLAGS}

FILEHANDLER_TEST_FOLDER = ${TEST_FOLDER}/fileHandler

${BUILD_FOLDER}/testFileHandler.o: ${LFILEHANDLER_I}/FileHandler.hpp ${FILEHANDLER_FOLDER}/FileHandler.cpp ${FILEHANDLER_TEST_FOLDER}/testFileHandler.cpp
	${COMPILER} ${INCLUDES} -c ${FILEHANDLER_TEST_FOLDER}/testFileHandler.cpp -o ${BUILD_FOLDER}/testFileHandler.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testTxtWriterTxtReader.o: ${LFILEHANDLER_I}/TxtReader.hpp ${LFILEHANDLER_I}/TxtWriter.hpp ${FILEHANDLER_FOLDER}/TxtReader.cpp ${FILEHANDLER_FOLDER}/TxtWriter.cpp ${FILEHANDLER_TEST_FOLDER}/testTxtWriterTxtReader.cpp
	${COMPILER} ${INCLUDES} -c ${FILEHANDLER_TEST_FOLDER}/testTxtWriterTxtReader.cpp -o ${BUILD_FOLDER}/testTxtWriterTxtReader.o ${COMMON_FLAGS}

MATCH_TEST_FOLDER = ${TEST_FOLDER}/match

${BUILD_FOLDER}/testMatch.o : ${LMATCH_I}/Match.hpp ${MATCH_FOLDER}/Match.cpp ${MATCH_TEST_FOLDER}/testMatch.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_TEST_FOLDER}/testMatch.cpp -o ${BUILD_FOLDER}/testMatch.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testMatchResults.o : ${LMATCH_I}/MatchResults.hpp ${MATCH_FOLDER}/MatchResults.cpp ${MATCH_TEST_FOLDER}/testMatchResults.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_TEST_FOLDER}/testMatchResults.cpp -o ${BUILD_FOLDER}/testMatchResults.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testPlayer.o : ${LMATCH_I}/Player.hpp ${MATCH_FOLDER}/Player.cpp ${MATCH_TEST_FOLDER}/testPlayer.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_TEST_FOLDER}/testPlayer.cpp -o ${BUILD_FOLDER}/testPlayer.o ${COMMON_FLAGS}

${BUILD_FOLDER}/testScore.o: ${LMATCH_I}/Score.hpp ${MATCH_FOLDER}/Score.cpp ${MATCH_TEST_FOLDER}/testScore.cpp
	${COMPILER} ${INCLUDES} -c ${MATCH_TEST_FOLDER}/testScore.cpp -o ${BUILD_FOLDER}/testScore.o ${COMMON_FLAGS}
 
# Deleta todos arquivos na pasta de Build, executavel principal e executavel de testes
clean:
	rm -f ./build/*
	rm -f ${PROJECT_NAME}
	rm -f test

window_clean:
	del /S .\build\*
	del ${PROJECT_NAME}.exe

run:
	make linux_build_${PROJECT_NAME} && ./${PROJECT_NAME}