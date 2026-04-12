#include <iostream>
#include <concepts>

//using namespace std;

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
    // Only works if lt is defined (1) as a free function or
    // (2) is a friend...
    // And we do not have primitive types such as int or float that use assembly instructions instead of
    // methods.
    // In short, don't do this.
};


// Now we try to use both and see what happens.

template <typename T>
concept LessThanComparable3 = requires (T a, T b) {
    { a < b } -> std::same_as<bool>;
    { operator<(a,b) } -> std::same_as<bool>;
};
// Don't do this either. Even if the first one succeeds, for many types the second one won't.


// Write a main function that uses all three concepts, once for each.
int main() {
    std::string a = "Hello";
    std::string b = "World";
    //int result = 1;
    LessThanComparable auto result = a < b;
    //LessThanComparable2 auto result2 = a < b;
/*     dicander@Whirlwind:~/Documents/cprog/concepts_attributes_lecture/src/lessthan$ g++ -std=c++20 lessthan.cpp -fconcepts-diagnostics-depth=3 && ./a.out
lessthan.cpp: In function ‘int main()’:
lessthan.cpp:38:42: error: deduced initializer does not satisfy placeholder constraints
   38 |     LessThanComparable2 auto result2 = a < b;
      |                                        ~~^~~
lessthan.cpp:38:42: note: constraints not satisfied
lessthan.cpp:17:9:   required for the satisfaction of ‘LessThanComparable2<auto [requires ::LessThanComparable2<<placeholder>, >]>’ [with auto [requires ::LessThanComparable2<<placeholder>, >] = bool]
lessthan.cpp:17:31:   in requirements with ‘T a’, ‘T b’ [with T = bool]
lessthan.cpp:18:16: note: the required expression ‘operator<(a, b)’ is invalid, because
   18 |     { operator<(a,b) } -> std::same_as<bool>; // This does not express the same thing as the previous one
      |       ~~~~~~~~~^~~~~
lessthan.cpp:18:16: error: ‘operator<’ not defined */
    
//    LessThanComparable3 auto result3 = a < b;
/*     dicander@Whirlwind:~/Documents/cprog/concepts_attributes_lecture/src/lessthan$ g++ -std=c++20 lessthan.cpp -fconcepts-diagnostics-depth=3 && ./a.out
lessthan.cpp: In function ‘int main()’:
lessthan.cpp:38:42: error: deduced initializer does not satisfy placeholder constraints
   38 |     LessThanComparable2 auto result2 = a < b;
      |                                        ~~^~~
lessthan.cpp:38:42: note: constraints not satisfied
lessthan.cpp:17:9:   required for the satisfaction of ‘LessThanComparable2<auto [requires ::LessThanComparable2<<placeholder>, >]>’ [with auto [requires ::LessThanComparable2<<placeholder>, >] = bool]
lessthan.cpp:17:31:   in requirements with ‘T a’, ‘T b’ [with T = bool]
lessthan.cpp:18:16: note: the required expression ‘operator<(a, b)’ is invalid, because
   18 |     { operator<(a,b) } -> std::same_as<bool>; // This does not express the same thing as the previous one
      |       ~~~~~~~~~^~~~~
lessthan.cpp:18:16: error: ‘operator<’ not defined
dicander@Whirlwind:~/Documents/cprog/concepts_attributes_lecture/src/lessthan$ g++ -std=c++20 lessthan.cpp -fconcepts-diagnostics-depth=3 && ./a.out
lessthan.cpp: In function ‘int main()’:
lessthan.cpp:52:42: error: deduced initializer does not satisfy placeholder constraints
   52 |     LessThanComparable3 auto result3 = a < b;
      |                                        ~~^~~
lessthan.cpp:52:42: note: constraints not satisfied
lessthan.cpp:27:9:   required for the satisfaction of ‘LessThanComparable3<auto [requires ::LessThanComparable3<<placeholder>, >]>’ [with auto [requires ::LessThanComparable3<<placeholder>, >] = bool]
lessthan.cpp:27:31:   in requirements with ‘T a’, ‘T b’ [with T = bool]
lessthan.cpp:29:16: note: the required expression ‘operator<(a, b)’ is invalid, because
   29 |     { operator<(a,b) } -> std::same_as<bool>;
      |       ~~~~~~~~~^~~~~
lessthan.cpp:29:16: error: ‘operator<’ not defined
dicander@Whirlwind:~/Documents/cprog/concepts_attributes_lecture/src/lessthan$ */
    std::cout << result << std::endl;   

}