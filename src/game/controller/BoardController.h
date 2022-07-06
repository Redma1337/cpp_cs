//
// Created on 06/07/2022.
//

#pragma once
#include <map>
#include "../board/Column.h"
#include "../board/EBoardOperation.h"
#include "../model/Model.h"

typedef std::map<int, Column> BoardModelType;

class BoardController {
    Model<BoardModelType> m_model; //board should just wrap access functionality of model
public:
    BoardController(Model<BoardModelType> &model);
    void setupBoard();
    void executeMove(int index, BoardOperation operation);
};
