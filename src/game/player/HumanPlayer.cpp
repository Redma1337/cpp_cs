//
// Created on 05/07/2022.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string name)
    : Player(std::move(name), true)
{}

std::array<int, 2>
HumanPlayer::generateTurn(std::array<int, 4> dices) {
    //TODO: implement move logic
}