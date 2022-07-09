//
// Created on 05/07/2022.
//

#include "CantStop.h"

CantStop::CantStop(Player &one, Player &two)
    :
        m_playerController{ one, two }
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    m_boardController.setBoard(board);

    std::shared_ptr<GameView> view = std::make_shared<GameView>("Cant Stop Game", board);
    m_viewController.addView(Menu::GAME_VIEW, view);

}

void
CantStop::start() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; //this is gpu dependent
    sf::RenderWindow window(
        sf::VideoMode(800, 800),
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

        m_viewController.drawView(window);

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