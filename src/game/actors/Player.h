//
// Created on 05/07/2022.
//

#pragma once
#include "PlayerEnums.h"
#include "../../graphics/components/misc/pairing/PairSelector.h"
#include <string>
#include <array>
#include <memory>

class Player {
protected:
    typedef std::vector<PlayerAction> ActionVec;

    sf::Color m_color;
    const std::string m_name;
    const bool m_isHuman;
public:
    Player(std::string name, bool human); //pass string by value because we will std::move it
    virtual ~Player() = default;

    virtual std::array<int, 2> doSelection(PairSelector& pairSelector) = 0;
    virtual std::vector<PlayerAction> generateActions() = 0;

    void doRoll(ActionVec& actions);
    void switchPlayer(ActionVec& actions);

    sf::Color getColor() const;
    void setColor(sf::Color color);

    std::string getName() const;

    bool isHuman() const;
};
