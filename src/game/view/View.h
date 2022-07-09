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
    explicit View(std::string name, int width = 800, int height = 800)
        : m_name{ std::move(name) }
    {}

    View() = default;;

    ~View() override = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

    std::string getName() const{
        return m_name;
    }
};
