
#include "game/CantStop.h"
#include "game/player/HumanPlayer.h"
#include "game/player/ComputerPlayer.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    CantStop cantStop(settings);
    cantStop.start();
    return 0;
}