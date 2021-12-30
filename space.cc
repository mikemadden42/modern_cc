#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::space_info root = fs::space("/");

    std::cout << "Free space: " << root.free << '\n'
              << "Available space: " << root.available << '\n';
}
