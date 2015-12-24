//
//  main.cpp
//  E - Classmates 2
//
//  Created by Kieran Will on 10/6/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#define MAXN 20

using namespace std;

int M, N, res, w[MAXN], r[MAXN], q[MAXN];
string s_a, s_b, s_t, names[MAXN];
vector<int> v[MAXN], v1[MAXN], v2[MAXN];
map<string, int> id;
bool f[MAXN];

int  getID(string &s);
void DFS(int, int, int);
void init(string &a, string &b);
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    while (cin >> N >> M) {
        while (M --) {
            cin >> s_a >> s_b;
            init(s_a, s_b);
        }
        cin >> s_t; q[0] = getID(s_t);
        res = N; f[q[0]] = true;
        
        DFS(0, 0, 1);
        cout << res << "\n";
        
        for (int i = 1; i <= res; ++ i) {
            cout << v1[i].size() << "\n";
            for (int j = 0; j < v1[i].size(); ++ j) {
                cout << names[v1[i][j]] << " " << names[v2[i][j]] << "\n";
            }
        }
    }
    return 0;
}

void init(string &a, string &b) {
    int id_a = getID(a), id_b = getID(b);
    v[id_a].push_back(id_b); v[id_b].push_back(id_a);
}

int getID(string &s) {
    if (id.find(s) == id.end()) {
        size_t i = id.size();
        names[i] = s; id[s] = static_cast<int>(i); return static_cast<int>(i);
    }
    return id[s];
}

void DFS(int a, int b, int c) {
    if (N == c) {
        if (w[q[N-1]] < res) {
            for (int i = 0; i <= res; ++ i) { v1[i].clear(); v2[i].clear(); }
            res = w[q[N-1]];
            for (int i = 0; i < N; ++ i) { v1[w[i]].push_back(r[i]); v2[w[i]].push_back(i); }
        }
        return;
    }
    int tmp_q = q[a]; bool flag = false;
    for (int i = 0; i < v[tmp_q].size(); ++ i) {
        int tmp_lct = v[tmp_q][i];
        if (f[tmp_lct]) { continue; }
        flag = true; q[c] = tmp_lct; w[tmp_lct] = b + 1; r[tmp_lct] = tmp_q; f[tmp_lct] = true;
        if (a < c and w[q[a+1]] <= b) { DFS(a+1, b,   c+1); }
        else                          { DFS(0,   b+1, c+1); }
        f[tmp_lct] = false;
    }
    if (!flag) {
        if (a < c and w[q[a+1]] <= b) { DFS(a+1, b,   c); }
        else                          { DFS(0,   b+1, c); }
    }
}/*
  
  6
  7
  Tanya Lena
  Tanya Katya
  Tanya Masha
  Lena Natasha
  Lena Vitya
  Natasha Vitya
  Masha Vitya
  Tanya
  
  */