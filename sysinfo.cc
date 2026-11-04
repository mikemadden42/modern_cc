#include <iostream>
#include <thread>

int main() {
    // hardware_concurrency() returns 0 when the value can't be determined.
    unsigned int cores = std::thread::hardware_concurrency();
    if (cores == 0) {
        std::cout << "Total cores: unknown" << std::endl;
    } else {
        std::cout << "Total cores: " << cores << std::endl;
    }

    return 0;
}
