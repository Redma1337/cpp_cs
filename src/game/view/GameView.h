//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../controller/BoardController.h"
#include "../controller/ViewController.h"

class GameView : public View {
    std::shared_ptr<Board> m_boardComponent;
public:
    explicit GameView(std::string name, const std::shared_ptr<Board> &board);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
