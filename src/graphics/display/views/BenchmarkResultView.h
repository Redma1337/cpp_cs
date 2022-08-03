//
// Created on 02.08.2022.
//

#pragma once

#include "../View.h"
#include "../../../game/actors/PlayerEnums.h"
#include "../../components/misc/Button.h"
#include "../../../game/benchmarking/Benchmark.h"

class BenchmarkResultView : public View {
    typedef std::function<void()> OpenSettingsScreenCallback;
    OpenSettingsScreenCallback m_openSettingsCallback;

    Benchmark &m_benchmark;

    Button m_backBtn;
    sf::Text m_firstPlayerResult;
    sf::Text m_secondPlayerResult;
public:
    explicit BenchmarkResultView(const OpenSettingsScreenCallback &callback, Benchmark &benchmark);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void onClick(const sf::Vector2i &cords) override;
    void onUpdate() override;
    void reload() override;
};
