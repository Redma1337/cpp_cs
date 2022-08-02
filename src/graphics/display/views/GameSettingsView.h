//
// Created on 30/07/2022.
//

#pragma once

#include "../../../game/actors/Player.h"
#include "../View.h"
#include "../../components/misc/pairing/Selector.h"

class GameSettingsView : public View {
    typedef std::shared_ptr<Player> SharedPlayer;
    typedef std::function<void(SharedPlayer, SharedPlayer)> OnGameStartCallback;
    typedef std::function<void(SharedPlayer, SharedPlayer)> OnGameBenchmarkCallback;

    OnGameStartCallback m_startGameCallback;
    OnGameBenchmarkCallback m_startBenchmarkCallback;

    Button m_startGameBtn;
    Button m_startBenchmarkBtn;
    Selector<SharedPlayer> m_selectorOne;
    Selector<SharedPlayer> m_selectorTwo;
public:
    explicit GameSettingsView(const OnGameStartCallback &callback);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onUpdate() override;
    void onClick(const sf::Vector2i &cords) override;
    void addBenchmarkStartedListener(const OnGameBenchmarkCallback &callback);
    void reload() override;
};
