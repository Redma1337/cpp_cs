//
// Created on 16/07/2022.
//

#pragma once

#include "../../Component.h"
#include "../../IClickable.h"
#include "../Button.h"
#include <array>

class PairSelector : public Component, IClickable {
    /*
     * Button index position
     *          0 1
     *          2 3
     */
    std::array<Button, 4> m_selectorButtons;
    std::array<int, 4> m_diceRoll;
    std::array<int, 2> m_selection;
    int m_selectedCount;
public:
    PairSelector(const sf::Vector2f &dim, const sf::Vector2f &pos, float buttonSize);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;

    void setup();
    void reRoll();
    void reset();
    void clickButton(int i);

    std::array<int, 4> getRoll() const;

    bool isSelectionFinished() const;
    std::array<int, 2> getDecision() const;
};
