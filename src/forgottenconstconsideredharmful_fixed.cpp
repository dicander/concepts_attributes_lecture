#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    const std::vector<int> my_vector = {1, 2, 3, 4, 5};
    int target_value = 3;

    // Använd const_iterator för att lösa problemet
    std::vector<int>::const_iterator it = std::find(my_vector.begin(), my_vector.end(), target_value);

    if (it != my_vector.end()) {
        std::cout << "Found value: " << *it << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
