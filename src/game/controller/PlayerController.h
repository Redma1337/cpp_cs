//
// Created on 05/07/2022.
//

#pragma once

#include "../player/Player.h"
#include "DiceController.h"
#include "EPlayerAction.h"
#include "BoardController.h"
#include "../player/HumanPlayer.h"
#include <queue>
#include <chrono>
#include <thread>

class PlayerController {
    typedef std::shared_ptr<Player> PlayerArray[2];

    PlayerArray m_players;
    int m_currentPlayer;

    std::queue<EPlayerAction> m_actionQueue;
    BoardController m_boardController;
public:
    PlayerController();

    void setOpponent(const std::shared_ptr<Player>& player);
    const std::shared_ptr<Player>& getCurrentPlayer() const;
    void switchPlayer();

    void update(PairSelector& selector);
    void enqueueAction(EPlayerAction action);

    bool isHumanMoving() const;
};
