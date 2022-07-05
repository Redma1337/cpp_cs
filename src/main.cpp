
#include "game/CantStop.h"
#include "game/player/HumanPlayer.h"
#include "game/player/ComputerPlayer.h"

int main() {
    HumanPlayer playerOne("Player One");
    ComputerPlayer playerTwo("Player Two");

    CantStop cantStop(playerOne, playerTwo);
    cantStop.start();
    return 0;
}

