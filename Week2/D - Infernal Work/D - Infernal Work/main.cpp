//
//  main.cpp
//  D - Infernal Work
//
//  Created by Kieran Will on 9/29/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
using namespace std;

int a, b, n;
int main(int argc, const char * argv[]) {
    while (cin >> a >> b) {
        cin >> n;
        long long ans = 0;
        for (int i = 0; i < n; ++ i) {
            int tmp1 = (i/b)*b;
            int tmp2 = (i/a)*a;
            if (tmp1 > tmp2) {
                ans += tmp1 - tmp2;
            }
        }
        cout << ans << "\n";
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 3 4 10
 4
 2 4 10
 0
 */