//
// Created on 30/06/2022.
//


#include <algorithm>
#include "Observable.h"

void Observable::addObserver(IObserver& o) {
    m_observers.push_back(&o);
    int x = m_observers.size();
}

void Observable::removeObserver(IObserver& o) {
    m_observers.remove(&o);
}

void Observable::fireEvent() {
    int x = m_observers.size();
    for (auto* o : m_observers) {
        o->onUpdate(*this);
    }
}
