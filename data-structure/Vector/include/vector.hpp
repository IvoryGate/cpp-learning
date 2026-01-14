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
}