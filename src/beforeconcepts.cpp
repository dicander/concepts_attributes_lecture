#include <iostream>

template <typename T>
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
