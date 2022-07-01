#include "game/model/Model.h"
#include "game/view/TestView.h"

int main()
{
    Model<int> model;
    TestView view("Test View", model);
    model.setData(10);

    return 0;
}