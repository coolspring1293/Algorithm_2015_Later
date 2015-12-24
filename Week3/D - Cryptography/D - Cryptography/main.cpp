//
//  main.cpp
//  D - Cryptography
//
//  Created by Kieran Will on 10/14/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MSIZE = 15002;

bool isPrime(int  n) {
    for(int i = 2; i <= sqrt(n); ++ i) {
        if(n % i == 0)return false;
    }
    return true;
}

int N, tmp;
int main(int argc, const char * argv[]) {
    int _C = 4, bss = 7; vector<int> _V; _V.push_back(2); _V.push_back(3); _V.push_back(5);
    while (_C < MSIZE) {
        tmp = bss;
        if (isPrime(tmp)) {
            _V.push_back(bss); _C ++;
        }
        bss ++;
    }
    
    while (cin >> N) {
        for (int i = 0; i < N; ++ i) {
            cin >> tmp; cout << _V[tmp-1] << "\n";
        }
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 4
 3
 2
 5
 7
 */