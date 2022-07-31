//
// Created on 30/07/2022.
//

#pragma once

#include <functional>
#include "../View.h"
#include "../../components/misc/Button.h"

class GameResultView : public View {
    typedef std::function<void()> OnGameRestartCallback;
    OnGameRestartCallback m_restartGameCallback;

    std::string m_winner;
    Button m_quit;
    Button m_playAigan;
public:
    GameResultView(const OnGameRestartCallback &callback);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onUpdate() override;
    void onClick(const sf::Vector2i &cords) override;
    void reload() override;

    void setWinner(const std::string &name);
};
