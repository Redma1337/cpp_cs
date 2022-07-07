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
    sf::CircleShape shape(80.f, 8);
    shape.setFillColor(sf::Color::Cyan);
    target.draw(shape);
}

void GameView::onModelUpdate(Observable &target) {
    std::cout << m_model.getData().size() << std::endl;
}
