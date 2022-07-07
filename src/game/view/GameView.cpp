//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, Model<BoardModelType> &model)
    : View::View(name), m_model{ model }
{
    m_model.addObserver(*this);
}

GameView::~GameView() {
    m_model.removeObserver(*this);
}

void
GameView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    const sf::Vector2f collDim = { 50, 50 };
    for (auto const& pair : m_model.getData()) {
        Column col = pair.second;
        col.draw(target, states);
    }
}

void GameView::onModelUpdate(Observable &target) {
    std::cout << m_model.getData().size() << std::endl;
}
