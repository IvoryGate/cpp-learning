#pragma once

namespace vector {
    template <typename T>
    class Vector
    {
        private:
            T* m_data;
            int size;
            int capacity;

        public:
            Vector(/* args */);
            ~Vector();

            T & at(int index);
            const T & at(int index) const;
        };
        
        Vector::Vector(/* args */)
        {
        }
        
        Vector::~Vector()
        {
    }

    template <typename T>
    Vector<T>::Vector() : m_data(nullptr), size(0), capacity(0) {

    }

    template <typename T>
    Vector<T>::~Vector() {
        delete[] m_data;
    }

    template <typename T>
    T& Vector<T>::at(int index) {
        return m_data[index];
    }

    template <typename T>
    const T& Vector<T>::at(int index) const {
        return m_data[index];
    }
}