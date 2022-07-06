//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../controller/BoardController.h"

class GameView : public View<Model<BoardModelType>> {
public:
    explicit GameView(std::string name, Model<BoardModelType> &model);

    ~GameView() {}

    void onUpdate(Observable& target) override;
};
