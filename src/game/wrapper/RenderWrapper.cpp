//
// Created on 24/07/2022.
//

#include "RenderWrapper.h"

sf::Font RenderWrapper::DEFAULT_FONT;

void
RenderWrapper::loadFont(const std::string &str) {
    if (!DEFAULT_FONT.loadFromFile(str)) {
        std::cout << "Couldn't load font from directory!" << std::endl;
    }
}

const sf::Text
RenderWrapper::createCenteredString(
        const std::string &msg,
        const sf::Vector2f &pos,
        int size,
        const sf::Color &color)
{
    sf::Text text;
    text.setFont(DEFAULT_FONT);
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(size);
    text.setStyle(sf::Text::Regular);

    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(pos);
    return text;
}

const sf::Text
RenderWrapper::createString(
        const std::string &msg,
        const sf::Vector2f &pos,
        int size,
        const sf::Color &color)
{
    sf::Text text;
    text.setFont(DEFAULT_FONT);
    text.setPosition(pos);
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(size);
    text.setStyle(sf::Text::Regular);
    return text;
}

const sf::ConvexShape
RenderWrapper::createTriangle(
        const sf::Vector2f &pos,
        const sf::Vector2f &pt1,
        const sf::Vector2f &pt2,
        const sf::Vector2f &pt3,
        const sf::Color &color)
{
    sf::ConvexShape triangle;
    triangle.setPosition(pos);
    triangle.setPointCount(3);
    triangle.setPoint(0, pt1);
    triangle.setPoint(1, pt2);
    triangle.setPoint(2, pt3);
    triangle.setFillColor(color);
    return triangle;
}
