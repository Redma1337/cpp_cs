//
// Created on 30/06/2022.
//

#include "TestView.h"

TestView::TestView(std::string name, TestViewType &model)
    : View<TestViewType>::View(name, model)
{}

void TestView::onUpdate(Observable &target) {
    std::cout << "target data updated on view!" << std::endl;
}