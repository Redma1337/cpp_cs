//
// Created on 30/06/2022.
//

#pragma once

#include "Observable.h"

class Observable;
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onUpdate(Observable&) = 0;
};
