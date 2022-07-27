//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../controller/BoardController.h"
#include "../controller/ViewController.h"
#include "../components/Button.h"
#include "../controller/PlayerController.h"

class GameView : public View {
    std::shared_ptr<Board> m_boardComponent;
    PlayerController &m_playerController;

    Button m_rollDiceBtn;
    Button m_commitSelectionBtn;
    Button m_switchPlayerBtn;

    PairSelector m_pairSelector;
public:
    explicit GameView(std::string name, const std::shared_ptr<Board> &board, PlayerController &playerController);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onUpdate() override;

    void onClick(const sf::Vector2i &cords) override;

    void setup();
};