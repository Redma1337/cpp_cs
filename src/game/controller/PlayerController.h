//
// Created on 05/07/2022.
//

#pragma once

#include "../player/Player.h"
#include "../player/HumanPlayer.h"
#include "DiceController.h"
#include "EPlayerAction.h"
#include "BoardController.h"
#include "CallbackAdapter.h"
#include <queue>
#include <chrono>
#include <thread>

class PlayerController : public CallbackAdapter {
    typedef std::shared_ptr<Player> PlayerArray[2];

    PlayerArray m_players;
    PieceOwner m_currentPlayer;

    std::queue<EPlayerAction> m_actionQueue;

    std::string m_statusText;
public:
    PlayerController();

    void update(PairSelector& selector);
    void switchPlayer();
    void reset();

    void enqueueAction(EPlayerAction action);
    void clearActions();

    void setPlayer(PieceOwner playerPos, const std::shared_ptr<Player>& player);
    const std::shared_ptr<Player>& getCurrentPlayer() const;

    bool isHumanMoving() const;
    std::string getCurrentStatus();
};
