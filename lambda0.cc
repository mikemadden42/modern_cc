// lambda0.cc -- using lambda expressions

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }

bool f13(int x) { return x % 13 == 0; }

// using a functor
class f_mod {
   private:
    int dv;

   public:
    explicit f_mod(int d = 1) : dv(d) {}
    bool operator()(int x) const { return x % dv == 0; }
};

int main() {
    using std::cout;
    std::vector<int> numbers(Size1);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::generate(numbers.begin(), numbers.end(), generator);

    // using function pointers
    cout << "Sample size = " << Size1 << '\n';

    size_t count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    size_t count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers again
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';

    // using lambdas
    count3 = std::count_if(numbers.begin(), numbers.end(),
                           [](int x) { return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
                            [](int x) { return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

    return 0;
}
