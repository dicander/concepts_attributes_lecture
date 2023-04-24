#include <iostream>
#include <vector>

[[nodiscard]] bool has_duplicates(const std::vector<int>& data) {
    std::unordered_set<int> seen;
    for (int x : data) {
        if (seen.count(x)) {
            return true;
        }
        seen.insert(x);
    }
    return false;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 3};

    if (has_duplicates(data)) { // The return value of has_duplicates() must be used due to the [[nodiscard]] attribute
        std::cout << "The vector has duplicates." << std::endl;
    } else {
        std::cout << "The vector has no duplicates." << std::endl;
    }

    return 0;
}
