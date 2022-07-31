//
// Created on 15/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>

class IClickable {
    virtual void onClick(const sf::Vector2i &cords) = 0;
};