#pragma once
#include <stdexcept>

namespace my_vector {
    template <typename T>
    class Vector
    {
        private:
            T* m_data;
            int m_size;
            int m_capacity;

        public:
            Vector(int initial_capacity = 10);
            ~Vector();

            T & at(int index);
            const T & at(int index) const;

            T & front();
            const T & front() const;

            T & back();
            const T & back() const;

            bool empty() const;
    };

    template <typename T>
    Vector<T>::Vector(int initial_capacity) : 
        m_data(initial_capacity > 0 ? new T[initial_capacity]() : nullptr), 
        m_size(initial_capacity > 0 ? initial_capacity : 0), 
        m_capacity(initial_capacity > 0 ? initial_capacity : 0)
    { }

    template <typename T>
    Vector<T>::~Vector() {
        if (m_data != nullptr) {
            delete [] m_data;
        }
        m_size = 0;
        m_capacity = 0;
    }

    template <typename T>
    T & Vector<T>::at(int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("out of range");
        }
        return m_data[index];
    }

    template <typename T>
    const T & Vector<T>::at(int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("out of range");
        }
        return m_data[index];
    }

    template <typename T>
    T & Vector<T>::front(){
        if (empty()) {
            throw std::logic_error("front() called on empty vector");
        }
        return m_data[0];
    }

    template <typename T>
    const T & Vector<T>::front() const {
        if (empty()) {
            throw std::logic_error("front() called on empty vector");
        }
        return m_data[0];
    }

    template <typename T>
    T & Vector<T>::back(){
        if (empty()) {
            throw std::logic_error("back() called on empty vector");
        }
        return m_data[m_size - 1];
    }

    template <typename T>
    const T & Vector<T>::back() const {
        if (empty()) {
            throw std::logic_error("back() called on empty vector");
        }
        return m_data[m_size - 1];
    }

    template <typename T>
    bool Vector<T>::empty() const {
        if (m_size <= 0 || m_data == nullptr) {
            return true;
        }else {
            return false;
        }
    }
}