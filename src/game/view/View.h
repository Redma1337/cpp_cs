//
// Created on 30/06/2022.
//

#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../event/IObserver.h"

class View : sf::Drawable {
protected:
    std::string m_name;
public:
    View(std::string name, int width = 800, int height = 600)
        : m_name{ name }
    {}

    View() {};

    virtual ~View() = default;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    std::string getName() const{
        return m_name;
    }
};
