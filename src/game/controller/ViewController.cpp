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
    //todo make sure name is valid
}

void
ViewController::drawView(sf::RenderTarget &target) const {
    std::shared_ptr<View> currentView = getCurrentView();
    currentView->draw(target, sf::RenderStates::Default);
}

const std::shared_ptr<View>
ViewController::getCurrentView() const {
    return m_viewMap.at(m_currentView);
}

void
ViewController::addView(Menu pageIndex, std::shared_ptr<View> sharedView) {
    if (m_currentView == Menu::NONE) {
        m_currentView = pageIndex;
    }

    m_viewMap.insert(
            SharedViewMap::value_type(pageIndex, sharedView)
        );
}