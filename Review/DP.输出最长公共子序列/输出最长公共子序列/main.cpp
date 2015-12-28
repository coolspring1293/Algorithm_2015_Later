//
//  main.cpp
//  输出最长公共子序列
//
//  Created by Kieran Will on 12/25/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int M = 1005;
int dp[M][M];
string s1, s2;
unsigned long l1, l2;

int main(int argc, const char * argv[]) {
    while (cin >> s1  >> s2) {
        string sol;
        l1 = s1.size(); l2 = s2.size();
        for (int i = 1; i <= l1; ++ i) dp[i][0] = 0;
        for (int i = 1; i <= l2; ++ i) dp[0][i] = 0;
        for (int i = 1; i <= l1; ++ i) {
            for (int j = 1; j <= l2; ++ j) {
                if (s1[i-1] == s2[j-1]) {
                    
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        for (int i = 1; i <= l1; ++ i) {
            for (int j = 1; j <= l2; ++ j) {
                cout << dp[i][j] << "\t";
            }
            cout << "\n";
        }
        size_t x = l1, y = l2;
        while (x >= 1 and y >= 1) {
            if (s1[x-1] == s2[y-1]) {
                sol += s1[x-1]; x --; y --;
            }
            else {
                if (dp[x-1][y] < dp[x][y-1]) y --;
                else x --;
            }
        }
        reverse(sol.begin(), sol.end());
        cout <<  sol << "\t" << dp[l1][l2] << "\n";
    }
    return 0;
}

/*
 ABCBDAB BACBBD
 ABCBDAB BDCABA
 */