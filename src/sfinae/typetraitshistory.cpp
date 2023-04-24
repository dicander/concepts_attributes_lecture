#include <iostream>
#include <type_traits>

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl; // Fungerar, eftersom int är en numerisk typ
    // std::cout << add(std::string("hello"), std::string("world")) << std::endl; // Kompileringsfel
    return 0;
}
