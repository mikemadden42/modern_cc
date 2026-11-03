// demo using three kinds of smart pointers
// requires support of C++14 make_unique

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Report {
   private:
    std::string str;

   public:
    explicit Report(std::string s) : str(std::move(s)) {
        std::cout << "Object created!\n";
    }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main() {
    {
        auto ps = std::make_shared<Report>("using shared_ptr");
        ps->comment();
    }
    {
        auto ps = std::make_unique<Report>("using unique_ptr");
        ps->comment();
    }
    {
        std::weak_ptr<Report> wp;
        {
            auto ps = std::make_shared<Report>("using weak_ptr");
            wp = ps;
            if (auto locked = wp.lock()) locked->comment();
        }
        std::cout << "weak_ptr expired: " << std::boolalpha << wp.expired()
                  << "\n";
    }
    return 0;
}
