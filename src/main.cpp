
#include "game/CantStop.h"
#include "game/player/HumanPlayer.h"
#include "game/player/ComputerPlayer.h"

int main() {
    HumanPlayer playerOne("Human");
    ComputerPlayer playerTwo("Computer");

    CantStop cantStop(playerOne, playerTwo);
    cantStop.start();
    return 0;
}