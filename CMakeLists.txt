cmake_minimum_required(VERSION 3.22)
project(sfml_test)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(sfml_test src/main.cpp src/graphics/display/View.h src/graphics/display/views/GameView.cpp src/graphics/display/views/GameView.h src/game/CantStop.cpp src/game/CantStop.h src/game/controller/PlayerController.cpp src/game/controller/PlayerController.h src/game/actors/Player.cpp src/game/actors/Player.h src/game/actors/players/HumanPlayer.cpp src/game/actors/players/HumanPlayer.h src/game/controller/DiceController.cpp src/game/controller/DiceController.h src/graphics/controller/EPieceType.h src/graphics/components/board/Column.cpp src/graphics/components/board/Column.h src/graphics/components/board/Cell.cpp src/graphics/components/board/Cell.h src/graphics/controller/BoardController.cpp src/graphics/controller/BoardController.h src/graphics/controller/ViewController.cpp src/graphics/controller/ViewController.h src/graphics/display/MenuEnum.h src/graphics/components/Component.h src/graphics/components/board/Board.cpp src/graphics/components/board/Board.h src/graphics/components/misc/Button.cpp src/graphics/components/misc/Button.h src/graphics/components/IClickable.h src/graphics/components/misc/pairing/PairSelector.cpp src/graphics/components/misc/pairing/PairSelector.h src/graphics/utils/RenderWrapper.cpp src/graphics/utils/RenderWrapper.h src/graphics/utils/RoundedRectangleShape.cpp src/graphics/utils/RoundedRectangleShape.h src/graphics/display/views/GameSettingsView.cpp src/graphics/display/views/GameSettingsView.h src/graphics/display/views/GameResultView.cpp src/graphics/display/views/GameResultView.h src/game/actors/PlayerEnums.h src/graphics/ColorTheme.h src/game/controller/CallbackAdapter.cpp src/game/controller/CallbackAdapter.h src/graphics/components/misc/pairing/Selector.h src/game/actors/players/RandomBot.cpp src/game/actors/players/RandomBot.h src/game/actors/players/GreedyBot.cpp src/game/actors/players/GreedyBot.h src/game/actors/players/HesitantBot.cpp src/game/actors/players/HesitantBot.h src/game/actors/players/IntelligentBot.cpp src/game/actors/players/IntelligentBot.h src/tests/bot_test.cpp src/game/actors/players/Bot.cpp src/game/actors/players/Bot.h src/game/actors/players/Bot.cpp src/game/actors/players/Bot.h src/graphics/display/views/BenchmarkResultView.cpp src/graphics/display/views/BenchmarkResultView.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR cmake-modules/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(cmake-modules/SFML/include)

#gtest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(sfml_test gtest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#enable_testing()

#add_executable(BotTest src/tests/bot_test.cpp src/graphics/display/View.h src/graphics/display/views/GameView.cpp src/graphics/display/views/GameView.h src/game/CantStop.cpp src/game/CantStop.h src/game/controller/PlayerController.cpp src/game/controller/PlayerController.h src/game/actors/Player.cpp src/game/actors/Player.h src/game/actors/players/HumanPlayer.cpp src/game/actors/players/HumanPlayer.h src/game/controller/DiceController.cpp src/game/controller/DiceController.h src/graphics/controller/EPieceType.h src/graphics/components/board/Column.cpp src/graphics/components/board/Column.h src/graphics/components/board/Cell.cpp src/graphics/components/board/Cell.h src/graphics/controller/BoardController.cpp src/graphics/controller/BoardController.h src/graphics/controller/ViewController.cpp src/graphics/controller/ViewController.h src/graphics/display/MenuEnum.h src/graphics/components/Component.h src/graphics/components/board/Board.cpp src/graphics/components/board/Board.h src/graphics/components/misc/Button.cpp src/graphics/components/misc/Button.h src/graphics/components/IClickable.h src/graphics/components/misc/pairing/PairSelector.cpp src/graphics/components/misc/pairing/PairSelector.h src/graphics/utils/RenderWrapper.cpp src/graphics/utils/RenderWrapper.h src/graphics/utils/RoundedRectangleShape.cpp src/graphics/utils/RoundedRectangleShape.h src/graphics/display/views/GameSettingsView.cpp src/graphics/display/views/GameSettingsView.h src/graphics/display/views/GameResultView.cpp src/graphics/display/views/GameResultView.h src/game/actors/PlayerEnums.h src/graphics/ColorTheme.h src/game/controller/CallbackAdapter.cpp src/game/controller/CallbackAdapter.h src/graphics/components/misc/pairing/Selector.h src/game/actors/players/RandomBot.cpp src/game/actors/players/RandomBot.h src/game/actors/players/GreedyBot.cpp src/game/actors/players/GreedyBot.h src/game/actors/players/HesitantBot.cpp src/game/actors/players/HesitantBot.h src/game/actors/players/IntelligentBot.cpp src/game/actors/players/IntelligentBot.h src/tests/bot_test.cpp src/game/actors/players/Bot.cpp src/game/actors/players/Bot.h)
#target_link_libraries(BotTest GTest::gtest_main gtest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#add_executable(CellTest src/tests/components_test.cpp src/graphics/display/View.h src/graphics/display/views/GameView.cpp src/graphics/display/views/GameView.h src/game/CantStop.cpp src/game/CantStop.h src/game/controller/PlayerController.cpp src/game/controller/PlayerController.h src/game/actors/Player.cpp src/game/actors/Player.h src/game/actors/players/HumanPlayer.cpp src/game/actors/players/HumanPlayer.h src/game/controller/DiceController.cpp src/game/controller/DiceController.h src/graphics/controller/EPieceType.h src/graphics/components/board/Column.cpp src/graphics/components/board/Column.h src/graphics/components/board/Cell.cpp src/graphics/components/board/Cell.h src/graphics/controller/BoardController.cpp src/graphics/controller/BoardController.h src/graphics/controller/ViewController.cpp src/graphics/controller/ViewController.h src/graphics/display/MenuEnum.h src/graphics/components/Component.h src/graphics/components/board/Board.cpp src/graphics/components/board/Board.h src/graphics/components/misc/Button.cpp src/graphics/components/misc/Button.h src/graphics/components/IClickable.h src/graphics/components/misc/pairing/PairSelector.cpp src/graphics/components/misc/pairing/PairSelector.h src/graphics/utils/RenderWrapper.cpp src/graphics/utils/RenderWrapper.h src/graphics/utils/RoundedRectangleShape.cpp src/graphics/utils/RoundedRectangleShape.h src/graphics/display/views/GameSettingsView.cpp src/graphics/display/views/GameSettingsView.h src/graphics/display/views/GameResultView.cpp src/graphics/display/views/GameResultView.h src/game/actors/PlayerEnums.h src/graphics/ColorTheme.h src/game/controller/CallbackAdapter.cpp src/game/controller/CallbackAdapter.h src/graphics/components/misc/pairing/Selector.h src/game/actors/players/RandomBot.cpp src/game/actors/players/RandomBot.h src/game/actors/players/GreedyBot.cpp src/game/actors/players/GreedyBot.h src/game/actors/players/HesitantBot.cpp src/game/actors/players/HesitantBot.h src/game/actors/players/IntelligentBot.cpp src/game/actors/players/IntelligentBot.h src/tests/bot_test.cpp src/game/actors/players/Bot.cpp src/game/actors/players/Bot.h)
#target_link_libraries(CellTest GTest::gtest_main gtest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#include(GoogleTest)
#gtest_discover_tests(BotTest CellTest)
