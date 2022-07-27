//
// Created on 05/07/2022.
//

#pragma once

#include "../player/Player.h"
#include "DiceController.h"
#include "EPlayerAction.h"
#include <queue>
#include <chrono>
#include <thread>

typedef std::pair<Player&, Player&> PlayerMatchUpModel;

class PlayerController {
    Player& m_playerOne;
    Player& m_playerTwo;
    Player* m_currentPlayer;
    std::queue<EPlayerAction> m_actionQueue;
public:
    PlayerController(Player& one, Player& two);
    ~PlayerController();

    void update(PairSelector& selector);

    void enqueueAction(EPlayerAction action);
    void switchPlayer();
    bool isHumanMoving() const;
};
