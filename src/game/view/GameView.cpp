//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(BoardController &board, PlayerController &playerController)
    :   m_boardController{ board },
        m_playerController{ playerController },
        m_switchPlayerBtn("Finish Round", {200, 50}, {750, 590}, true),
        m_rollDiceBtn("Roll dice", {200, 50}, {750, 650}, true),
        m_commitSelectionBtn("Commit", {200, 50}, {750, 700}, true), //just place the second button bellow, so we dont have problems with click events stacking
        m_pairSelector{ { 110, 110 }, {740, 300}, 50 },
        m_statusText{ RenderWrapper::createString("Status: " + playerController.getCurrentStatus(), {600, 50}, 20, sf::Color::White) }
{}

void
GameView::setup() {
    m_boardController.setupBoard({50, 50});
    m_commitSelectionBtn.setVisible(false);
    m_pairSelector.setVisible(false);

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
    m_statusText.setString(m_playerController.getCurrentStatus());
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
    } else {
        target.draw(m_statusText);
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

void GameView::reload() {
    setup();
}