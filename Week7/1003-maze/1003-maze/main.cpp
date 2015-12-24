//
//  main.cpp
//  1003-maze
//
//  Created by Kieran Will on 11/16/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define EACH(x, n) for((x) = 1; (x) <= (n); ++ (x))
using namespace std;

const int MAXN = 30;
bool maze[MAXN][MAXN];
bool v[MAXN][MAXN];
int N, i, j, ans;

void init();
bool BFS(int x, int y);
int main(int argc, const char * argv[]) {
    while (cin >> N and N != 0) {
        init();
        EACH(i, N) EACH(j, N) cin >> maze[i][j];
        
        for (int i = 0; i <= N + 1; ++ i) {
            for (int j = 0; j <= N + 1; ++ j) {
                //cout << maze[i][j] << " ";
            }
            //cout << "\n";
        }
        if(BFS(1, 1)) {
            cout << ans << "\n";
        }
        //else {
        //    cout << 0 << "\n";
        //}
    }
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

void init() {
    for (int i = 0; i < MAXN; ++ i) {
        for (int j = 0; j < MAXN; ++ j) {
            maze[i][j] = true; v[i][j] = false;
        }
    }
    ans = 0;
}

bool BFS(int x, int y) {
    v[x][y] = true;
    if (x == N and y == N) {
        return true;
    }
    if (!maze[x][y]) {
        ans ++ ;
        if(!v[x+1][y  ]) BFS(x+1,   y);
        if(!v[x  ][y+1]) BFS(x,   y+1);
        if(!v[x  ][y-1]) BFS(x,   y-1);
        if(!v[x-1][y  ]) BFS(x-1, y  );
    }
    return false;
}
/*
 5
 0 1 1 1 1
 0 0 1 1 1
 1 0 0 0 1
 1 1 1 0 1
 1 1 1 0 0
 4
 0 0 1 1
 0 0 0 1
 1 1 1 1
 1 1 1 0
 0
 
 */