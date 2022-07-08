//
// Created on 08/07/2022.
//

#pragma once

#include "Component.h"
#include "Column.h"
#include "../model/Model.h"

typedef std::map<int, Column> BoardModelType;

class Board : public Component, Model<BoardModelType> {
public:
    Board();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setup();
};
