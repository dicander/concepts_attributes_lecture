#include <iostream>

void process_data(int data) {
    if (data > 0) [[likely]] {
        std::cout << "Processing positive data: " << data << std::endl;
    } else [[unlikely]] {
        std::cout << "Processing non-positive data: " << data << std::endl;
    }
}

int main() {
    process_data(5);
    process_data(-3);
    return 0;
}
