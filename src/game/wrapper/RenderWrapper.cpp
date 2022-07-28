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
