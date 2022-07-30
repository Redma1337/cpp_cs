//
// Created on 30/07/2022.
//

#include "GameResultView.h"

GameResultView::GameResultView(const OnGameRestartCallback &callback)
    :   m_restartGameCallback{ callback },
        m_playAigan("Play again", {200, 50}, {400, 375}, true),
        m_quit("Quit", {200, 50}, {400, 445}, true)
{
    m_quit.addActionListener([this](const sf::Vector2i &cord) {
        exit(EXIT_SUCCESS);
    });

    m_playAigan.addActionListener([this](const sf::Vector2i &cord) {
        m_restartGameCallback();
    });
}

void
GameResultView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Text header = RenderWrapper::createCenteredString(m_winner + " won !", { 500, 250 }, 30, sf::Color::White);

    target.draw(header);
    m_playAigan.draw(target, states);
    m_quit.draw(target, states);
}

void
GameResultView::onUpdate() {}

void
GameResultView::onClick(const sf::Vector2i &cords) {
    m_playAigan.onClick(cords);
    m_quit.onClick(cords);
}

void
GameResultView::reload() {}

void
GameResultView::setWinner(const std::string &name) {
    m_winner = name;
}



