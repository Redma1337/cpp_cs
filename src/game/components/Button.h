//
// Created on 15/07/2022.
//

#pragma once

#include <functional>
#include "Component.h"
#include "../view/IClickable.h"

class Button : public Component, IClickable {
    std::function<void(const sf::Vector2i)> m_callback;
public:
    Button(const sf::Vector2f &dim, const sf::Vector2f &pos);

    void addActionListener(std::function<void(const sf::Vector2i)> callback);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;
};
