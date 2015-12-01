//
//  main.cpp
//  D - Diplomas
//
//  Created by Kieran Will on 12/1/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 19; // max N = 18
const int INF  = 0x3f3f3f3f;
int N, a[MAXN], dp[MAXN][1 << MAXN];
//状态压缩 DP
int getState(int x) { return 1 << (x - 1); }

void getSol(int, int, int);

int main(int argc, const char * argv[]) {
    while (cin >> N) {
        for (int i = 1; i <= N; ++ i)
            cin >> a[i];
        memset(dp, INF, sizeof(dp));
        getSol(1, 0, 0);
        std::cout << dp[N][(1 << N) - 1] << "\n";
    }
    return 0;
}
void getSol(int x, int s, int cur) {
    if (cur >= dp[x-1][s]) return;
    dp[x-1][s] = cur;
    if (x > N) return;
    if (s & getState(x)) {
        getSol(x+1, s, cur); return;
    }
    getSol(x+1, s|getState(x), cur+1);
    for (int i = x + 1; i <= N; ++ i)
        if((1 == abs(a[i]-a[x])) and !(s & getState(i)))
            getSol(x+1, s|getState(x)|getState(i), cur + 1);
}
/*
  6
  8 15 13 8 14 8
  */