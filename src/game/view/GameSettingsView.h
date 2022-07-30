//
// Created on 30/07/2022.
//

#pragma once

#include "View.h"
#include "../controller/PlayerController.h"
#include "../components/pairing/Selector.h"

class GameSettingsView : public View {
    typedef std::shared_ptr<Player> SharedPlayer;
    typedef std::function<void(SharedPlayer, SharedPlayer)> OnGameStartCallback;

    OnGameStartCallback m_startGameCallback;

    Button m_startGameBtn;
    Selector<std::shared_ptr<Player>> m_selectorOne;
    Selector<std::shared_ptr<Player>> m_selectorTwo;
public:
    explicit GameSettingsView(const OnGameStartCallback &playerController);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onUpdate() override;
    void onClick(const sf::Vector2i &cords) override;
    void reload() override;
};
