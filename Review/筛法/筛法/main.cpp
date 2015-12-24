//
//  main.cpp
//  筛法
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MSIZE 31643
using namespace std;

using std::cin;
using std::cout;


int m[MSIZE], _count = 0;
bool flg[MSIZE];
int main(int argc, const char * argv[]) {
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) {
            for(int j = i * 2 ; j < MSIZE ; j += i) { flg[j] = 1; }
        }
    }
    for(int i = 2; i < MSIZE ; ++ i) {
        if (!flg[i]) { m[++ _count] = i; }
    }
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
