//
// Created on 05/07/2022.
//

#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(std::string name)
        : Player(std::move(name), false)
{}

std::array<int, 2>
ComputerPlayer::generateTurn(PairSelector& pairSelector) {
    //TODO: implement move logic
}