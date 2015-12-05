//
//  main.cpp
//  G - Mnemonics and Palindromes
//
//  Created by Kieran Will on 12/4/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
///////
/*
 给出一个字符串，要求将这个字符串划分成尽量少的串，
 使得每个串都为回文串。
 读入一行，一个字符串s，长度不超过4000。
 输出第一行包含一个正整数，
 表示最少划分成的串的数量。
 第二行输出你的划分方案，每个回文串间以空格隔开。
 若有多组答案，输出任意一组即可。
 */


#include <iostream>

#include <cstring>

#define NOANS       -2
#define UNKNOWN     -1
#define MaxSum     901
#define MaxSquare 8101
#define MaxDigits  100

using namespace std;
int f[MaxSum][MaxSquare], p[MaxSum][MaxSquare], N, m, n;
bool CanUpdate(int a, int b) {
    if (b == -2 or b > MaxDigits - 1) return 0;
    if (a == -2) return 1;
    return (a > b + 1);
}

int getSol(int n, int m) {
    int j;
    if (n > 9 * MaxDigits || m > 81 * MaxDigits\
        || n < 0 || m < 0 || n > m)
        return -2;
    if (f[n][m] != -1) return f[n][m];
    f[n][m] = -2;
    for (int i = 1; i < 10; ++ i) {
        j = getSol(n-i,m-i*i);
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
        int a[9], i;
        memset(a, 0, sizeof(a));
        while (p[n][m]) {
            i = p[n][m];
            a[i-1] ++;
            n -= i;
            m -= i*i;
        }
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < a[i]; ++ j) {
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
}
