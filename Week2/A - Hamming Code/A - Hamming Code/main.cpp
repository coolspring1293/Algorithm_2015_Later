//
//  main.cpp
//  A - Hamming Code
//
//  Created by Kieran Will on 9/30/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
using namespace std;


bool isGood(int *a) {
    if ((a[1] + a[2] + a[3]) % 2 != a[4]) {
        return false;
    }
    if ((a[0] + a[2] + a[3]) % 2 != a[5]) {
        return false;
    }
    if ((a[0] + a[1] + a[3]) % 2 != a[6]) {
        return false;
    }
    return true;
}

int tmp[7];
bool flg;
int main(int argc, const char * argv[]) {
    while (cin >> tmp[0]) {
        flg = false;
        for (int i = 1; i < 7; ++ i) {
            cin >> tmp[i];
        }
        if (isGood(tmp)) {
            for (int i = 0; i < 6; ++ i) {
                cout << tmp[i] << " ";
            }
            cout << tmp[6] << "\n"; flg = true; continue;
        }
        else {
            for (int i = 0; i < 7; ++ i) {
                tmp[i] = 1 - tmp[i];
                if (isGood(tmp)) {
                    break;
                }
                else {
                    tmp[i] = 1 - tmp[i];
                }
            }
        }
        for (int i = 0; i < 6; ++ i) {
            cout << tmp[i] << " ";
        }
        cout << tmp[6] << "\n";;
    }
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 0 1 0 1 1 0 1
 1 1 1 1 1 1 1
 
 */