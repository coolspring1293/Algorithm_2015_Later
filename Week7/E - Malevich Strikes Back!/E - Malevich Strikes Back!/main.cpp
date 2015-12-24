//
//  main.cpp
//  E - Malevich Strikes Back!
//
//  Created by Kieran Will on 11/13/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAXN 110
#define FOUND if(isFound) break
#define LOOP(i, s, t, x) for(int i = (s); i < (t); i = i + (x))
#define LOOP2(i, s, t, x) for(int i = (s); i > (t); i = i - (x))
#define JUDGE(x) if ((x) == matrix[j][i]) return false;
#define RANGE(x, y, e) (y - e < 1 or y + e > N or x - e < 1 or x + e > N)
using namespace std;

int N, matrix[MAXN][MAXN];
bool isFound = false;
bool isL(int x, int y, int EX) {
    if (RANGE(x, y, EX)) return false;
    LOOP(i, y - EX, y + EX + 1, 1) {
        LOOP (j, x - EX, x - EX + abs(i-y), 1)                JUDGE(0);
        LOOP (j, x - EX + abs(i-y), x + EX - abs(i-y) + 1, 1) JUDGE(1);
        LOOP2(j, x + EX, x + EX - abs(i-y), 1)                JUDGE(0);
    }
    return true;
}
int main(int argc, const char * argv[]) {
    while (cin >> N and N != 0) {
        LOOP(i, 1, N+1, 1) LOOP(j, 1, N+1, 1)
            cin >> matrix[i][j];
        isFound = false;
        LOOP2(g, (N % 2 == 0 ? N - 1: N), 2, 2) {
            LOOP(i, 1, N, 1) { LOOP(j, 1, N, 1) {
                    if(0 == matrix[i][j] and isL(i, j, g/2)) {
                        cout << g << endl;
                        isFound = true; break;
                    } FOUND;
                } FOUND;
            } FOUND;
        }
        if(!isFound) cout<< "No solution\n";
    }
    return 0;
}
/*
 6
 1 1 0 1 1 0
 1 0 0 0 1 1
 0 0 0 0 0 0
 1 0 0 0 1 1
 1 1 0 1 1 1
 0 1 1 1 1 1
 4
 1 0 0 1
 0 0 0 0
 0 0 0 0
 1 0 0 1
 0
 
 
 
 6
 1 1 1 1 1 1
 1 1 0 1 1 1
 1 0 0 0 1 1
 1 1 0 1 1 1
 1 1 0 1 1 1
 1 1 1 1 1 1
 6
 1 1 1 1 1 1
 1 1 0 1 1 1
 1 0 0 0 1 1
 1 1 0 1 1 1
 1 1 1 1 1 1
 1 1 1 1 1 1
 6
 1 1 1 0 1 1
 1 1 0 0 1 1
 1 0 0 0 0 1
 1 1 0 0 1 1
 1 1 1 0 1 1
 1 1 1 1 1 1
 6
 1 1 1 0 1 1
 1 1 0 1 1 1
 1 0 0 0 0 1
 1 1 0 1 1 1
 1 1 1 0 1 1
 1 1 1 1 1 1

 
 */