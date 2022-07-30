//
// Created on 05/07/2022.
//

#include "CantStop.h"
#include "wrapper/RenderWrapper.h"
#include "player/ComputerPlayer.h"


CantStop::CantStop(sf::ContextSettings ctxSettings)
    :   m_window(sf::VideoMode(1000, 800), "Can't Stop Game", sf::Style::Default, ctxSettings)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    m_boardController.setBoard(board);

    std::shared_ptr<ComputerPlayer> opponent = std::make_shared<ComputerPlayer>("Computer Player");
    m_playerController.setOpponent(opponent);

    m_playerController.setOnMoveListener(
        [&](PieceOwner color, std::array<int, 2> selection){ return m_boardController.onMove(color, selection); }
    );
    m_playerController.setOnTurnFinishListener(
        [&](PieceOwner color, bool didBust){ return m_boardController.onFinish(color, didBust); }
    );

    std::shared_ptr<GameView> view = std::make_shared<GameView>("Cant Stop Game", m_boardController, m_playerController);
    m_viewController.addView(Menu::GAME_VIEW, view);

    //relative to cmake-build-debug/sfml_test.exe
    RenderWrapper::loadFont("../resources/fonts/Roboto-Medium.ttf");
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

        m_window.clear(sf::Color(15, 23, 42));

        m_viewController.onUpdate();
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