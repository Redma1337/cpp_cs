//
// Created on 02.08.2022.
//

#include "BenchmarkResultView.h"
#include "../../utils/RenderWrapper.h"

BenchmarkResultView::BenchmarkResultView(const OpenSettingsScreenCallback &callback, Benchmark &benchmark)
    :   View(),
        m_backBtn("Quit", {200, 50}, {400, 445}, true),
        m_openSettingsCallback{ callback },
        m_benchmark{ benchmark }
{
    std::string text = "Player one wins: " + std::to_string(m_benchmark.getFirstPlayerWins());
    m_firstPlayerResult = RenderWrapper::createCenteredString(text, { 400, 300 }, 30, sf::Color::White);

    text = "Player two wins: " + std::to_string(m_benchmark.getSecondPlayerWins());
    m_secondPlayerResult = RenderWrapper::createCenteredString(text, { 400, 350 }, 30, sf::Color::White);
}

void
BenchmarkResultView::onClick(const sf::Vector2i &cords) {
    m_backBtn.onClick(cords);
}

void
BenchmarkResultView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    m_backBtn.draw(target, states);
    target.draw(m_firstPlayerResult);
    target.draw(m_secondPlayerResult);
}

void
BenchmarkResultView::onUpdate() {}

void BenchmarkResultView::reload() {
}
