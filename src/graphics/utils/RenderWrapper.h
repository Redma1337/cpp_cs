//
// Created on 24/07/2022.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RoundedRectangleShape.h"

class RenderWrapper {
    static sf::Font DEFAULT_FONT;
public:
    static void loadFont(const std::string &str);

    static sf::Text createString(
            const std::string &msg,
            const sf::Vector2f &pos,
            int size,
            const sf::Color &color
    );

    static sf::Text createCenteredString(
            const std::string &msg,
            const sf::Vector2f &pos,
            int size,
            const sf::Color &color
    );

    static sf::ConvexShape createTriangle(
            const sf::Vector2f &pos,
            const sf::Vector2f &pt1,
            const sf::Vector2f &pt2,
            const sf::Vector2f &pt3,
            const sf::Color &color
    );

    static sf::RoundedRectangleShape createRoundedRect(
            const sf::Vector2f &pos,
            const sf::Vector2f &dim,
            const sf::Color &fillColor,
            float cornerRadius
    );
};
