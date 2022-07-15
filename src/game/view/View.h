//
// Created on 30/06/2022.
//

#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../event/IObserver.h"
#include "IClickable.h"

class View : sf::Drawable, IClickable {
protected:
    std::string m_name;
public:
    explicit View(std::string name, int width = 800, int height = 800)
        : m_name{ std::move(name) }
    {}

    View() = default;

    ~View() override = default;

    //this is not implemented -> keep it virtual
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void onClick(const sf::Vector2i &cords) {};

    std::string getName() const{
        return m_name;
    }
};
