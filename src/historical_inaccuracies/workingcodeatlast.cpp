#include <iostream>
#include <concepts>

template <typename T>
concept Addable = requires (T a, T b) {
    { a + b } -> std::same_as<T>;
};

template <Addable T>
T add(T a, T b) {
    return a + b;
}

class MyClass {
public:
    int value;

    MyClass() : value(0) {}
    MyClass(int v) : value(v) {}

    MyClass operator+(const MyClass& other) const {
        return MyClass(value + other.value);
    }
};

int main() {
    MyClass a(3), b(5);
    auto result = add(a, b); // Nu fungerar add() korrekt med MyClass-objekt
    std::cout << result.value << std::endl;
    return 0;
}
