//
// Created on 05/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "model/Model.h"
#include "view/GameView.h"
#include "controller/PlayerController.h"
#include "controller/BoardController.h"

class CantStop {
    Model<BoardModelType> m_boardModel;
    const GameView m_gameView;

    const BoardController m_boardController;
    const PlayerController m_playerController;

    void onEvent(sf::Event emitter);
public:
    static size_t WINDOW_WIDTH, WINDOW_HEIGHT;

    CantStop(Player& one, Player& two);
    void start();

};
