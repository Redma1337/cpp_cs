//
// Created on 05/07/2022.
//

#include "CantStop.h"

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
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; //this is gpu dependent
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Can't Stop Game",
        sf::Style::Default,
        settings
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            onEvent(event);
        }

        window.clear(sf::Color::Black);

        //TODO: potentially implement several screen support using view controller
        const sf::Texture& viewDrawCtx(m_gameView.getTexture());
        sf::Sprite view(viewDrawCtx);
        window.draw(view);

        window.display();
    }
}

void
CantStop::onEvent(sf::Event emitter) {
    if (emitter.type == sf::Event::MouseButtonPressed) {
        if (emitter.mouseButton.button == sf::Mouse::Right) {
            //TODO: Spread Event
            m_boardModel.fireEvent();
        }
    }
}