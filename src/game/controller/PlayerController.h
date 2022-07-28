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
    typedef std::function<void(PieceColor color, std::array<int, 2> selection)> ActionCallback;

    PlayerArray m_players;
    int m_currentPlayer;

    std::queue<EPlayerAction> m_actionQueue;
    ActionCallback m_actionCallback;
public:
    PlayerController();

    void setOpponent(const std::shared_ptr<Player>& player);
    void setActionListener(const ActionCallback& callback);
    const std::shared_ptr<Player>& getCurrentPlayer() const;
    void switchPlayer();

    void update(PairSelector& selector);
    void enqueueAction(EPlayerAction action);

    bool isHumanMoving() const;
};
