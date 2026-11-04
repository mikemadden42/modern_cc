#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> a{0};

void increment() { ++a; }

int main() {
    std::thread t1{increment};
    std::thread t2{increment};
    t1.join();
    t2.join();
    std::cout << a << std::endl;
    return 0;
}
