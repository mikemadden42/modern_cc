// https://rosettacode.org/wiki/Read_a_file_line_by_line

#include <fstream>
#include <iostream>
#include <string>

int main() {
    int line_count = 0;
    std::string line;
    std::ifstream infile("read.cc");

    if (infile) {
        while (getline(infile, line)) {
            std::cout << line_count << ": " << line << std::endl;
            line_count++;
        }
    }

    infile.close();

    return 0;
}
