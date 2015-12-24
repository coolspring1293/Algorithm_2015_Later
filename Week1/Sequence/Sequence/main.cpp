//
//  main.cpp
//  Sequence II
//
//  Created by Kieran Will on 9/22/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int n, p;
int main(int argc, const char * argv[]) {
    while (cin >> n >> p and n and p) {
        long long tmp = 1;
        for (int i = 1; i <= n; ++ i) {
            tmp = tmp * i % p;
        }
        cout << tmp << "\n";
    }
    return 0;
}

/*
 1 2 2 11 0 0
 */