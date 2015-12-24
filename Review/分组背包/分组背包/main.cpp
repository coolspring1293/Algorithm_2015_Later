//
//  main.cpp
//  分组背包
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 20;
int c[N][N]/*体积*/, w[N][N]/*价值*/, f[N];
//[GROUP][]
int Weight[4][6] = {
    { 2, 3, 1, 4, 6, 5},
    { 2,2,2,1,5,8 },
    { 3,4,6,2,1,6 },
    { 2,5,4,3,8,5 }
};
int Value[4][6]  = {
    { 5, 6 ,5, 1,19, 7},
    { 3,7,9,11,3,3},
    { 2,5,4,3,8,5 },
    { 3,2,6,13,4,1}};
int nCapacity = 13;

int main(int argc, const char * argv[]) {
    int n;//size
    int m;//max size of the packet
    int K;//size of Groups
    
    n = 6; m = 10; K = 4;
    for (int i = 0; i < K; ++ i) {
        for (int j = 0; j < n; ++ j) {
            w[i+1][j+1] = Value[i][j];
            c[i+1][j+1] = Weight[i][j];
        }
    }
    for (int i = 0; i <= m; ++ i) {
        f[i] = 0;
    }
    for (int k = 1; k <= K; ++ k) {
        for (int v = m; v >= 0; -- v) {
            for (int i = 1; i <= K; ++ i) {
                if (v <= c[k][i]) break;
                f[v] = max(f[v], f[v-c[k][i]] + w[k][i]);
            }
            
        }
    }
    
    cout << f[m] << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
