#include <iostream>
#include <vector>

struct container_tag {}; // Tag för behållare med .size() funktion
struct array_tag {};      // Tag för vanliga C++-arrayer

template <typename T>
struct tag {
    using type = container_tag;
};

template <typename T, size_t N>
struct tag<T[N]> {
    using type = array_tag;
};

// För behållare med .size() funktion
template <typename T>
size_t count_elements(const T& container, container_tag) {
    return container.size();
}

// För vanliga C++-arrayer
template <typename T, size_t N>
size_t count_elements(const T(&array)[N], array_tag) {
    return N;
}

template <typename T>
size_t count_elements(const T& obj) {
    using dispatch_tag = typename tag<T>::type;
    return count_elements(obj, dispatch_tag{});
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Vector size: " << count_elements(vec) << std::endl; // Skriver ut: Vector size: 5
    std::cout << "Array size: " << count_elements(arr) << std::endl;  // Skriver ut: Array size: 5

    return 0;
}
