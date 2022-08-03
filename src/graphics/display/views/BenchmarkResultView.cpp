//
// Created on 02.08.2022.
//

#include "BenchmarkResultView.h"
#include "../../utils/RenderWrapper.h"

BenchmarkResultView::BenchmarkResultView(const OpenSettingsScreenCallback &callback, Benchmark &benchmark)
    :   View(),
        m_backBtn("Back", {200, 50}, {400, 445}, true),
        m_openSettingsCallback{ callback },
        m_benchmark{ benchmark }
{
    m_firstPlayerResult = RenderWrapper::createCenteredString("", { 350, 300 }, 30, sf::Color::White);
    m_secondPlayerResult = RenderWrapper::createCenteredString("", { 350, 350 }, 30, sf::Color::White);
    m_backBtn.addActionListener([&](auto cords) {
        m_openSettingsCallback();
    });
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
BenchmarkResultView::onUpdate() {
    std::string first = "Player one wins: " + std::to_string(m_benchmark.getFirstPlayerWins());
    std::string second = "Player two wins: " + std::to_string(m_benchmark.getSecondPlayerWins());

    std::string firstPerc = std::to_string(m_benchmark.getPercentage(PieceOwner::PLAYER_ONE));
    std::string secondPerc = std::to_string(m_benchmark.getPercentage(PieceOwner::PLAYER_TWO));
    first += " (" + firstPerc.substr(0, firstPerc.find(".")+3) + "%)";
    second += " (" + secondPerc.substr(0, secondPerc.find(".")+3) + "%)";
    m_firstPlayerResult.setString(first);
    m_secondPlayerResult.setString(second);
}

void BenchmarkResultView::reload() {
}
