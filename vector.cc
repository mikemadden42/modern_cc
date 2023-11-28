#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<std::pair<int, int>>> nestedVector;

    nestedVector.emplace_back();
    nestedVector[0].emplace_back(23, 42);

    for (auto & it : nestedVector) {
        for (auto & jit : it) {
            std::cout << jit.first << ", " << jit.second << std::endl;
        }
    }
}
