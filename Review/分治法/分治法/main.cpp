//
//  main.cpp
//  分治法
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

//
//  main.cpp
//  A - The Sierpinski Fractal
//
//  Created by Kieran Will on 10/28/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//


#include <cstring>
#include <stdio.h>
#include <iostream>
#define M 1025

char G[M][2*M];

void fun(int n, int x, int y) {
    if (1 == n) {
        G[x][  y] = G[x-1][y+1] = '/' ;
        G[x][1+y] = G[x  ][y+2] = '_' ;
        G[x][3+y] = G[x-1][y+2] = '\\';
        return;
    }
    int s = 1 << (n-1);//左移n-1
    fun(n-1,   x,     y);
    fun(n-1,   x, s*2+y);
    fun(n-1, x-s,   s+y);
}

int n;
int main(int argc, const char * argv[]) {
    while (scanf("%d", &n) == 1 and n != 0) {
        memset(G, ' ', sizeof(G));
        int s = 1 << n;
        int e = s + 1;
        fun(n, s, 1);
        for (int i = 1; i <= s; ++ i) {
            for (int j = 1; j <= e; ++ j) {
                putchar(G[i][j]);
            }
            putchar('\n'); ++ e;
        }
        putchar('\n');
    }
    return 0;
}
/*
 3
 2
 1
 0
 
 */
