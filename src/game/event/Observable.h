//
// Created on 30/06/2022.
//

#pragma once

#include <list>
#include "IObserver.h"

class IObserver;
class Observable {
public:
    virtual ~Observable() = default;
    void addObserver(IObserver& o);
    void removeObserver(IObserver& o);
    void fireEvent();
private:
    std::list<IObserver*> m_observers;
};
