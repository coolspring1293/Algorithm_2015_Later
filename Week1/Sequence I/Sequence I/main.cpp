//
//  main.cpp
//  Sequence I
//
//  Created by Kieran Will on 9/22/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define SIZE 1001
using namespace std;

int N, a[SIZE];

int main(int argc, const char * argv[]) {
    int sum = 0, ans = 0, location = 0;
    while (cin >> N) {
        for (int i = 0; i < N; ++ i) {
            cin >> a[i];
            sum = 0; ans = 0;
            for (int j = 1; j < N - 1; ++ j) {
                sum = a[j-1] + a[j] + a[j+1];
                if (sum > ans) {
                    ans = sum;
                    location = j;
                }
            }
        }
        cout << ans << " " << location + 1 << "\n";
    }
    return 0;
}
/* 
 
 6
 1 4 4 4 1 1
 
*/