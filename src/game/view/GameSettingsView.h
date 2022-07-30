//
// Created on 30/07/2022.
//

#pragma once

#include "View.h"

class GameSettingsView : public View {
public:
    GameSettingsView(std::string name);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onUpdate() override;
    void onClick(const sf::Vector2i &cords) override;
};
