//
//  main.cpp
//  B - An antiarithmetic permutation
//
//  Created by Kieran Will on 10/27/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define M 100005
using namespace std;
int s[M], a[M], n;
void fun(int l, int h) {
    int c = l;
    if (l == h) { return; }
    for (int i = l; i <= h; i += 2) {
        a[c ++] = s[i];
    }
    for (int i = l + 1; i <= h; i += 2) {
        a[c ++] = s[i];
    }
    for (int i = l; i <= h; ++ i) {
        s[i] = a[i];
    }
    int m = (l + h) / 2;
    fun(l, m); fun(m + 1, h);
}
int main(int argc, const char * argv[]) {
    while (cin >> n and n != 0) {
        for (int i = 0; i < n; ++ i) { s[i] = i; }
        fun(0, n-1);
        cout << n << ":";
        for (int i = 0; i < n; ++ i) {
            cout << " " << a[i];
        }
        cout << "\n";
    }
    return 0;
}

/*
 3
 5
 6
 0
 */

