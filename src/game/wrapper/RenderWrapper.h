//
// Created on 24/07/2022.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class RenderWrapper {
    static sf::Font DEFAULT_FONT;
public:
    static void loadFont(const std::string &str);

    static const sf::Text createString(
        const std::string &msg,
        const sf::Vector2f &pos,
        int size,
        const sf::Color &color
    );

    static const sf::Text createCenteredString(
        const std::string &msg,
        const sf::Vector2f &pos,
        int size,
        const sf::Color &color
    );
};
