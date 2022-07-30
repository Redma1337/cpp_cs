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

    typedef std::function<TurnResult(PieceOwner color, std::array<int, 2> selection)> OnMoveCallback;
    typedef std::function<void(PieceOwner color, bool didBust)> OnTurnFinishCallback;
    typedef std::function<void(PieceOwner color)> OnGameFinishCallback;

    PlayerArray m_players;
    int m_currentPlayer;

    std::queue<EPlayerAction> m_actionQueue;

    OnMoveCallback m_onMoveCallback;
    OnTurnFinishCallback m_onFinishCallback;
    OnGameFinishCallback m_onGameFinishCallback;

    std::string m_statusText;
public:
    PlayerController();

    void setOnMoveListener(const OnMoveCallback& callback);
    void setOnTurnFinishListener(const OnTurnFinishCallback& callback);
    void setOnGameFinishCallback(const OnGameFinishCallback& callback);


    void setOpponent(const std::shared_ptr<Player>& player);
    const std::shared_ptr<Player>& getCurrentPlayer() const;
    void switchPlayer();

    void update(PairSelector& selector);
    void enqueueAction(EPlayerAction action);

    bool isHumanMoving() const;
    std::string getCurrentStatus();
};
