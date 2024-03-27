#include <iostream>
#include <concepts>

using namespace std;

template<typename T>
concept DestroyableAndMovable = destructible<T> && move_constructible<T>;
// Add a bang before destructible for this glorious error message:
// twoconceptscleaner.cpp: In function ‘int main()’:
// twoconceptscleaner.cpp:17:6: error: no matching function for call to ‘f(int)’
//    17 |     f(1);
//       |     ~^~~
// twoconceptscleaner.cpp:11:6: note: candidate: ‘template<class T>  requires  DestroyableAndMovable<T> void f(T)’
//    11 | void f(T a) {
//       |      ^
// twoconceptscleaner.cpp:11:6: note:   template argument deduction/substitution failed:
// twoconceptscleaner.cpp:11:6: note: constraints not satisfied
// twoconceptscleaner.cpp: In substitution of ‘template<class T>  requires  DestroyableAndMovable<T> void f(T) [with T = int]’:
// twoconceptscleaner.cpp:17:6:   required from here
// twoconceptscleaner.cpp:7:9:   required for the satisfaction of ‘DestroyableAndMovable<T>’ [with T = int]
// twoconceptscleaner.cpp:7:33: note: the expression ‘!(destructible<T>) [with T = int]’ evaluated to ‘false’
//     7 | concept DestroyableAndMovable = !destructible<T> && move_constructible<T>;

template<DestroyableAndMovable T>
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