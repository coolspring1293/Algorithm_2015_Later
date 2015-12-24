//
//  main.cpp
//  二维背包
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100;
int c1[N]/*体积*/, c2[N]/*2*/, w[N]/*价值*/,f[N][N];

int CAP[] = { 2, 3, 1, 4, 6, 5};
int Value[]  = { 5, 6 ,5, 1,19, 7};
int CAP2[]  = { 3, 4 , 5, 3, 2, 6};
int nCapacity = 10;

int main(int argc, const char * argv[]) {
    int n;//size
    int m1, m2;//max size of the packet
    //cin >> n >> m;
    n = 6; m1 = 10; m2 = 12;
    for (int i = 0; i < n; ++ i) {
        //cin >> c[i] >> w[i];
        w[i+1] = Value[i];
        c2[i+1] =  CAP2[i];
        c1[i+1]  = CAP[i];
    }
    for (int i = 0; i <= m1; ++ i) {
        for (int j = 0; j <= m2; ++ j) {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int v = m1; v >= c1[i]; -- v) {
            for (int u = m2; u >= c2[i]; -- u) {
                f[v][u] = max(f[v][u], f[v-c1[v]][u-c2[u]] + w[i]);
            }
        }
    }
    
    cout << f[m1][m2] << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
