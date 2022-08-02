//
// Created on 30/07/2022.
//

#pragma once
#include "../actors/PlayerEnums.h"
#include <functional>

class CallbackAdapter {
    typedef std::function<TurnResult(PieceOwner color, std::array<int, 2> selection)> OnMoveCallback;
    typedef std::function<void(PieceOwner color, bool didBust)> OnTurnFinishCallback;
    typedef std::function<void(PieceOwner winner, std::string player)> OnGameFinishCallback;
protected:
    OnMoveCallback m_onMoveCallback;
    OnTurnFinishCallback m_onFinishCallback;
    OnGameFinishCallback m_onGameFinishCallback;
public:
    void setOnMoveListener(const OnMoveCallback& callback);
    void setOnTurnFinishListener(const OnTurnFinishCallback& callback);
    void setOnGameFinishListener(const OnGameFinishCallback& callback);
};
