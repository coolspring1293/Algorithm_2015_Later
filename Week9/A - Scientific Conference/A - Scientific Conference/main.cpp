//
//  main.cpp
//  A - Scientific Conference
//
//  Created by Kieran Will on 11/28/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 100001

int N, s, e, sol = 0, dp[MAXN];
std::vector<std::pair<int, int>> V;
int main(int argc, const char * argv[]) {
    while (std::cin >> N) {
        V.clear(); memset(dp, 0, sizeof(dp)); sol = 0;
        for (int i = 0; i < N; ++ i) {
            std::cin >> s >> e;
            std::pair<int, int> tmp(s, e);
            V.push_back(tmp);
        }
        sort(V.begin(), V.end());
        int index = 0;
        for (int i = 1; i <= MAXN; ++ i) {
            sol = std::max(sol, dp[i-1]);
            if (N == index or i < V[index].first) { continue; }
            while (i == V[index].first) {
                dp[V[index].second] = std::max(dp[V[index].second], sol+1);
                ++ index;
            }
        }
        std::cout << sol << "\n";
    }
    return 0;
}