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


void Binarycout(int n) {
    for (int i = N - 1; i >= 0; -- i)
        cout << ((n >> i) & 1);
    cout << "\n";
}


int getState_Shift(int x) { return 1 << (x - 1); }
void getSol(int, int, int);
int main(int argc, const char * argv[]) {
    while (cin >> N) {
        for (int i = 1; i <= N; ++ i) cin >> a[i];
        memset(dp, INF, sizeof(dp));
        getSol(1, 0, 0);
        cout << dp[N][(1 << N) - 1] << "\n";
    }
    return 0;
}

/*

int _ = 0;
void getSol_2(int x, int s, int cur) {
    cout << "\n_____ = " << _++ << "\n";
    cout << "x=" << x << "\n";
    cout << "s=" << s << "\n";
    cout << "c=" << cur << "\n";
    if (cur >= dp[x-1][s]) {
        cout << "\n|||||||||\n"; return;
    
    }
    dp[x-1][s] = cur;
    if (x > N) return;
    cout << (s & getState_Shift(x) )<< "\n";
    if (s & getState_Shift(x)) {
        cout << "\n^^^^^^^\n";
        getSol(x+1, s, cur); return;
    }
    getSol(x+1, s|getState_Shift(x), cur+1);
    for (int i = x + 1; i <= N; ++ i)
        if((1 == abs(a[i]-a[x])) and !(s & getState_Shift(i))) {
            cout << "\n*************\n";
            getSol(x+1, s|getState_Shift(x)|getState_Shift(i), cur + 1); }
}
 
 */
/* Search, using recursion to achieve to find the shortest.
 * @x, the location of the cursor
 * @s, the currrent statement
 * @cur, the current shortest of the count of rows.
 */
void getSol(int x, int s, int cur) {
    /* No need to access the current statement. */
    if (cur >= dp[x-1][s]) return ;
    /* If the current diploma has been merged, put the cursor down.*/
    if (s & getState_Shift(x)) {
        getSol(x+1, s, cur); return;
    }
    
    dp[x-1][s] = cur;
    getSol(x+1, s|getState_Shift(x), cur+1);
    /* Judge the absolute value of the difference between the two numbers is 1.*/
    for (int i = x + 1; i <= N; ++ i) {
        if((1 == abs(a[i]-a[x])) and !(s & getState_Shift(i))) {
            getSol(x+1, s|getState_Shift(x)|getState_Shift(i), cur + 1);
        }
    }
}






/*
 6
 8 15 13 8 14 8
  */