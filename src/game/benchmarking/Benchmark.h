//
// Created on 02.08.2022.
//

#pragma once

#include <vector>

class Benchmark {
    int m_runCount;
    bool m_running;

    int m_firstPlayerWins;
    int m_secondPlayerWins;
public:
    void commitRun(PieceOwner data) {
        m_runCount--;
        m_running = !isFinished();
        if (data == PieceOwner::PLAYER_ONE) {
            m_firstPlayerWins++;
        } else {
            m_secondPlayerWins++;
        }
    };

    PieceOwner getWinner() const {
        return m_firstPlayerWins < m_secondPlayerWins ? PieceOwner::PLAYER_ONE : PieceOwner::PLAYER_TWO;
    }

    float getWinnerPercentage() const {
        return (m_secondPlayerWins + m_firstPlayerWins) / getWinnerAmount();
    }

    int getWinnerAmount() const {
        return std::max(m_firstPlayerWins, m_secondPlayerWins);
    }

    float getFirstPlayerWins() {
        return m_firstPlayerWins;
    }

    float getSecondPlayerWins() {
        return m_secondPlayerWins;
    }

    void setRunCount(int newCount) {
        m_runCount = newCount;
    }

    bool isLastRun() const {
        return m_runCount == 1;
    }

    void setRunning(bool state) {
        m_running = state;
    }

    bool isRunning() const {
        return m_running;
    }

    bool isFinished() const {
        return m_runCount == 0;
    };
};
