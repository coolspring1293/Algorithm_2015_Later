//
//  main.cpp
//  A - Charm Bracelet
//
//  Created by Kieran Will on 11/12/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define MAX 35000
using namespace std;

int N, M, W[MAX], D[MAX], dp[MAX];
int main(int argc, const char * argv[]) {
    while (cin >> N >> M) {
        for (int i = 0; i < N; ++ i)
            cin >> W[i] >> D[i];
        for (int i = 0; i <= N; ++ i)
            for (int j = M; j >= W[i]; -- j)
                if (dp[j] < dp[j - W[i]] + D[i])
                    dp[j] = dp[j - W[i]] + D[i];
        cout << dp[M] << "\n";
    }
    return 0;
}
/*
 4 6
 1 4
 2 6
 3 12
 2 7
 
 */