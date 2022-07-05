//
// Created on 05/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "model/Model.h"
#include "view/GameView.h"

class CantStop {
    //this holds the data necessary to represent the board
    Model<int> m_boardModel;

    //this draws the game board and will update if board model is edited
    GameView m_gameView;

    void onEvent(sf::Event emitter);
public:
    CantStop();
    void start();

};
