//
//  main.cpp
//  B - False Mirrors
//
//  Created by Kieran Will on 11/28/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define INF 0x3f3f3f3f
int n, a[20], m[20];

int shoot(int, int, int, int);
int getSol(int&, int&, int);
int main(int argc, const char * argv[]) {
    std::cin >> n;
    int sum = 0, damage = 0, min = INF;
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::cout << getSol(sum, damage, min) << "\n";
}

int shoot(int x, int y, int sign, int tmp) {
    for (int i = y; i <= y + 2; ++ i) {
        if (tmp == (m[i % n] += sign)) {
            x -= sign * a[i % n];
        }
    }
    return x;
}

int getSol(int& x, int& y, int md) {
    if (0 == x) return (md < y) ? md : y;
    for (int i = 0; i < n; ++ i) {
        if (m[i] != 0) continue;
        x = shoot(x, i, 1, 1);
        y += x;
        if (md > y) {
            md = getSol(x, y, md);
        }
        y -= x;
        x = shoot(x, i, -1, 0);
    }
    return md;
}
/*
  7
  3 4 2 2 1 4 1
  */