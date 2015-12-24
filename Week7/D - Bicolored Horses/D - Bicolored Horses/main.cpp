//
//  main.cpp
//  D - Bicolored Horses
//
//  Created by Kieran Will on 11/11/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x7FFFFFF
#define M 502
using std::cin;
using std::cout;
int dp[M][M], a[M], N, K;
//2-dim packet problem
int main(int argc, const char * argv[]) {
    while (cin >> N >> K) {
        for (int i = 0; i < M; ++ i)
            for (int j = 0; j < M; ++ j)
                dp[i][j] = INF;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < N; ++ i) {
            cin >> a[i+1];
            a[i+1] += a[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= K; ++ i)
            for (int j = i; j <= N; ++ j)
                for (int k = i - 1; k < j; ++ k) {
                    int tmp = dp[i-1][k] + (a[j] - \
                        a[k]) * (j - k - a[j] + a[k]);
                    dp[i][j] = std::min(tmp, dp[i][j]);
                }
        cout << dp[K][N] << "\n";
    }
    return 0;
}
/*
 6 3
 1
 1
 0
 1
 0
 1
 */
