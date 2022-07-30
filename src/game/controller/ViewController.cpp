//
// Created on 07/07/2022.
//

#include "ViewController.h"
#include "../view/EMenu.h"

ViewController::ViewController()
    : m_currentView{ Menu::NONE }
{}

void
ViewController::setCurrentView(Menu m) {
    m_currentView = m;

    std::shared_ptr<View> currentView = getCurrentView();
    currentView->reload();
}

void
ViewController::drawView(sf::RenderTarget &target) const {
    std::shared_ptr<View> currentView = getCurrentView();
    currentView->draw(target, sf::RenderStates::Default);
}

void
ViewController::onUpdate() {
    std::shared_ptr<View> currentView = getCurrentView();
    currentView->onUpdate();
}

void
ViewController::onClick(const sf::Vector2i &cords) const {
    std::shared_ptr<View> currentView = getCurrentView();
    currentView->onClick(cords);
}

const std::shared_ptr<View>&
ViewController::getCurrentView() const {
    return m_viewMap.at(m_currentView);
}

void
ViewController::addView(Menu pageIndex, std::shared_ptr<View> sharedView) {
    m_viewMap.insert(
            SharedViewMap::value_type(pageIndex, sharedView)
    );
}