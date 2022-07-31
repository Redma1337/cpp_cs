//
// Created on 05/07/2022.
//

#pragma once

#include "DiceController.h"
#include "../../graphics/controller/BoardController.h"
#include "CallbackAdapter.h"
#include "../actors/Player.h"
#include <queue>
#include <chrono>
#include <thread>
#include <iostream>

class PlayerController : public CallbackAdapter {
    typedef std::shared_ptr<Player> SharedPlayer;
    typedef std::queue<PlayerAction> ActionQueue;

    SharedPlayer m_players[2];
    PieceOwner m_currentPlayer;

    ActionQueue m_actionQueue;

    std::string m_statusText;
public:
    PlayerController();

    void update(PairSelector& selector);
    void switchPlayer();
    void reset();

    void enqueueAction(PlayerAction action);
    void clearActions();

    void setPlayer(PieceOwner playerPos, const SharedPlayer& player);
    const SharedPlayer getCurrentPlayer() const;

    bool isHumanMoving() const;
    std::string getCurrentStatus() const;
};
