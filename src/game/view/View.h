//
// Created on 30/06/2022.
//

#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "IClickable.h"

class View : sf::Drawable, IClickable {
protected:
public:
    View() = default;

    ~View() override = default;

    //this is not implemented -> keep it virtual
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void onUpdate() = 0;
    virtual void onClick(const sf::Vector2i &cords) = 0;
};
