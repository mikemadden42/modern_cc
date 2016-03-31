// https://rosettacode.org/wiki/Read_a_file_line_by_line

#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char **argv) {
  int linecount = 0;
  std::string line;
  std::ifstream infile(argv[1]);

  if (infile) {
    while (getline(infile, line)) {
      std::cout << linecount << ": " << line << std::endl;
      linecount++;
    }
  }

  infile.close();

  return 0;
}
