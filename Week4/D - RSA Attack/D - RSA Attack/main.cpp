//
//  main.cpp
//  D - RSA Attack
//
//  Created by Kieran Will on 10/20/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#define MSIZE 32015
using namespace std;
int m[MSIZE], _count = 0;
bool flg[MSIZE];
int K, e, n, c;
int p, q, x, y;

void gcd(int, int, int&, int&);

long long sol(int, int, int);//mod

int main(int argc, const char * argv[]) {
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) {
            for(int j = i * 2 ; j < MSIZE ; j += i) { flg[j] = 1; }
        }
    }
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) { m[++ _count] = i; }
    }
    //筛法打表
    while (cin >> K) {
        for (int ii = 0; ii < K; ++ ii) {
            cin >> e >> n >> c;
            for (int i = 1; i < _count; ++ i) {
                if (n % m[i] == 0) {
                    p = m[i]; q = (n/m[i]); break;
                }
            }
            int tmp = (p-1) * (q-1);
            gcd(e, tmp, x, y);
            if (x < 0) { x += e * tmp;}
            cout << sol(c, x, n) << "\n";
        }
    }
    return 0;
}

/*
 3
 9 187 129
 11 221 56
 7 391 204
 
 */


void gcd(int a,int b,int &x, int &y) {
    if(!b) { x = 1; y = 0; return; }
    gcd(b, a%b, x, y);
    int tmp = x; x = y; y = tmp - a/b*y;
}

long long sol(int a, int b, int mod) {
    long long tmp;
    if (b == 0) { return 1 % mod; }
    if (b == 1) { return a % mod; }
    tmp = sol(a, b/2, mod);
    tmp = tmp*tmp % mod;
    if(b & 1) { tmp = tmp * a % mod; }
    return tmp;
}