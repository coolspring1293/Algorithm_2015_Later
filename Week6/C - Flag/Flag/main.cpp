//
//  main.cpp
//  Flag
//
//  Created by Kieran Will on 11/1/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
using namespace std;
const int M = 55;
int n;
long long a[M];

int main(int argc, const char * argv[]) {
    a[1] = a[2] = 2LL;
    for (int i = 3; i < M; ++ i) a[i] = a[i-1] + a[i-2];
    while (cin >> n and n != 0) cout << a[n] << "\n";
    return 0;
}
