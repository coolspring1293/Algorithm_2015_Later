
#include <iostream>
#include <iomanip>

using namespace std;


bool isprime(long long n) {
    for (long long i = 2; i * i <= n; ++i) if (n % i == 0)
        return false;
    return true;
}

int main() {
    int k;
    std::cin >> k;
    long long num;
    std::cin >>  num;
    for (int i = 0; i < 12 - k; ++i)  { num *= 10; }
    if (num == 0)  { num = 1; }
    while (!isprime(num)) {
        num++;
    }
    std::cout << std::setw(12) << std::setfill('0') << num << "\n";
    //printf("%012lld\n", num);
    return 0;
}



