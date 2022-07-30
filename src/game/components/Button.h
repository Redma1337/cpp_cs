//
// Created on 15/07/2022.
//

#pragma once

#include <functional>
#include "Component.h"
#include "../view/IClickable.h"
#include "../wrapper/RenderWrapper.h"

class Button : public Component, IClickable {
    typedef std::function<void(const sf::Vector2i&)> ButtonCallback;

    ButtonCallback m_callback;
    sf::Color m_color;
    std::string m_text;
    bool m_isRounded;
public:
    Button(const std::string &text, const sf::Vector2f &dim, const sf::Vector2f &pos, bool isRounded);
    Button(const std::string &text, const sf::Vector2f &dim);
    Button(const std::string &text);

    void addActionListener(ButtonCallback callback);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;

    //this is used by bots to simulate human behaviour
    void click();

    void setColor(const sf::Color &color);
    void setText(const std::string &text);
};
