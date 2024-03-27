#include <iostream>
#include <vector>

template <typename T>
void print_values(T begin, T end) {
    for (; begin != end; ++begin) {
        std::cout << *begin << " ";
    }
    std::cout << std::endl;
}

// Let's test this with arrays and vectors
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    print_values(std::begin(arr), std::end(arr));

    std::vector<int> vec = {1, 2, 3, 4, 5};
    print_values(std::begin(vec), std::end(vec));

    // Old style calls without using std::begin and std::end
    print_values(arr, arr + 5);
    print_values(&vec[0], &vec[0] + vec.size());
    print_values(vec.begin(), vec.end());

}