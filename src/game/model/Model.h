//
// Created on 30/06/2022.
//

#pragma once

#include "../event/Observable.h"

template <typename T>
class Model : public Observable {
     T m_data;
public:
    virtual ~Model() = default;

    void setData(const T& newData) {
        m_data = newData;

        fireEvent();
    }

    T getData() const {
        return m_data;
    }
};