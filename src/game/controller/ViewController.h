//
// Created on 07/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "../view/View.h"
#include "../view/EMenu.h"

class ViewController {
    typedef std::map<Menu, std::shared_ptr<View>> SharedViewMap;

    SharedViewMap m_viewMap;
    Menu m_currentView;
public:
    ViewController();

    void setCurrentView(Menu m);
    const std::shared_ptr<View> getCurrentView() const;

    void addView(Menu pageIndex, std::shared_ptr<View> sharedView);

    void drawView(sf::RenderTarget& target) const;
    void onClick(const sf::Vector2i &cords) const;
    void onUpdate();
};
