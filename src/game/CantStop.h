//
// Created on 05/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "model/Model.h"
#include "view/GameView.h"
#include "controller/PlayerController.h"
#include "controller/BoardController.h"
#include "controller/ViewController.h"

class CantStop {
    BoardController m_boardController;
    PlayerController m_playerController;
    ViewController m_viewController;
    sf::RenderWindow m_window;

    void onEvent(sf::Event emitter);
public:
    CantStop(Player& one, Player& two);
    void start();
};
