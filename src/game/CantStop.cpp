//
// Created on 05/07/2022.
//

#include "CantStop.h"
#include "../graphics/utils/RenderWrapper.h"

CantStop::CantStop(sf::ContextSettings ctxSettings)
    :   m_window(sf::VideoMode(1000, 850), "Can't Stop Game", sf::Style::Default, ctxSettings),
        m_benchmark{}
{
    //relative to cmake-build-debug/sfml_test.exe
    RenderWrapper::loadFont("../resources/fonts/Roboto-Medium.ttf");

    setupBoardController();
    setupRoutes();
}

void
CantStop::setupBoardController() {
    std::shared_ptr<Board> board = std::make_shared<Board>();
    m_boardController.setBoard(board);

    m_playerController.setOnMoveListener([&](PieceOwner color, std::array<int, 2> selection){
        return m_boardController.onMove(color, selection);
    });

    m_playerController.setOnTurnFinishListener([&](PieceOwner color, bool didBust){
        return m_boardController.onFinish(color, didBust);
    });

    m_playerController.setOnGameFinishListener([&](PieceOwner winner, std::string name){
        m_resultView->setWinner(name);
        bool isLastRun = m_benchmark.isLastRun();
        if (m_benchmark.isRunning()) {
            m_benchmark.commitRun(winner);
        }

        if (m_benchmark.isRunning()) {
            m_viewController.setCurrentView(Menu::GAME_VIEW);
        } else {
            if (isLastRun) {
                m_viewController.setCurrentView(Menu::GAME_BENCHMARK);
            } else {
                m_viewController.setCurrentView(Menu::GAME_WON);
            }
        }
    });
}

void
CantStop::setupRoutes() {
    m_resultView = std::make_shared<GameResultView>([&] {
        //handle a play aigan request
        m_playerController.reset();
        m_viewController.setCurrentView(Menu::GAME_SETTINGS);
    });

    m_settingsView = std::make_shared<GameSettingsView>([&](auto one, auto two) {
        //handle the game start
        m_playerController.setPlayer(PieceOwner::PLAYER_ONE, one);
        m_playerController.setPlayer(PieceOwner::PLAYER_TWO, two);
        m_viewController.setCurrentView(Menu::GAME_VIEW);
    });

    m_settingsView->addBenchmarkStartedListener([&](auto one, auto two) {
        m_benchmark.setRunCount(5);
        m_benchmark.setRunning(true);
        m_playerController.setPlayer(PieceOwner::PLAYER_ONE, one);
        m_playerController.setPlayer(PieceOwner::PLAYER_TWO, two);
        m_viewController.setCurrentView(Menu::GAME_VIEW);
    });

    m_benchmarkView = std::make_shared<BenchmarkResultView>([&] {
        m_playerController.reset();
        m_viewController.setCurrentView(Menu::GAME_SETTINGS);
    }, m_benchmark);

    m_gameView = std::make_shared<GameView>(m_boardController, m_playerController);

    m_viewController.addView(Menu::GAME_VIEW, m_gameView);
    m_viewController.addView(Menu::GAME_WON, m_resultView);
    m_viewController.addView(Menu::GAME_SETTINGS, m_settingsView);
    m_viewController.addView(Menu::GAME_BENCHMARK, m_settingsView);

    m_viewController.setCurrentView(Menu::GAME_SETTINGS);
}

void
CantStop::start() {
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            onEvent(event);
        }

        m_window.clear(sf::Color(15, 23, 42));

        m_viewController.onUpdate();
        m_viewController.drawView(m_window);

        m_window.display();
    }
}

void
CantStop::onEvent(sf::Event emitter) {
    if (emitter.type == sf::Event::MouseButtonPressed) {
        if (emitter.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
            m_viewController.onClick(mousePos);
        }
    }
}


