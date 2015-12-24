//
//  main.cpp
//  C - Idempotents
//
//  Created by Kieran Will on 10/21/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MSIZE 31643
using namespace std;

using std::cin;
using std::cout;


int m[MSIZE], _count = 0;
bool flg[MSIZE];


void gcd(int a,int b,int &x, int &y) {
    if(0 == b) { x = 1; y = 0; return; }
    gcd(b, a%b, x, y);
    int tmp = x; x = y; y = tmp - a/b*y;
}


int K, n, p, q, x, y, a1, a2;
int main(int argc, const char * argv[]) {
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) {
            for(int j = i * 2 ; j < MSIZE ; j += i) { flg[j] = 1; }
        }
    }
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) { m[++ _count] = i; }
    }
    while (cin >> K) {
        for (int ii = 0; ii < K; ++ ii) {
            cin >> n;
            for (int i = 1; i < _count; ++ i) {
                if (n % m[i] == 0) {
                    p = m[i]; q = (n/m[i]); break;
                }
            }
            gcd(p, q, x, y);
            a1 = p * x; if (a1 < 0) { a1 += n; }
            gcd(q, p, x, y);
            a2 = q * x; if (a2 < 0) { a2 += n; }
            if (a1 > a2) { swap(a1, a2); }
            cout << "0 1 " << a1 << " " << a2 << "\n";
        }
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}


/*
 3
 6
 15
 910186311
 
 *//*
    
    
    0 1 3 4
    0 1 6 10
    0 1 303395437 606790875
    
    
    
    */
