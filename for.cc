#include <iostream>

int main() {
  const int arr[] = { 0, 1, 2, 3 };

  for (auto i : arr) {
    std::cout << i << std::endl;
  }
}
