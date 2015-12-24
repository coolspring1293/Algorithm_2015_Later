//
//  main.cpp
//  弗洛伊德算法
//
//  Created by Kieran Will on 12/25/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

//
//  main.cpp
//  Floyd_alg
//
//  Created by Kieran Will on 1/12/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAX_ADJ_SIZE 101
#define MAX_ELEMENT 1
using namespace std;

//有向带权图的弗洛伊德算法
void shortest(int adj[][MAX_ADJ_SIZE], unsigned size){
    int floyd[MAX_ADJ_SIZE][MAX_ADJ_SIZE];
    for (int i = 0; i < size; ++ i) {
        for (int j = 0; j < size; ++ j) {
            floyd[i][j] = i;
        }
    }
    for (int k = 0; k < size; ++ k) {
        for (int i = 0; i < size; ++ i) {
            for (int j = 0; j < size; ++j ) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    floyd[i][j] = floyd[k][j];
                }
            }
        }
    }
}


void insert(vector<int> &tmp, int n) {
    for (int i = 0; i < tmp.size(); ++ i) {
        if(tmp[i] == n) return;
    }
    tmp.push_back(n);
}


bool DFS(int m[][100000], int size, int egd) {
    for (int off = 0; off < size; ++ off) {
        bool *test = new bool [size];
        int *visit = new int [size];
        for (int i = 0; i < size; ++ i) { test[i] = false; }
        test[off] = true;
        int all = 1, k = 0, i = off;
        while (i < size + off) {
            for (int j = off; j < size+off; ++ j) {
                if (j != off and test[j%size] == true) { //cout << "size=" <<size << " off=" << off;cout <<"  j="<< j  << "\n";
                    return true; }
                else if (m[i%size][j] < 10000) { //cout << "i=" << i << " j=" << j <<" m[i][j]="<<m[i][j] <<" \n";
                    test[j%size] = true; visit[k] = i; i = j; ++ k; ++ all; }
            }
            k --;
            i = visit[k];
            
            if (all == size) { break; }
        }
        cout << "\n";
    }
    
    
    return false;
}


int main () {
    int _count_test, a, b;
    cin >> _count_test;
    int _tms, _size;//100000
    
    
    for (int i = 0; i < _count_test; ++ i) {
        cin >> _size;
        int adj[_size][100000];
        for (int ii = 0; ii < _size; ++ ii) {
            for (int jj = 0; jj < _size; ++ jj) {
                adj[ii][jj] = 100000;
            }
        }
        cin >> _tms;
        for (int j = 0; j < _tms; ++ j) {
            cin >> a >> b;
            adj[a-1][b-1] = 1;
        }
        string sol = !DFS(adj, _size, _tms) ? "There exists a cycle.\n" : "It is acyclic.\n";
        cout << sol;
    }
    
    return 0;
}


int main_01() {
    int _count_test, a, b;
    cin >> _count_test;
    int _tms;
    
    
    for (int i = 0; i < _count_test; ++ i) {
        int adj[101][101];
        vector<int> tmp;
        for (int ii = 0; ii < 101; ++ ii) {
            for (int jj = 0; jj < 101; ++ jj) {
                adj[ii][jj] = 10000;
            }
        }
        cin >> _tms;
        for (int j = 0; j < _tms; ++ j) {
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
            insert(tmp, a);
            insert(tmp, b);
        }
        sort(tmp.begin(), tmp.end());
        shortest(adj, tmp[tmp.size()-1]+1);
        for (int j = 0; j < tmp.size()-1; ++ j) {
            cout << tmp[j+1] << ":" << adj[0][tmp[j+1]] << "\n";
        }
        cout << "---\n";
    }
    
    
    return 0;
}


void shortest_floyd(int adj[][MAX_ADJ_SIZE], int floyd[][MAX_ADJ_SIZE], unsigned size){
    //init
    for (int i = 0; i < size; ++ i) {
        for (int j = 0; j < size; ++ j) {
            floyd[i][j] = i;
        }
    }
    for (int k = 0; k < size; ++ k) {
        for (int i = 0; i < size; ++ i) {
            for (int j = 0; j < size; ++j) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    floyd[i][j] = floyd[k][j];
                }
            }
        }
    }
}

int main_t(int argc, const char * argv[]) {
    
    
    int adj[MAX_ADJ_SIZE][MAX_ADJ_SIZE];
    int fly[MAX_ADJ_SIZE][MAX_ADJ_SIZE];
    memset(adj, MAX_ELEMENT, sizeof(adj)/sizeof(int));
    memset(fly, MAX_ELEMENT, sizeof(fly)/sizeof(int));
    unsigned n = 5;
    
    adj[0][1] = 3;
    adj[0][2] = 4;
    adj[1][2] = 5;
    adj[1][3] = 2;
    adj[1][4] = 2;
    adj[2][3] = 6;
    adj[3][4] = 7;
    adj[1][0] = 3;
    adj[2][0] = 4;
    adj[2][1] = 5;
    adj[3][1] = 2;
    adj[4][1] = 2;
    adj[3][2] = 6;
    adj[4][3] = 7;
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j){
            cout << setw(12) << adj[i][j];
        }
        cout << "\n";
    }
    shortest_floyd(adj, fly, n);
    cout << "\n--------------------------------\n";
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j){
            cout << setw(12) << adj[i][j];
        }
        cout << "\n";
    }
    cout << "\n--------------------------------\n";
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j){
            cout << setw(12) << fly[i][j];
        }
        cout << "\n";
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
