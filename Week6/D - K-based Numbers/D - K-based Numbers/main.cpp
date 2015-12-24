//
//  main.cpp
//  D - K-based Numbers
//
//  Created by Kieran Will on 11/7/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define M 20
using namespace std;

long long dp[M][2];
int N, K;

int main(int argc, const char * argv[]) {
    while (cin >> N >> K) {
        dp[1][0] = 0;
        dp[1][1] = K - 1;
        for (int i = 2; i <= N; ++ i) {
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) * (K - 1);
            dp[i][0] = dp[i-1][1];
        }
        cout << dp[N][1] + dp[N][0] << "\n";
    }
    return 0;
}
/*
 2  10
 */

