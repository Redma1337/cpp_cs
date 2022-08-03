//
// Created on 02.08.2022.
//

#pragma once

#include <vector>
#include <cmath>

class Benchmark {
    int m_runCount;
    bool m_running;

    int m_firstPlayerWins;
    int m_secondPlayerWins;
    std::string m_firstName;
    std::string m_secondName;
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

    float getPercentage(PieceOwner owner) const {
        float total = m_firstPlayerWins + m_secondPlayerWins;
        float perc = (owner == PieceOwner::PLAYER_ONE ? m_firstPlayerWins : m_secondPlayerWins);
        float result = 100.f * (perc / total);
        return result;
    }

    int getFirstPlayerWins() const {
        return m_firstPlayerWins;
    }

    int getSecondPlayerWins() const {
        return m_secondPlayerWins;
    }

    void setRunCount(int newCount) {
        m_runCount = newCount;
        m_firstPlayerWins = 0;
        m_secondPlayerWins = 0;
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
