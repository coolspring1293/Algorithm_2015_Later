//
//  main.cpp
//  最长子字符串
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//


#include <iostream>
using namespace std;
const int M = 10005, F = 0x3f3f3f3f;
int N, a[M], x, m = 0;
int main(int agrc, const char * agev[]) {
    cin >> N;
    for (int i = 0; i < N; ++ i) {
        cin >> x;
        a[i] = F;
        int k = 0;
        while (a[k] < x) ++ k;
        a[k] = x;
        if (m < k + 1) m = ++ k;
    }
    cout << m << "\n";
    return 0;
}
/*
 7
 1 7 3 5 9 4 8
 
 */
