//
//  main.cpp
//  D - Anniversary Party
//
//  Created by Kieran Will on 11/30/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
/*
 背景
 有个公司要举行一场晚会。为了能玩得开心，公司领导决定：如果邀请了某个人，那么一定不会邀请他的上司（上司的上司，上司的上司的上司……都可以邀请）。
 每个参加晚会的人都能为晚会增添一些气氛，求一个邀请方案，使气氛值的和最大。
 输入格式
 第1行一个整数N（1<=N<=6000）表示公司的人数。
 接下来N行每行一个整数。第i行的数表示第i个人的气氛值x(-128<=x<=127)。
 接下来每行两个整数L，K。表示第K个人是第L个人的上司。
 输入以0 0结束。
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LP(i, s, e) for (int i = (s); i <= (e); ++ i)
#define MAXN 6010
#define INF  0x3f3f3f3f
//conviviality

int N, L, K, root, treeSp[MAXN], dp[MAXN][2], convi[MAXN];
std::vector<int> V[MAXN];

bool getSol(int r) {
    dp[r][1] = convi[r];
    //std::cout << " |root " << r << " size="<< V[r].size() << "\n";
    if(!V[r].empty()) {
        LP(i, 0, V[r].size()-1) getSol(V[r][i]);
        LP(i, 0, V[r].size()-1) {
            dp[r][0] += std::max(dp[V[r][i]][0],
                                 dp[V[r][i]][1]);
            dp[r][1] += dp[V[r][i]][0];
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    while (std::cin >> N) {
        LP(i, 1, N) {
            V[i].clear(); treeSp[i] = -1;
            dp[i][0] = dp[i][1] = 0;
            std::cin >> convi[i];
        }
        while (std::cin >> L >> K) {
            if (L == 0 and K == 0) { break; }
            V[K].push_back(L);
            treeSp[L] = K;
            //std::cout << "L = " << L << "   K = " << K << "\n";
        }
        //std::cout << "L = " << L << "   K = " << K << "\n";
        int root = 1;
        while (-1 != treeSp[root]) {
            root = treeSp[root];
        }
        getSol(root);
        std::cout << std::max(dp[root][1], dp[root][0]) << "\n";
    }
    return 0;
}



/*
 7
 1
 1
 1
 1
 1
 1
 1
 1 3
 2 3
 6 4
 7 4
 4 5
 3 5
 0 0
 */