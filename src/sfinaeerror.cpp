#include <iostream>
#include <string>
#include <type_traits>

template <typename T,
          typename std::enable_if<std::is_same<T, std::string>::value>::type* = nullptr>
void print_if_string(const T& s) {
    std::cout << "The string is: " << s << std::endl;
}

int main() {
    std::string str = "Hello, world!";
    int num = 42;

    print_if_string(str); // OK, fungerar med std::string
    print_if_string(num); // Fel: kommer att generera ett kompileringsfel

    return 0;
}
