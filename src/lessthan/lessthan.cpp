#include <iostream>
#include <concepts>

using namespace std;

//create a concept that tests if a type implements less than

template <typename T>
concept LessThanComparable = requires (T a, T b) {
    { a < b } -> std::same_as<bool>;
};

// Now do a similar one, but instead of that syntax, try to use the
// syntax operator<(a,b) -> bool and see what happens

template <typename T>
concept LessThanComparable2 = requires (T a, T b) {
    { operator<(a,b) } -> std::same_as<bool>; // This does not express the same thing as the previous one
    // What it does express is that the operator is defined for the type T.
};

// Now we try to use both and see what happens. Naturally this does not do what we want since the last one does not
// either.

template <typename T>
concept LessThanComparable3 = requires (T a, T b) {
    { a < b } -> std::same_as<bool>;
    { operator<(a,b) } -> std::same_as<bool>;
};

// Write a main function that uses all three concepts, once for each.
int main() {
    int a = 3, b = 5;
    LessThanComparable auto result = a < b;
    //LessThanComparable2 auto result2 = a < b;
    //LessThanComparable3 auto result3 = a < b;
    cout << result << endl;   

}