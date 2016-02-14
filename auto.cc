#include <iostream>

int main()
{
  auto maton = 112;   // maton is type int
  auto pt = &maton;   // pt is type int *
  
  std::cout << maton << std::endl;
  std::cout << *pt << std::endl;
  
  return 0;
}
