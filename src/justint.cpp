#include <iostream>
#include <concepts>

using namespace std;

template<typename T>
    requires integral<T>
void f(T a) {
    std::cout << "f(" << a << ")\n";
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