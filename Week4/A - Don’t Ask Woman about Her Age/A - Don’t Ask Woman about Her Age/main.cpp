//
//  main.cpp
//  A - Don’t Ask Woman about Her Age
//
//  Created by Kieran Will on 10/20/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MSIZE 1000002
using namespace std;
// 进制转换

int real_data[MSIZE];
string _s;

bool divideOrg(int *, int, int);
int  getRealAge();
int main(int argc, const char * argv[]) {
    cin >> _s;
    for (int i = 0; i < _s.length(); ++ i) {
        if (isdigit(_s[i])) { real_data[i] = _s[i] - '0';      }
        else                { real_data[i] = _s[i] - 'A' + 10; }
    }
    int real_age = getRealAge();
    if (real_age == -1) { cout << "No solution.\n"; }
    else                { cout << real_age << "\n"; }
    return 0;
}


bool divideOrg(int *data, int base, int div) {
    int tmp = 0;
    for (int i = 0; i < _s.length(); i ++) {
        tmp *= base; tmp += data[i];
        if (tmp >= div) { tmp = tmp - (tmp / div) * div; }
    }
    return (tmp == 0) ;
}
int getRealAge() {
    int tmp = 0;
    for (int i = 0; i < _s.length(); i ++) {
        if (real_data[i] > tmp) { tmp = real_data[i]; }
    }
    if (tmp <= 1) { return 2; }
    for (int i = tmp + 1; i <= 36; i ++) {
        if (divideOrg(real_data, i, i-1)) { return i; }
    }
    return -1;
}
/*
A1A
  
  */