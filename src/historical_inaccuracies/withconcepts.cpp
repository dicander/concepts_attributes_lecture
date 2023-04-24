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

class MyClass {};

int main() {
    MyClass a, b;
    auto result = add(a, b); // Felaktig användning av add med icke-numeriska typer
    std::cout << result << std::endl;
    return 0;
}