#include <iostream>
#include <concepts>

template <typename T>
concept HasX = requires(T obj) {
    { obj.x } -> std::convertible_to<int>;
};

class MyClass {
public:
    int x;
};

class AnotherClass {
public:
    float x;
};

// A function that accepts any type that satisfies the HasX concept
template <HasX T>
void print_x(const T& obj) {
    std::cout << "x value: " << obj.x << std::endl;
}

int main() {
    MyClass a;
    a.x = 42;

    AnotherClass b;
    b.x = 3.14f;

    print_x(a); // OK: MyClass has an int x member
    print_x(b); // OK: AnotherClass has a float x member, which is convertible to int

    return 0;
}
