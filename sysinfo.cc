#include <iostream>
#include <limits.h>
#include <thread>
#include <unistd.h>

int main() {
  char name[_POSIX_HOST_NAME_MAX + 1];
  gethostname(name, sizeof(name));
  std::cout << "Host name: " << name << std::endl;

  unsigned int cores = std::thread::hardware_concurrency();
  std::cout << "Total cores: " << cores << std::endl;

  return 0;
}
