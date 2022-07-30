//
// Created on 30/07/2022.
//

#include "CallbackAdapter.h"

void CallbackAdapter::setOnMoveListener(const OnMoveCallback& callback) {
    m_onMoveCallback = callback;
}

void CallbackAdapter::setOnTurnFinishListener(const OnTurnFinishCallback& callback) {
    m_onFinishCallback = callback;
}

void CallbackAdapter::setOnGameFinishListener(const OnGameFinishCallback& callback) {
    m_onGameFinishCallback = callback;
}