//
// Created on 05/07/2022.
//

#pragma once

#include "../player/Player.h"
#include "DiceController.h"

typedef std::pair<Player&, Player&> PlayerMatchUpModel;

class PlayerController {
    Player& m_playerOne;
    Player& m_playerTwo;
    Player* m_currentPlayer;
public:
    PlayerController(Player& one, Player& two);
    bool doTurn(PairSelector& selector);
    void switchPlayer();
};
