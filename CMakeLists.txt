cmake_minimum_required(VERSION 3.22)
project(sfml_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfml_test src/main.cpp src/game/view/View.h src/game/view/GameView.cpp src/game/view/GameView.h src/game/CantStop.cpp src/game/CantStop.h src/game/controller/PlayerController.cpp src/game/controller/PlayerController.h src/game/player/Player.cpp src/game/player/Player.h src/game/player/HumanPlayer.cpp src/game/player/HumanPlayer.h src/game/player/ComputerPlayer.cpp src/game/player/ComputerPlayer.h src/game/controller/DiceController.cpp src/game/controller/DiceController.h src/game/player/EPieceColor.h src/game/player/EPieceType.h src/game/components/Column.cpp src/game/components/Column.h src/game/components/Cell.cpp src/game/components/Cell.h src/game/controller/BoardController.cpp src/game/controller/BoardController.h src/game/controller/ViewController.cpp src/game/controller/ViewController.h src/game/view/EMenu.h src/game/components/Component.h src/game/components/Board.cpp src/game/components/Board.h src/game/components/Button.cpp src/game/components/Button.h src/game/view/IClickable.h src/game/components/PairSelector.cpp src/game/components/PairSelector.h src/game/wrapper/RenderWrapper.cpp src/game/wrapper/RenderWrapper.h src/game/controller/EPlayerAction.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR cmake-modules/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(cmake-modules/SFML/include)
target_link_libraries(sfml_test sfml-system sfml-window sfml-graphics sfml-audio sfml-network)