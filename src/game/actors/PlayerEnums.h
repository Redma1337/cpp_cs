//
// Created on 30/07/2022.
//

#pragma once

enum class TurnResult {
    DEFAULT,
    BUSTED,
    WON,
};

enum class PlayerAction {
    IDLE,
    WAIT,
    ROLL_DICE,
    MAKE_SELECTION,
    SWITCH_PLAYER
};

enum class PieceOwner {
    PLAYER_ONE = 0,
    PLAYER_TWO = 1
};