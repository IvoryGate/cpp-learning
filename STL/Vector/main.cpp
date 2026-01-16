#include <iostream>
#include "vector.hpp"

int main() {
    // 测试at()
    try {
        my_vector::Vector<int> vec(5);

        for (int i = 0; i < 5; i++) {
            vec.at(i) = i * 10;
        }

        std::cout << "Vector 中的元素有：" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "index " << i << ": " << vec.at(i) << std::endl;
        }

        std::cout << "尝试访问越界元素..." << std::endl;
        std::cout << vec.at(10) << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }
    my_vector::Vector<int> vec1(5);
    my_vector::Vector<int> vec2(0);

    for (int i = 0; i < 5; i++ ){
        vec1.at(i) = i;
    }

    // 测试front()
    try{
        std::cout << "vec1.front()的值是：" << vec1.front() << std::endl;
        std::cout << "vec1.empty()的值是：" << vec1.empty() << std::endl;
        vec2.front();
    } catch (const std::logic_error& e){
        std::cerr << "错误: " << e.what() << std::endl;
    }

    // 测试back()
   try{
        std::cout << "vec1.back()的值是：" << vec1.back() << std::endl;
        std::cout << "vec2.empty()的值是：" << vec2.empty() << std::endl;
        vec2.back();
    } catch (const std::logic_error& e){
        std::cerr << "错误: " << e.what() << std::endl;
    }

    return 0;
}