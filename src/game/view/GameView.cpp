//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, const std::shared_ptr<Board> &board)
    : m_boardComponent{ board }, View(name)
{}

void
GameView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    m_boardComponent->draw(target, states);
}
