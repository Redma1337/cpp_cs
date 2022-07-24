//
// Created on 05/07/2022.
//

#include "CantStop.h"
#include "wrapper/RenderWrapper.h"


CantStop::CantStop(Player &one, Player &two)
    :
        m_playerController{ one, two }, m_window(sf::VideoMode(1000, 800), "Can't Stop Game", sf::Style::Default)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    m_boardController.setBoard(board);

    std::shared_ptr<GameView> view = std::make_shared<GameView>("Cant Stop Game", board, m_playerController);
    m_viewController.addView(Menu::GAME_VIEW, view);

    //relative to cmake-build-debug/sfml_test.exe
    RenderWrapper::loadFont("../resources/fonts/Segoe UI.ttf");
}

void
CantStop::start() {
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            onEvent(event);
        }

        m_window.clear(sf::Color::Black);

        m_viewController.drawView(m_window);

        m_window.display();
    }
}

void
CantStop::onEvent(sf::Event emitter) {
    if (emitter.type == sf::Event::MouseButtonPressed) {
        if (emitter.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
            m_viewController.onClick(mousePos);
        }
    }
}