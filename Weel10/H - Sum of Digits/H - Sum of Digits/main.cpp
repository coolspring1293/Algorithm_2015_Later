//
//  main.cpp
//  H - Sum of Digits
//
//  Created by Kieran Will on 12/1/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <cstring>

const int MAXN = 8101;
const int MAXD = 100;
const int MAXS = 901;
using namespace std;
int f[MAXS][MAXN], p[MAXS][MAXN], N, m, n;
bool CanUpdate(int a, int b) {
    if (b == -2 or b > MAXD - 1) return 0;
    if (a == -2) return 1;
    return (a > b + 1);
}

int getSol(int n, int m) {
    if (n > 9 * MAXD || m > 81 * MAXD\
        || n < 0 || m < 0 || n > m) {
        return -2;
    }
    if (f[n][m] != -1) {
        return f[n][m];
    }
    f[n][m] = -2;
    for (int i = 1; i < 10; ++ i) {
        int j = getSol(n - i, m - i*i);
        if (CanUpdate(f[n][m], j)) {
            f[n][m] = j + 1;
            p[n][m] = i;
        }
    }
    return f[n][m];
}

void printSOL(int ans, int n, int m) {
    if (-2 == ans) {
        cout << "No solution\n";
    }
    else {
        int tmp[9], i;
        memset(tmp, 0, sizeof(tmp));
        while (p[n][m]) {
            i = p[n][m];
            tmp[i - 1] ++;
            n -= i;
            m -= i * i;
        }
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < tmp[i]; ++ j) {
                cout << i + 1;
            }
        }
        cout << "\n";
    }
}


int main(int argc, const char * argv[]) {
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    while (cin >> N) {
        while (N --) {
            cin >> n >> m;
            printSOL(getSol(n, m), n, m);
        }
    }
    return 0;
}/*
  4
  9 81
  12 9
  6 10
  7 9
  
  */


