//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../controller/BoardController.h"
#include "../controller/ViewController.h"
#include "../components/Button.h"

class GameView : public View {
    std::shared_ptr<Board> m_boardComponent;
    Button m_doTurnBtn;
public:
    explicit GameView(std::string name, const std::shared_ptr<Board> &board);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;
};
