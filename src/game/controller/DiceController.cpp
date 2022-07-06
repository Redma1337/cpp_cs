//
// Created on 05/07/2022.
//

#include "DiceController.h"
#include <iostream>

std::mt19937 DiceController::m_rngEngine(time(NULL));

std::uniform_int_distribution<size_t> DiceController::m_span(1, 6);

int
DiceController::rollSingleDice() {
    return m_span(m_rngEngine);
}

std::array<int, 4>
DiceController::rollDices() {
    return {
        rollSingleDice(),
        rollSingleDice(),
        rollSingleDice(),
        rollSingleDice()
    };
}