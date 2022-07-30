//
// Created on 05/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "view/GameView.h"
#include "controller/PlayerController.h"
#include "controller/BoardController.h"
#include "controller/ViewController.h"
#include "view/GameResultView.h"
#include "view/GameSettingsView.h"

class CantStop {
    BoardController m_boardController;
    PlayerController m_playerController;
    ViewController m_viewController;
    sf::RenderWindow m_window;

    std::shared_ptr<GameView> m_gameView;
    std::shared_ptr<GameResultView> m_resultView;
    std::shared_ptr<GameSettingsView> m_settingsView;

    void onEvent(sf::Event emitter);
public:
    CantStop(sf::ContextSettings ctxSettings);
    void restart();

    void start();
    void setupBoardController();
    void setupGameControlls();
    void setupRoutes();
};
