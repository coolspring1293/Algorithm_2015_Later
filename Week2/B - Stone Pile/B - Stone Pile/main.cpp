//
//  main.cpp
//  B - Stone Pile
//
//  Created by Kieran Will on 9/29/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//


//use DP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MSIZE 5000002
using namespace std;
int N, W, tmp[MSIZE], sum, solution;//solution = minimal possible weight difference between stone piles

int main(int argc, const char * argv[]) {
    while (cin >> N) {
        vector<int> _stone; sum = 0; solution = MSIZE;
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < N; i ++) { cin >> W; _stone.push_back(W); sum += W; }
        for (int i = 0; i < N; i ++) {
            for (int j = sum; j >= _stone[i]; j --) {
                tmp[j] = max(tmp[j], tmp[j-_stone[i]] + _stone[i]);
            }
        }
        for (int i = 0; i <= sum; i ++) {
            if (tmp[i] and abs(sum - tmp[i] * 2) < solution) {
                solution = abs(sum - tmp[i] * 2);
            }
        }
        cout << abs(solution) << "\n";
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 5
 5 8 13 27 14

 */