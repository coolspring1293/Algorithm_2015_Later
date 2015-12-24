//
//  main.cpp
//  快速幂矩阵
//
//  Created by Kieran Will on 12/24/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;

class Mat {
public:
    int size;
    double mat[N][N];
};

Mat operator * (const Mat a, const Mat b) {
    Mat c; int n = a.size; c.size = n;
    memset(c.mat, 0, sizeof(c.mat));
    for(int k = 0; k < n; ++ k) {
        for(int i = 0; i < n; ++ i) {
            if(a.mat[i][k] <= 0)  continue;
            for(int j = 0; j < n; ++ j) {
                if(b.mat[k][j] <= 0)    continue;    //剪枝
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

Mat operator ^ (Mat a, int k) {
    Mat c; int n = a.size; c.size = n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            c.mat[i][j] = (i == j);    //初始化为单位矩阵
    
    for( ; k; k >>= 1) {
        if(k&1) c = c * a;
        a = a * a;
    }
    return c;
}

//Fib
long long fib(int tmp) {
    Mat m;
    m.size = 2;
    m.mat[0][0] = 1;
    m.mat[0][1] = 1;
    m.mat[1][0] = 1;
    m.mat[1][1] = 0;
    if (tmp == 0) return 0;
    if (tmp == 1) return 1;
    return (m^(tmp-2)).mat[0][0] + (m^(tmp-2)).mat[0][1];
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 30; ++ i) {
        cout << " |f("<< i << ") = " << fib(i) << "\n";
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
