//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, const std::shared_ptr<Board> &board)
    : View(name),
        m_boardComponent{ board },
        m_doTurnBtn({100, 50}, {650, 50})
{
    m_doTurnBtn.addActionListener([](const sf::Vector2i &cord) {
        std::cout << "Button Clicked!" << std::endl;
    });
}

void
GameView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    m_boardComponent->draw(target, states);
    m_doTurnBtn.draw(target, states);
}

void
GameView::onClick(const sf::Vector2i &cords) {
    m_doTurnBtn.onClick(cords);
}