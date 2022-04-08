#include <iostream>

int main() {
    auto count = 112;  // count is type int
    auto pt = &count;  // pt is type int *

    std::cout << count << std::endl;
    std::cout << *pt << std::endl;

    int v[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v) std::cout << x << std::endl;

    return 0;
}
