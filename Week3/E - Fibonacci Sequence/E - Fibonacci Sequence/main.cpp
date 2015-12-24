//
//  main.cpp
//  E - Fibonacci Sequence
//
//  Created by Kieran Will on 10/19/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define M_SIZE 2000000002
#define S_TRI 3

using namespace std;




long long cur, x_i, y_i, x_j, y_j, test, _l = - M_SIZE, _r = M_SIZE, _m = 0, _s[S_TRI];
int main(int argc, const char * argv[]) {
    while (scanf("%lld", &x_i) != EOF) {
        cin >> y_i >> x_j >> y_j >> test;
        if (x_i > x_j) { swap(x_i, x_j); swap(y_i, y_j); }
        while (_l <= _r) {
            _m = (_l + _r) >> 1;
            _s[0] = y_i;
            _s[cur = 1] = _m;
            long long tmp = x_i + 2; int flg_count = -2;
            while (tmp <=  x_j) {
                cur = (cur + 1) % 3; ++ tmp;
                _s[cur] = _s[(cur + 2) % 3] + _s[( cur + 1) % 3];
                if (_s[cur] > M_SIZE)         { flg_count =  1; } //right
                else if (_s[cur] < (-M_SIZE)) { flg_count = -1; } //left
                if (flg_count != -2)               { break;     } //not found
            }
            if (flg_count == -2) {
                if      (_s[cur] > y_j) { flg_count =  1; }
                else if (_s[cur] < y_j) { flg_count = -1; }
                else                    { flg_count =  0; }
            }
            if      (flg_count ==  1) { _r = _m - 1; }
            else if (flg_count == -1) { _l = _m + 1; }
            else if (flg_count ==  0) { break;       }
        }
        _s[0] = y_i; _s[cur = 1] = _m;
        if (x_i < test) {
            long long tmp = x_i + 2;
            while (tmp <=  test) {
                cur = (cur + 1) % 3; ++ tmp;
                _s[cur] = _s[(cur + 2) % 3]+_s[(cur + 1) % 3];
            }
        }
        else if (x_i > test) {
            long long tmp = x_i - 1;
            while (tmp >=  test) {
                cur = (cur + 1) % 3; -- tmp;
                _s[cur] = _s[(cur + 2) % 3] - _s[(cur + 1) % 3];
            }
        }
        else  { -- cur; }
        cout << _s[cur] << "\n";

    }    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
