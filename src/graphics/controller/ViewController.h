//
// Created on 07/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "../display/MenuEnum.h"
#include "../display/View.h"

class ViewController {
    typedef std::shared_ptr<View> SharedView;
    typedef std::map<Menu, SharedView> SharedViewMap;

    SharedViewMap m_viewMap;
    Menu m_currentView;
public:
    ViewController();

    void setCurrentView(Menu m);
    const SharedView getCurrentView() const;

    void addView(Menu pageIndex, const SharedView& sharedView);

    void drawView(sf::RenderTarget& target) const;

    void onClick(const sf::Vector2i &cords) const;
    void onUpdate();
};
