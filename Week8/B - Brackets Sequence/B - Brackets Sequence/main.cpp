//
//  main.cpp
//  B - Brackets Sequence
//
//  Created by Kieran Will on 11/19/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAXN 101
#define INF  0x3f3f3f3f
using namespace std;


int dp[MAXN][MAXN][2], _max_dis = INF;;
unsigned long _len = 0;
string _s;

bool matched(int i, int j) {
    return (_s[i] == '[' and _s[j] == ']') or (_s[i] == '(' and _s[j] == ')');
}

void init() {
    _len = _s.length();
    _max_dis = static_cast<int>(_len + 1);
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < _len; ++ i) {
        dp[i][i][0]   = 1;
        dp[i+1][i][0] = 0;
    }
}

void showBrackets(int i, int j) {
    //cout << _count << ": " <<  i << " " <<  j << "\n"; _count ++ ;
    //cout << "   " << dp[i][j][1] << "\n";
    if      (i  > j) return;
    else if (i == j)
        if (_s[i] == '[' or _s[i] == ']') cout << "[]";
        else                              cout << "()";
    else
        if (dp[i][j][1] == INF) {
            cout << _s[i];
            showBrackets(i+1, j-1);
            cout << _s[j];
        }
        else {
            showBrackets(i            , dp[i][j][1]);
            showBrackets(dp[i][j][1]+1,           j);
        }
}

int main(int argc, const char * argv[]) {
    while (cin >> _s) {
        init();
        for (int i = static_cast<int>(_len - 2); i >= 0; -- i) {
            for (int j = i + 1; j < _len; ++ j) {
                dp[i][j][0] = _max_dis;
                if (matched(i, j))
                    dp[i][j][0] = min(dp[i][j][0], dp[i+1][j-1][0]);
                // shortest_index = si
                for (int si = i; si <= j; ++ si)
                    if (dp[i][j][0] > dp[i][si][0] + dp[si+1][j][0]) {
                        dp[i][j][0] = dp[i][si][0] + dp[si+1][j][0];
                        dp[i][j][1] = si;
                    }
            }
        }
       // cout << dp[0][_len-1][0] << "\n";
        showBrackets(0, static_cast<int>(_len-1));
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 ([(]
 ([)]
 */