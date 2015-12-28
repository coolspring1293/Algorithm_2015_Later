//
//  main.cpp
//  矩阵连乘
//
//  Created by Kieran Will on 12/25/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 102
#define INF 0x3f3f3f3f

using namespace std;

int N, x[MAXN], dp[MAXN][MAXN], t, m;

int main(int argc, const char * argv[]) {
    while (cin >> N) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; ++ i) {
            cin >> x[i];
        }
        for (int i = 2; i < N; ++ i) {
            for (int j = 2; j < N - i + 2; ++ j) {
                t = i + j - 1;
                dp[j][t] = INF;
                for (int k = j; k < t; ++ k) {
                    m = dp[j][k] + dp[k+1][t] + x[j-1] * x[k] * x[t];
                    dp[j][t] = min(dp[j][t], m);
                }
            }
        }
        cout << dp[2][N] << "\n";
    }
    return 0;
}
