//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../model/Model.h"

typedef Model<int> TestViewType;

class GameView : public View<TestViewType> {
public:
    explicit GameView(std::string name, TestViewType &model);

    ~GameView() {}

    void onUpdate(Observable& target) override;
};
