
#include "game/CantStop.h"
#include <unordered_set>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    CantStop cantStop(settings);
    cantStop.start();
    return 0;
}


