//
// Created on 30/06/2022.
//


#include <algorithm>
#include "Observable.h"

void Observable::addObserver(IObserver& o) {
    m_observers.push_back(&o);
}

void Observable::removeObserver(IObserver& o) {
    m_observers.remove(&o);
}

void Observable::fireEvent() {
    for (auto* o : m_observers) {
        o->onModelUpdate(*this);
    }
}
