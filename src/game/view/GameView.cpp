//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::TestView(std::string name, TestViewType &model)
    : View<TestViewType>::View(name, model)
{}

void GameView::onUpdate(Observable &target) {
    std::cout << "target data updated on view!" << std::endl;
}