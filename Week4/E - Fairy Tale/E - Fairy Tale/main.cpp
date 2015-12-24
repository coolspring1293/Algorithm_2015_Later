//
//  main.cpp
//  E - Fairy Tale
//
//  Created by Kieran Will on 10/21/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
/*
#include <iostream>
#include <iomanip>
using namespace std;

bool isP(long long x) {
    for(long long i = 2; i * i <= x; ++ i) { if (0 == x % i) { return false; } }
    return true;
}
int size_throne;
long long  throne;
int main(int argc, const char * argv[]) {
    while (scanf("%d", &size_throne) != EOF) {
        cin >> throne;
        for (int i = 0; i < 12 - size_throne; ++ i) { throne *= 10; }
        if (0 == throne) { throne = 1; }
        while (!isP(throne)) { ++ throne; }
        cout << setw(12) << setfill('0') << throne << "\n";
    }
    return 0;
}
/*
5
64631
646310554187
 */


#include <iostream>
#include <iomanip>

using namespace std;


bool isP(long long n) {
    for (long long i = 2; i * i <= n; ++i) if (0 == n % i) { return false; }
    return true;
}

int main() {
    int k;
    std::cin >> k;
    long long num;
    std::cin >>  num;
    for (int i = 0; i < 12 - k; ++i)  { num *= 10; }
    if (num == 0)  { num = 1; }
    while (!isP(num)) {
        num++;
    }
    std::cout << std::setw(12) << std::setfill('0') << num << "\n";
    //printf("%012lld\n", num);
    return 0;
}



