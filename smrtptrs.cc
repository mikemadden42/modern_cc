// smrtptrs.cc -- using three kinds of smart pointers
// requires support of C++11 shared_ptr and unique_ptr

#include <iostream>
#include <memory>
#include <utility>

class Report {
   private:
    std::string str;

   public:
    explicit Report(std::string  s) : str(std::move(s)) { std::cout << "Object created!\n"; }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main() {
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    return 0;
}
