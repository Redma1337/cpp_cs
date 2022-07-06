//
// Created on 30/06/2022.
//

#include "GameView.h"

GameView::GameView(std::string name, Model<BoardModelType> &model)
    : View<Model<BoardModelType>>::View(name, model)
{}

void GameView::onUpdate(Observable &target) {
    std::cout << "target data updated on view!" << std::endl;
}