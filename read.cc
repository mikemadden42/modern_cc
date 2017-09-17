// https://rosettacode.org/wiki/Read_a_file_line_by_line

#include <fstream>
#include <iostream>
#include <string>

int main() {
    int linecount = 0;
    std::string line;
    std::ifstream infile("read.cc");

    if (infile) {
        while (getline(infile, line)) {
            std::cout << linecount << ": " << line << std::endl;
            linecount++;
        }
    }

    infile.close();

    return 0;
}
