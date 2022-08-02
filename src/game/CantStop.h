//
// Created on 05/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "controller/PlayerController.h"
#include "../graphics/controller/BoardController.h"
#include "../graphics/controller/ViewController.h"
#include "../graphics/display/views/GameView.h"
#include "../graphics/display/views/GameResultView.h"
#include "../graphics/display/views/GameSettingsView.h"
#include "benchmarking/Benchmark.h"

class CantStop {
    BoardController m_boardController;
    PlayerController m_playerController;
    ViewController m_viewController;

    Benchmark<PieceOwner> m_benchmark;

    sf::RenderWindow m_window;

    std::shared_ptr<GameView> m_gameView;
    std::shared_ptr<GameResultView> m_resultView;
    std::shared_ptr<GameSettingsView> m_settingsView;

    void onEvent(sf::Event emitter);
public:
    CantStop(sf::ContextSettings ctxSettings);
    void start();
    void setupBoardController();
    void setupRoutes();
};
