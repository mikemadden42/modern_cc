// http://en.wikipedia.org/wiki/C%2B%2B11
// http://en.wikipedia.org/wiki/Smart_pointer#C.2B.2B_Smart_Pointers

#include <memory>

int main()
{
  std::shared_ptr < int >p1( new int ( 5 ) );
  std::shared_ptr < int >p2 = p1; //Both now own the memory.
  
  p1.reset();     //Memory still exists, due to p2.
  p2.reset();     //Deletes the memory, since no one else owns the memory.
}
