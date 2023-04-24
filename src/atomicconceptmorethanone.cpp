#include <iostream>
#include <concepts>

template <typename T>
concept AddableAndSubtractable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
};

class MyNumber {
public:
    MyNumber(int val) : value(val) {}

    MyNumber operator+(const MyNumber& other) const {
        return MyNumber(value + other.value);
    }

    MyNumber operator-(const MyNumber& other) const {
        return MyNumber(value - other.value);
    }

    int get_value() const {
        return value;
    }

private:
    int value;
};


// Make MyNumber printable
std::ostream& operator<<(std::ostream& os, const MyNumber& obj) {
    return os << obj.get_value();
}

// A function that accepts any type that satisfies the AddableAndSubtractable concept
template <AddableAndSubtractable T>
T add_and_subtract(const T& a, const T& b) {
    return a + b - b;
}

int main() {
    MyNumber a(42);
    MyNumber b(3);

    MyNumber result = add_and_subtract(a, b); // OK: MyNumber satisfies the AddableAndSubtractable concept
    std::cout << "Result: " << result << std::endl;
    return 0;
}