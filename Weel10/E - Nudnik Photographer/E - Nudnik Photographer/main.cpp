//
//  main.cpp
//  E - Nudnik Photographer
//
//  Created by Kieran Will on 12/3/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
const int MAXN = 56;
int n, pht[MAXN];


int main(int argc, const char * argv[]) {
    while (std::cin >> n) {
        pht[1] = pht[2] = 1;
        pht[3] = 2;
        for (int i = 4; i <= n; ++ i) {
            pht[i] = pht[i-1] + pht[i-3] + 1;
        }
        std::cout << pht[n] << "\n";
    }
    return 0;
}
