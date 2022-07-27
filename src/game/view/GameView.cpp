//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, BoardController &board, PlayerController &playerController)
    : View(name),
        m_boardController{ board },
        m_playerController{ playerController },
        m_switchPlayerBtn("Finish Round", {200, 50}, {700, 590}),
        m_rollDiceBtn("Roll dice", {200, 50}, {700, 650}),
        m_commitSelectionBtn("Commit", {200, 50}, {700, 700}), //just place the second button bellow, so we dont have problems with click events stacking
        m_pairSelector{ { 110, 110 }, {740, 300}, 50 }
{
    m_commitSelectionBtn.setVisible(false);
    m_pairSelector.setVisible(false);
    setup();
}

void
GameView::setup() {
    m_rollDiceBtn.addActionListener([this](const sf::Vector2i &cord) {
        m_rollDiceBtn.setVisible(false);
        m_switchPlayerBtn.setVisible(false);
        m_commitSelectionBtn.setVisible(true);

        m_playerController.enqueueAction(EPlayerAction::ROLL_DICE);
    });

    m_commitSelectionBtn.addActionListener([this](const sf::Vector2i &cord) {
        m_commitSelectionBtn.setVisible(false);

        m_rollDiceBtn.setVisible(true);
        m_switchPlayerBtn.setVisible(true);

        m_playerController.enqueueAction(EPlayerAction::MAKE_SELECTION);
    });

    m_switchPlayerBtn.addActionListener([this](const sf::Vector2i &cord) {
        m_playerController.enqueueAction(EPlayerAction::SWITCH_PLAYER);
    });
}

void
GameView::onUpdate() {
    m_playerController.update(m_pairSelector);
}

void
GameView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (m_playerController.isHumanMoving()) {
        if (m_pairSelector.isSelectionFinished()) {
            m_commitSelectionBtn.draw(target, states);
        }

        m_rollDiceBtn.draw(target, states);
        m_switchPlayerBtn.draw(target, states);
    }

    m_pairSelector.draw(target, states);
    m_boardController.drawBoard(target);
}

void
GameView::onClick(const sf::Vector2i &cords) {
    if (m_playerController.isHumanMoving()) {
        if (m_pairSelector.isSelectionFinished()) {
            m_commitSelectionBtn.onClick(cords);
        }

        m_rollDiceBtn.onClick(cords);
        m_pairSelector.onClick(cords);
    }
    m_switchPlayerBtn.onClick(cords);
}