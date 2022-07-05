//
// Created on 05/07/2022.
//

#include "CantStop.h"
#include "controller/DiceController.h"

CantStop::CantStop()
    : m_boardModel{ 0 }, m_gameView{ "Game View", m_boardModel }
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

//this function will connect our observer system with the sfml internal event system
void
CantStop::onEvent(sf::Event emitter) {
    if (emitter.type == sf::Event::MouseButtonPressed) {
        if (emitter.mouseButton.button == sf::Mouse::Right) {
            //TODO: Spread Event
            m_boardModel.setData(10);
        }
    }
}