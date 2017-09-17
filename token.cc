// https://rosettacode.org/wiki/Tokenize_a_string

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string s = "Hello,How,Are,You,Today";
    std::vector<std::string> v;
    std::istringstream buf(s);

    for (std::string token; getline(buf, token, ',');)
        v.push_back(token);

    copy(v.begin(), v.end(),
         std::ostream_iterator<std::string>(std::cout, "."));
    std::cout << std::endl;
}
