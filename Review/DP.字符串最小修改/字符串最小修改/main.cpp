//
//  main.cpp
//  字符串最小修改
//
//  Created by Kieran Will on 12/25/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
//
//  main.cpp
//  C - AGTC
//
//  Created by Kieran Will on 11/12/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int M = 1005;
int dp[M][M];
string s1, s2;
int    l1, l2;
int min_3(int a, int b, int c) {
    return min(min(a, b), c);
}

int main(int argc, const char * argv[]) {
    while (cin >> l1 >> s1 >> l2 >> s2) {
        for (int i = 1; i <= l1; ++ i) dp[i][0] = i;
        for (int i = 1; i <= l2; ++ i) dp[0][i] = i;
        for (int i = 1; i <= l1; ++ i)
            for (int j = 1; j <= l2; ++ j)
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min_3(dp[i-1][j]   + 1,\
                                     dp[i][j-1]   + 1,\
                                     dp[i-1][j-1] + 1 );
        cout << dp[l1][l2] << "\n";
    }
    return 0;
}

/*
 10 AGTCTGACGC
 11 AGTAAGTAGGC
 */
