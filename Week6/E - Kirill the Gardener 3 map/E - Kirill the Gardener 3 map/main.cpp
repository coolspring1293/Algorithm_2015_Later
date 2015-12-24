//
//  main.cpp
//  E - Kirill the Gardener 3 map
//
//  Created by Kieran Will on 11/8/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#define M 100002
#define INF 0x7FFFFFFF
using namespace std;

class T {
public:
    int _low, _high;
    T() { _high = 0; _low = INF; }
    T(int x) {  _high = _low = x; }
    void alter(int tmp) {
        if (_low > tmp) { _low = tmp; }
        if (_high < tmp) { _high = tmp; }
    }
};

map<int, T> V;
int N, m, j;
long long lf[M][2], rt[M][2], sol = 0, level_length;
int main(int argc, const char * argv[]) {
    scanf("%d", &N); V[0] = T(0); j = 1;
    for (int i = 0; i < N; ++ i) {
        scanf("%d", &m); V[m].alter(i);
    }
    lf[0][0] = lf[0][1] = rt[0][0] = rt[0][1] = 0;
    for (map<int, T>::iterator ii = V.begin(); ii != V.end(); ++ ii) {
        level_length = ii->second._high - ii->second._low;
        lf[j][0] = level_length +
                    min(lf[j-1][0] + abs(ii->second._low - lf[j-1][1]),
                        rt[j-1][0] + abs(ii->second._low - rt[j-1][1]));
        lf[j][1] = ii->second._high;
        
        rt[j][0] = level_length +
                    min(lf[j-1][0] + abs(ii->second._high - lf[j-1][1]),
                        rt[j-1][0] + abs(ii->second._high - rt[j-1][1]));
        rt[j][1] = ii->second._low;
        
        sol = (lf[j][0] < rt[j][0]) ? lf[j][0] : rt[j][0];
        ++ j;
    }
    printf("%lld", sol + N);
    return 0;
}

/**
 6
 3 2 5 6 2 5
 */