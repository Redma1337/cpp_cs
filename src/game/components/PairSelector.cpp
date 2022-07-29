//
// Created on 16/07/2022.
//

#include <iostream>
#include "PairSelector.h"
#include "../controller/DiceController.h"

PairSelector::PairSelector(const sf::Vector2f &dim, const sf::Vector2f &pos, float bS)
    :   Component(dim, pos),
        m_selectedCount{ 0 },
        m_selectorButtons {
            Button("", { bS, bS }, {m_position.x , m_position.y }),
            Button("", { bS, bS }, {m_position.x + bS + 10, m_position.y }),
            Button("", { bS, bS }, {m_position.x, m_position.y + bS + 10 }),
            Button("", { bS, bS }, {m_position.x + bS + 10, m_position.y + bS + 10 }),
        },
        m_selection{ 0 }
{
    setup();
}

void
PairSelector::setup() {
    for (int i = 0; i < m_selectorButtons.size(); i++) {
        m_selectorButtons[i].addActionListener([&, i](const sf::Vector2i &cords){
            int pair_index = m_selectedCount >= 2 ? 1 : 0;
            m_selection[pair_index] += m_diceRoll[i];
            m_selectorButtons[i].setColor(pair_index == 0 ? sf::Color::Green : sf::Color::Blue);
            m_selectorButtons[i].setLocked(true);
            m_selectedCount++;
        });
    }
}

void
PairSelector::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    std::for_each(m_selectorButtons.begin(), m_selectorButtons.end(), [&](const Button &btn) {
        btn.draw(target, states);
    });
}

void
PairSelector::onClick(const sf::Vector2i &cords) {
    if (isLocked() || !isVisible()) {
        return;
    }

    std::for_each(m_selectorButtons.begin(), m_selectorButtons.end(), [&](Button &btn) {
        btn.onClick(cords);
    });
}

void
PairSelector::reRoll() {
    reset();
    m_diceRoll = DiceController::rollDices();
    for (int i = 0; i < m_selectorButtons.size(); i++) {
        m_selectorButtons[i].setText(std::to_string(m_diceRoll[i]));
    }
}

void
PairSelector::reset() {
    m_selectedCount = 0;
    m_selection = {0, 0};
    for (int i = 0; i < m_selectorButtons.size(); i++) {
        m_selectorButtons[i].setColor(sf::Color(20, 20, 20, 100));
        m_selectorButtons[i].setLocked(false);
    }
}

void
PairSelector::clickButton(int i) {
    m_selectorButtons[i].click();
}

bool
PairSelector::isSelectionFinished() const {
    return m_selectedCount == 4;
}

std::array<int, 2>
PairSelector::getDecision() const {
    return m_selection;
}

