//
//  main.cpp
//  B - Piggy-Bank
//
//  Created by Kieran Will on 11/12/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 550
#define INF 0x3f3f3f3f
using namespace std;

int T, E, F, N, W[MAX], P[MAX], dp[MAX*20];
int main(int argc, const char * argv[]) {
    cin >> T;
    while (T --) {
        cin >> E >> F >> N;
        memset(W, 0, sizeof(W));
        memset(P, 0, sizeof(P));
        memset(dp, INF, sizeof(dp)); dp[0] = 0;
        for (int i = 0; i < N; ++ i) cin >> P[i] >> W[i];
        for (int i = 0; i < N; ++ i)
            for (int j = W[i]; j <= F - E; ++ j)
                //if (dp[j-W[i]] < INF)
                    dp[j] = min(dp[j], dp[j-W[i]] + P[i]);
        
        if (dp[F-E] >= INF) cout << "This is impossible.\n";
        else cout << "The minimum amount of money in the piggy-bank is " << dp[F-E] << ".\n";
    }
    return 0;
}
/*
 3
 10 110
 2
 1 1
 30 50
 10 110
 2
 1 1
 50 30
 1 6
 2
 10 3
 20 4
 */