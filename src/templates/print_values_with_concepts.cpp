#include <iostream>
#include <vector>
#include <concepts>


template<typename Container>
concept Range = requires(Container c) {
  c.begin(); // Check if Container has a begin() function
  c.end();   // Check if Container has an end() function
};

template<Range container>
void print_range(const container& v) {
  for (auto element : v) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4};
    print_range(numbers); // Works because vector has begin() and end()

  // This wouldn't compile because int doesn't have begin() and end()
  // print_range(42);

  // Does this work with arrays?
    int array[] = {1, 2, 3, 4};
    //print_range(array); // Does not work because arrays don't have begin() and end()
}
