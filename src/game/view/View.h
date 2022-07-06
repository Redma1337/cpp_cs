//
// Created on 30/06/2022.
//

#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../event/IObserver.h"

template <typename T>
class View : public IObserver {
private:
    T& m_model;

protected:
    std::string m_name;
    sf::RenderTexture m_renderTexture;

public:
    explicit View(std::string name, T& model)
        : m_model{ model }, m_name{ name }
    {
        if (!m_renderTexture.create(800, 600)) {
            std::cout << "View couldn't create render texture";
        }

        m_model.addObserver(*this);
    }

    virtual ~View() {
        m_model.removeObserver(*this);
    }

    const sf::Texture& getTexture() const {
        return m_renderTexture.getTexture();
    }

    std::string getName() const{
        return m_name;
    }
};
