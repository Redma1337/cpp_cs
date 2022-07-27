//
// Created on 05/07/2022.
//

#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(std::string name)
        : Player(std::move(name), false)
{}

std::array<int, 2>
ComputerPlayer::doSelection(PairSelector& pairSelector) {
    std::cout << "Computer Player turning...." << std::endl;
    pairSelector.clickButton(0);
    pairSelector.clickButton(2);
    pairSelector.clickButton(1);
    pairSelector.clickButton(3);
    return pairSelector.getDecision();
}

std::vector<EPlayerAction>
ComputerPlayer::generateActions() {
    std::vector<EPlayerAction> actions;
    actions.push_back(EPlayerAction::ROLL_DICE);
    actions.push_back(EPlayerAction::WAIT);
    actions.push_back(EPlayerAction::WAIT);
    actions.push_back(EPlayerAction::MAKE_SELECTION);
    actions.push_back(EPlayerAction::WAIT);
    actions.push_back(EPlayerAction::SWITCH_PLAYER);
    return actions;
}