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

void
RenderWrapper::drawString(
        sf::RenderTarget &ctx,
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
    ctx.draw(text);
}
