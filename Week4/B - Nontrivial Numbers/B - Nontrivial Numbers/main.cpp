//
//  main.cpp
//  B - Nontrivial Numbers
//
//  Created by Kieran Will on 10/21/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define MSIZE 100002
#include <cmath>
using namespace std;
int a, b;

int fun(int x) {
    int R = 1, k = sqrt(x);
    for (int i = 2; i <= k; ++ i) {
        if (x % i == 0) {
            if (i == k and pow(k, 2) == x) { R += i;         }
            else                           { R += i + x / i; }
        }
    }
    return R;
}

int main(int argc, const char * argv[]) {
    while (cin >> a >> b) {
        if (a == 1) { cout << "1\n"; continue; }
        double minx = MSIZE, p = 0; int ans = b;
        for (int i = b; i > a-1; -- i) {
            p = fun(i);
            if (p == 1.0) { ans = i; break; }
            if (minx > p/i) { minx = p/i; ans = i; }
        }
        cout << ans << "\n";
    }
    return 0;
}