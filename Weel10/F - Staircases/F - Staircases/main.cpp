//
//  main.cpp
//  F - Staircases
//
//  Created by Kieran Will on 12/3/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 505;
int N;
long long a[MAXN]; long long old =  0;
int main(int argc, const char * argv[]) {
    //while (cin >> N)
    for (N = 1; N < 100; ++ N)
    {   cout << "_____________________________\n";
        memset(a, 0LL, sizeof(a));
        a[0] = 1LL;
        for(int i = 1; i < N; ++ i) {
            for (int j = N - 1; j >= 0; -- j) {
                if (N >= i + j) {
                    a[i+j] += a[j]; //cout << " | T=" << i+j << "\t J=" << j << "\t";
                    for (int l = 0; l <= N; ++ l) {
                        //cout << a[l] << "\t";
                    }
                    //cout << "\n";
                }
                //cout << "\n";
            }
        }
        
        cout << "\n" << N << "\t" << a[N]-old << "\n";
        old = a[N];
    }
    return 0;
}
/*
212
 */