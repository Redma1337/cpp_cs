//
// Created on 30/06/2022.
//

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../event/IObserver.h"

template <typename T>
class View : public IObserver {
    T& m_model;
    std::string m_name;
    sf::RenderTexture m_renderTexture;
public:
    explicit View(std::string name, T& model)
        : m_model{ model }, m_name{ name }
    {
        if (!m_renderTexture.create())

        m_model.addObserver(*this);
    }

    virtual ~View() {
        m_model.removeObserver(*this);
    }

    std::string getName() const{
        return m_name;
    }
};
