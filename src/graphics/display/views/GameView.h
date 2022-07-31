//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "../View.h"
#include "../../../game/controller/PlayerController.h"
#include "../../controller/BoardController.h"

class GameView : public View {
    BoardController &m_boardController;
    PlayerController &m_playerController;

    Button m_rollDiceBtn;
    Button m_commitSelectionBtn;
    Button m_switchPlayerBtn;

    sf::Text m_statusText;

    PairSelector m_pairSelector;
public:
    GameView(BoardController &board, PlayerController &playerController);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;
    void onUpdate() override;
    void reload() override;

    void setup();
};