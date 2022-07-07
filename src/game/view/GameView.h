//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../controller/BoardController.h"

class GameView : public View, IObserver {
    Model<BoardModelType>& m_model;
public:
    explicit GameView(std::string name, Model<BoardModelType> &model);

    ~GameView();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void onModelUpdate(Observable& target) override;
};
