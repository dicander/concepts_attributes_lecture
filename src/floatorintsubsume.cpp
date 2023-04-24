#include <iostream>
#include <concepts>

using namespace std;

template<typename T>
    requires floating_point<T> || integral<T>
void f(T a) {
    std::cout << "We got a number! f(" << a << ")\n";
}

template<typename T>
    requires floating_point<T>
void f(T a) {
    std::cout << "We got a float! f(" << a << ")\n";
}

template<typename T>
    requires floating_point<T> && destructible<T>
void f(T a) {
    std::cout << "We got a float, and it can be destroyed! f(" << a << ")\n";
}

template<typename T>
    requires integral<T>
void f(T a) {
    std::cout << "We got an integral! f(" << a << ")\n";
}

int main() {
    f(1);
    f(1.0);
    f(1.0f);
    f(1l);
    f(1ll);
    f(1ul);
    f(1ull);
    return 0;
}