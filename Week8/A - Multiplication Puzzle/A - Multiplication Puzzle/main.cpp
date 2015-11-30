//
//  main.cpp
//  A - Multiplication Puzzle
//
//  Created by Kieran Will on 11/17/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 102
#define INF 0x3f3f3f3f
#define LP(i, s, e) for (int i = (s); i < (e); ++ i)
using namespace std;

int N, x[MAXN], dp[MAXN][MAXN], t, m;
int main(int argc, const char * argv[]) {
    while (cin >> N) {
        memset(dp, 0, sizeof(dp));
        LP(i, 1, N+1) cin >> x[i];
        LP(i, 2, N)
            LP(j, 2, N-i+2) {
                t = i + j - 1;
                dp[j][t] = INF;
                LP(k, j, t)
                    LP(k, j, t) {
                    m = dp[j][k] + dp[k+1][t] + \
                    x[j-1] * x[k] * x[t];
                    dp[j][t] = min(dp[j][t], m);
                }
            }
        
        cout << dp[2][N] << "\n";
    }
    return 0;
}
/*
 6
 10 1 50 50 20 5
 
*/