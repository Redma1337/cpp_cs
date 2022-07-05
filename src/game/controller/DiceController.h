//
// Created on 05/07/2022.
//

#pragma once
#include <random>
#include <ctime>
#include <array>

class DiceController {
    static std::mt19937 m_rngEngine;
    static std::uniform_int_distribution<size_t> m_span;

    static int rollSingleDice();
public:
    static std::array<int, 4> rollDices();
};
