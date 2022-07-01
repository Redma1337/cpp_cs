//
// Created on 30/06/2022.
//

#pragma once
#include <iostream>
#include "View.h"
#include "../model/Model.h"

typedef Model<int> TestViewType;

class TestView : public View<TestViewType> {
public:
    explicit TestView(std::string name, TestViewType &model);

    ~TestView() {}

    void onUpdate(Observable& target) override;
};
