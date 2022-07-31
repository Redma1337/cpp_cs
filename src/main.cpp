
#include "game/CantStop.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    CantStop cantStop(settings);
    cantStop.start();
    return 0;
}