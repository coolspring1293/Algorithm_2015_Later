//
//  main.cpp
//  B - Longest Ordered Subsequence
//
//  Created by Kieran Will on 11/6/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
using namespace std;

const int M = 10005, F = 0x7FFFFFF;
int N, a[M], x, m = 0;
// AlgoCom = O(n^2) how to make it by a O(nlogn) Method?
int main(int argc, const char * argv[]) {
    cin >> N;
    for (int k = 0; k < N; ++ k) {
        a[k] = F;
        cin >> x;
        int i = 0;
        while (a[i] < x) ++ i;
        a[i] = x;
        if (m < i + 1) m = ++ i;
    }
    cout << m << "\n";
    return 0;
}
/*
 7
 1 7 3 5 9 4 8
 */