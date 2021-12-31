#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::space_info root = fs::space("/");

    std::cout << "Free space: " << root.free << std::endl
              << "Available space: " << root.available << std::endl
              << "Total space: " << root.capacity << std::endl;
}
