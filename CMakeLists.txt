cmake_minimum_required(VERSION 3.22)
project(sfml_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfml_test src/main.cpp src/game/view/View.h src/game/view/GameView.cpp src/game/view/GameView.h src/game/model/Model.h src/game/event/IObserver.h src/game/event/Observable.cpp src/game/event/Observable.h src/game/CantStop.cpp src/game/CantStop.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR cmake-modules/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(cmake-modules/SFML/include)
target_link_libraries(sfml_test sfml-system sfml-window sfml-graphics sfml-audio sfml-network)