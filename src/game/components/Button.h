//
// Created on 15/07/2022.
//

#pragma once

#include <functional>
#include "Component.h"
#include "../view/IClickable.h"
#include "../wrapper/RenderWrapper.h"

class Button : public Component, IClickable {
    std::function<void(const sf::Vector2i)> m_callback;
    sf::Color m_color;
    std::string m_text;
public:
    Button(const std::string &text, const sf::Vector2f &dim, const sf::Vector2f &pos);
    Button(const std::string &text, const sf::Vector2f &dim);
    Button(const std::string &text);

    void addActionListener(std::function<void(const sf::Vector2i)> callback);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;

    //this is used by bots to simulate human behaviour
    void click();

    void setColor(const sf::Color &color);
    void setText(const std::string &text);
};
