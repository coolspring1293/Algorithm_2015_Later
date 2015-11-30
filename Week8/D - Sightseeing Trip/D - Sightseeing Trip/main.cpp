//
//  main.cpp
//  D - Sightseeing Trip
//
//  Created by Kieran Will on 11/19/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF  0x3f3f3f3f
#define LP(i, e) for (int i = 1; i <= (e); ++ i)
using namespace std;
int N, M, u, v, d, _m[MAXN][MAXN], _p[MAXN][MAXN], dp[MAXN][MAXN], st[MAXN], mC, x, y;
void getSol(int);
int main(int argc, const char * argv[]) {
    // insert code here...
    while (cin >> N >> M) {
        memset(_m, INF, sizeof(_m));
        LP(i, M) {
            //cin >> u >> v >> d;
            scanf("%d%d%d", &u, &v, &d);
            if (_m[u][v] > d) _m[u][v] = _m[v][u] = d;
        }
        memcpy(dp, _m, sizeof(_m));
        mC = INF; x = y = 0;
        getSol(N); cout << "\n";
    }
    return 0;
}
void getSol(int n) {
    LP(i, n) LP(j, n) _p[i][j] = j;
    LP(k, n) {
        LP(i, n) LP(j, n)
                if (i != j and dp[i][j] != INF and \
                    _m[i][k] != INF and _m[k][j] != INF \
                    and dp[i][j] + _m[i][k] + _m[k][j] < mC) { // find the ring with the shortest length
                    mC = dp[i][j] + _m[i][k] + _m[k][j];
                    y = i; x = 0;
                    while (y != j) {// stone the patn record
                        st[x ++] = y;
                        y = _p[y][j];
                    }
                    st[x ++] = j;
                    st[x ++] = k;
                }
        LP(i, n) LP(j, n)
                if(dp[i][k] != INF and dp[k][j] != INF\
                   and dp[i][k] + dp[k][j] < dp[i][j]) { // floyd algo.  dp = distance
                    dp[i][j] = dp[i][k] + dp[k][j];
                    _p[i][j] = _p[i][k];
                }
    }
    if (INF == mC) printf("No solution.");//cout << "No solution.";
    else LP(i, x)  printf("%d ", st[i-1]);//cout << st[i-1] << " ";
}
/*
  5 7
  1 4 1
  1 3 300
  3 1 10
  1 2 16
  2 3 100
  2 5 15
  5 3 20
  4 3
  1 2 10
  1 3 20
  1 4 30
  -1
  
 
 */