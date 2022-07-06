//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, Model<BoardModelType> &model)
    : View<Model<BoardModelType>>::View(name, model)
{}

bool test = true;
void GameView::onUpdate(Observable &target) {
    m_renderTexture.clear();

    sf::CircleShape shape(80.f, 8);
    shape.setFillColor(test ? sf::Color::Cyan : sf::Color::Red);
    test = !test;
    m_renderTexture.draw(shape);

    m_renderTexture.display();
}