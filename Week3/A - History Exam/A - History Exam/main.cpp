//
//  main.cpp
//  A - History Exam
//
//  Created by Kieran Will on 10/14/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N, M, tmp, _ans = 0;
std::vector<int> _p, _s;
int main(int argc, const char * argv[]) {
    while (std::cin >> N) {
        _p.clear(); _s.clear(); _ans = 0;
        for (int i = 0; i < N; ++ i) {
            std::cin >> tmp; _p.push_back(tmp);
        }
        std::cin >> M;
        for (int i = 0; i < M; ++ i) {
            std::cin >> tmp; _s.push_back(tmp);
        }
        for (int i = 0; i < M; ++ i) {
            tmp = _s[i];
            if (std::binary_search(_p.begin(), _p.end(), tmp)) {
                ++ _ans;
            }
        }
        std::cout << _ans << "\n";
        
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
/*
 2
 1054
 1492
 4
 1492
 65536
 1492
 100
 */