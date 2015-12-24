//
//  main.cpp
//  C - Way to the University
//
//  Created by Kieran Will on 9/30/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define MSIZE 10002
//
bool _stop[MSIZE], _flg;
int N, M, tmp;
int main(int argc, const char * argv[]) {
    while (cin >> N) {
        memset(_stop, false, sizeof(_stop)); _flg = false;
        for (int i = 0; i < N; ++ i) {
            cin >> tmp;
            for (int j = tmp < 8 ? 0 : tmp - 7; j < tmp + 5; ++ j) {
                _stop[j] = true;
            }
        }
        cin >> M;
        for (int i = 0; i < M; ++ i) {
            cin >> tmp;
            for (int j = tmp < 16 ? 0 : tmp - 15; j < tmp - 3; ++ j) {
                _stop[j] = true;
            }
        }
        for (int i = 0; i < MSIZE; ++ i) {
            if (!_stop[i]) { cout << fixed << setprecision(6) << i * 3.6 / 20 << "\n"; _flg = true; break; }
        }
        if (!_flg) {
            cout << fixed << setprecision(6) << 100005 * 3.6 / 20 << "\n";
        }
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 1
 1
 1
 100
 
 
 */