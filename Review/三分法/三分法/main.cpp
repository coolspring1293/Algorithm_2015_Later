//
//  main.cpp
//  三分法
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//
//
//  main.cpp
//  C - Bookshelf
//
//  Created by Kieran Will on 10/13/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;
const double EPS = 1e-8;
int h, H, L;
double getS (double x) { return ((H / 2.0 * x) / sqrt(x * x + h * h) - x); }


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //while (scanf("%d%d%d", &h, &H, &L) != EOF) {
    while (cin >> h >> H >> L) {
        double _left = 0, _right = H;
        while(_right - _left >= EPS) {
            double tmp_1 = (_left+_right) / 2.0, tmp_2 = (tmp_1+_right) / 2.0;
            double ans1 = getS(tmp_1),           ans2 = getS(tmp_2);
            if (ans1 > ans2) { _right = tmp_2; }
            else             { _left  = tmp_1; }
        }
        cout << fixed << setprecision(6) << getS(_left) << "\n";
    }
    return 0;
}
