//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, const std::shared_ptr<Board> &board, PlayerController &playerController)
    : View(name),
        m_boardComponent{ board },
        m_playerController{ playerController },
        m_doTurnBtn({200, 50}, {700, 650}),
        m_pairSelector{ { 110, 110 }, {740, 300}, 50 }
{
    m_doTurnBtn.addActionListener([this](const sf::Vector2i &cord) {
        m_pairSelector.reRoll();
    });
}

void
GameView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    m_boardComponent->draw(target, states);
    m_doTurnBtn.draw(target, states);
    m_pairSelector.draw(target, states);
}

void
GameView::onClick(const sf::Vector2i &cords) {
    m_doTurnBtn.onClick(cords);
    m_pairSelector.onClick(cords);
}