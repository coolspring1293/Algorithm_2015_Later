//
//  main.cpp
//  完全背包
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//


#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100;
int c[N]/*体积*/, w[N]/*价值*/, f[N];

int Weight[] = { 2, 3, 1, 4, 6, 5};
int Value[]  = { 5, 6 ,5, 1,19, 7};
int nCapacity = 10;

int main(int argc, const char * argv[]) {
    int n;//size
    int m;//max size of the packet
    //cin >> n >> m;
    n = 6; m = 10;
    for (int i = 0; i < n; ++ i) {
        //cin >> c[i] >> w[i];
        w[i+1] = Value[i];
        c[i+1] = Weight[i];
    }
    for (int i = 0; i <= m; ++ i) {
        cout << i << "\t";
        f[i] = 0;
    }
    cout << "\n";
    for (int i = 1; i <= n; ++ i) {
        for (int v = c[i]; v <= m; ++ v) {
            f[v] = max(f[v], f[v-c[i]] + w[i]);
        }
        /////////////////////
        cout << i << ":\t";
        for (int k = 1; k <= m; ++ k) {
            cout << f[k] << "\t";
        }
        cout << "\n";
        ///////////////////
    }
    cout << f[m] << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
