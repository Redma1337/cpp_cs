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

    float offsetX = pos.x - (text.getGlobalBounds().width / 2);

    //internal height calculation might be off, this should be height / 2, but it is not
    float offsetY = pos.y - (text.getGlobalBounds().height);
    text.setPosition({ offsetX, offsetY });
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
