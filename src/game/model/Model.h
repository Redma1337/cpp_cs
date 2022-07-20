//
// Created on 30/06/2022.
//

#pragma once

template <typename T>
class Model {
    T m_data;
public:
    virtual ~Model() = default;

    Model() {}

    //this will not trigger an event
    Model(const T& initialValue) : m_data(initialValue) {}

    void setData(const T &newData) {
        m_data = newData;
    }

    //we give out copies, because we want to force setData use
    T getData() const {
        return m_data;
    }

};