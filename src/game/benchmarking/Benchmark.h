//
// Created on 02.08.2022.
//

#pragma once

#include <vector>

template <typename T>
class Benchmark {
    int m_runCount;
    bool m_running;
    std::vector<T> m_resultDataOne;
public:
    void commitRun(T data) {
        m_runCount--;
        m_running = !isFinished();
    };

    void setRunCount(int newCount) {
        m_runCount = newCount;
    }

    int getRunCount() const {
        return m_runCount;
    };

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
