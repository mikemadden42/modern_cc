#include <iostream>

int main() {
    std::cout << "using nullptr" << std::endl;

    int *i = nullptr;
    // https://stackoverflow.com/questions/62338661/printing-nullptr-with-stdcout-and-printf
    std::cout << static_cast<const void *>(i) << std::endl;

    return 0;
}
