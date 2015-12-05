//
//  main.cpp
//  C - Cards
//
//  Created by Kieran Will on 12/3/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1100;
int m, n, c;
int card[MAXN];
bool f[MAXN][MAXN];
//vector<int> card;
int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        for (int i = 0; i < m; ++ i) {
            cin >> c; card[c] ++;
        }
        if (1 == card[0]) f[0][1] = true;
        if (0 == card[0]) f[0][0] = true;
        for (int i = 1; i <= n; ++ i) {
            if (2 == card[i]) {
                f[i][0] = false;
                f[i][1] = f[i-1][0];
            }
            if (1 == card[i]) {
                f[i][0] =  f[i-1][0];
                f[i][1] = (f[i-1][1] or f[i-1][0]);
            }
            if (0 == card[i]) {
                f[i][0] = (f[i-1][1] or f[i-1][0]);
                f[i][1] = (f[i-1][1] or f[i-1][0]);
            }
        }
        if (f[n][0] == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
    return 0;
}
/*
 
 5 4
 2 0 1 2
 
 */