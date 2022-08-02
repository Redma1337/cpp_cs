//
// Created on 30/07/2022.
//

#include "GameSettingsView.h"
#include "../../../game/actors/players/HumanPlayer.h"
#include "../../utils/RenderWrapper.h"
#include "../../../game/actors/players/RandomBot.h"
#include "../../../game/actors/players/GreedyBot.h"
#include "../../../game/actors/players/HesitantBot.h"
#include "../../../game/actors/players/IntelligentBot.h"

GameSettingsView::GameSettingsView(const OnGameStartCallback &callback)
    :   m_startGameCallback{ callback },
        m_startGameBtn("Play", {200, 50}, {400, 700}, true),
        m_startBenchmarkBtn("Benchmark", {200, 50}, {400, 760}, true),
        m_selectorOne{ {200, 200}, {200, 350}, 1 },
        m_selectorTwo{ {200, 200}, {600, 350}, 1 }
{
    std::map<std::string, std::shared_ptr<Player>> data = {
            { "Human", std::make_shared<HumanPlayer>() },
            { "Random Bot", std::make_shared<RandomBot>() },
            { "Greedy Bot", std::make_shared<GreedyBot>() },
            { "Hesitant Bot", std::make_shared<HesitantBot>() },
            { "Intelligent Bot", std::make_shared<IntelligentBot>() },
    };

    m_selectorOne.setData(data);
    m_selectorTwo.setData(data);

    m_startGameBtn.addActionListener([this](const sf::Vector2i &cord) {
        auto playerOne = m_selectorOne.getSelection()[0];
        auto playerTwo = m_selectorTwo.getSelection()[0];
        m_startGameCallback(playerOne, playerTwo);
    });

    m_startBenchmarkBtn.addActionListener([this](const sf::Vector2i &cord) {
        auto playerOne = m_selectorOne.getSelection()[0];
        auto playerTwo = m_selectorTwo.getSelection()[0];
        m_startBenchmarkCallback(playerOne, playerTwo);
    });
}

void GameSettingsView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Text header = RenderWrapper::createCenteredString("Choose your match-up!", { 500, 250 }, 40, sf::Color::White);
    sf::Text vsLbl = RenderWrapper::createCenteredString("vs.", { 500, 500 }, 40, sf::Color::White);

    target.draw(header);
    target.draw(vsLbl);
    m_selectorOne.draw(target, states);
    m_selectorTwo.draw(target, states);

    if (m_selectorOne.isSelectionFinished() && m_selectorTwo.isSelectionFinished()) {
        m_startGameBtn.draw(target, states);
        m_startBenchmarkBtn.draw(target, states);
    }
}

void GameSettingsView::onUpdate() {}

void GameSettingsView::onClick(const sf::Vector2i &cords) {
    m_selectorOne.onClick(cords);
    m_selectorTwo.onClick(cords);
    m_startGameBtn.onClick(cords);
    m_startBenchmarkBtn.onClick(cords);
}

void GameSettingsView::reload() {
    m_selectorTwo.reset();
    m_selectorOne.reset();
}

void
GameSettingsView::addBenchmarkStartedListener(const OnGameBenchmarkCallback &callback) {
    m_startBenchmarkCallback = callback;
}
