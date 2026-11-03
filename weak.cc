// http://en.wikipedia.org/wiki/C%2B%2B11
// http://en.wikipedia.org/wiki/Smart_pointer#C.2B.2B_Smart_Pointers

#include <memory>

int main() {
    auto p1 = std::make_shared<int>(5);
    std::weak_ptr<int> wp1 = p1;  // p1 owns the memory.

    {
        std::shared_ptr<int> p2 = wp1.lock();  // Now p1 and p2 own the memory.

        if (p2) {  // Always check to see if the memory still exists
                   // Do something with p2
        }
    }  // p2 is destroyed. Memory is owned by p1.

    // The int is destroyed. With make_shared the object and control block
    // share one allocation, which is freed once wp1 is gone too.
    p1.reset();

    std::shared_ptr<int> p3 =
        wp1.lock();  // Memory is gone, so we get an empty shared_ptr.

    if (p3) {
        // Will not execute this.
    }
}
