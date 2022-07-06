//
// Created on 05/07/2022.
//

#include "CantStop.h"

size_t CantStop::WINDOW_WIDTH = 800;
size_t CantStop::WINDOW_HEIGHT = 600;

CantStop::CantStop(Player &one, Player &two)
    :
        m_boardController{ m_boardModel },
        m_gameView{ "Game View", m_boardModel },
        m_playerController{ one, two }
{
    //TODO: potential setup Code
}

void
CantStop::start() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Can't Stop Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            onEvent(event);
        }

        window.clear(sf::Color::Black);

        window.display();
    }
}

void
CantStop::onEvent(sf::Event emitter) {
    if (emitter.type == sf::Event::MouseButtonPressed) {
        if (emitter.mouseButton.button == sf::Mouse::Right) {
            //TODO: Spread Event
        }
    }
}