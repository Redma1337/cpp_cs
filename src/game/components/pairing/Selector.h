//
// Created on 30/07/2022.
//

#pragma once

#include <list>
#include "../Button.h"
#include "../../Theme.h"

template <typename T>
class Selector : public Component, IClickable {
    std::vector<Button> m_buttons;
    std::vector<T> m_data;
    std::vector<T> m_selection;
    int m_selections;
    bool m_locked;
public:
    Selector(const sf::Vector2f &dim, const sf::Vector2f &pos, int selections)
        : Component(dim, pos), m_selections{ selections }, m_locked{ false }
    {}

    void setData(const std::map<std::string, T> data) {
        int yOff = 0;
        for (auto const &pair : data)  {
            Button btn(pair.first, { 200, 50 }, { m_position.x, m_position.y + yOff }, true);
            m_buttons.push_back(btn);
            m_data.push_back(pair.second);
            yOff += 60;
        }
        initListeners();
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
          for (const Button &b : m_buttons) {
              b.draw(target, states);
          }
    }

    void onClick(const sf::Vector2i &cords) override {
        if (m_locked) {
            return;
        }

        for (Button &b : m_buttons) {
            b.onClick(cords);
        }
    }

    virtual void reset() {
        m_selection = {};
        for (Button &b : m_buttons) {
            b.setColor(Theme::BUTTON_COLOR_DEFAULT);
            b.setLocked(false);
        }
    }

    virtual void click(int buttonIndex) {
        m_buttons[buttonIndex].click();
    }

    virtual void initListeners() {
        for (int i = 0; i < m_buttons.size(); i++) {
            m_buttons[i].addActionListener([&, i](const sf::Vector2i &cords){
                onBtnClick(i, m_buttons[i]);
            });
        }
    }

    virtual void onBtnClick(int index, Button &btn) {
        reset();
        m_selection.push_back(m_data[index]);
        btn.setColor(Theme::BUTTON_COLOR_SELECTED);
    }

    bool isSelectionFinished() const {
        return m_selection.size() >= m_selections;
    }

    std::vector<T> getSelection() const {
        return m_selection;
    }
};
