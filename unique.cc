// http://en.wikipedia.org/wiki/C%2B%2B11
// http://en.wikipedia.org/wiki/Smart_pointer#C.2B.2B_Smart_Pointers

#include <memory>

int main() {
    std::unique_ptr<int> p1(new int(5));
    std::unique_ptr<int> p3 = std::move(p1);  // Transfers ownership. p3 now
                                              // owns the memory and p1 is
                                              // rendered invalid.

    p3.reset();  // Deletes the memory.
    p1.reset();  // Does nothing.
}
