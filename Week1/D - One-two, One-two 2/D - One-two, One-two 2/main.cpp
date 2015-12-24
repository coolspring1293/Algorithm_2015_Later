//
//  main.cpp
//  D - One-two, One-two 2
//
//  Created by Kieran Will on 9/22/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//


#include <iostream>
#include <cstring>
#define MAXN 1000001
using namespace std;

class Node {
public:
    int _digit, _mod;
    int _last_node;
    Node(int d, int m, int s) :     _digit(d), _mod(m), _last_node(s) {}
    void Set(int d, int m, int s) { _digit = d, _mod = m, _last_node = s;}
    Node() {};
};


Node nodes[MAXN];
int N, _left, _right, _ret;
bool vis[MAXN];

void BFS() {
    while(_left < _right) {
        int tmp_mod_1 = (nodes[_left]._mod*10+1) % N;
        int tmp_mod_2 = (nodes[_left]._mod*10+2) % N;
        if (!vis[tmp_mod_1]) {
            vis[tmp_mod_1] = true; _right ++;
            nodes[_right].Set(1, tmp_mod_1, _left);
            //cout << "\n |"<<_right << " "<< 1<< " " << tmp_mod_1 << " " << _left << "\n";
            if(tmp_mod_1 == 0) { _ret = _right; return; }
        }
        if (!vis[tmp_mod_2]) {
            vis[tmp_mod_2] = true; _right ++;
            nodes[_right].Set(2, tmp_mod_2, _left);
            //cout << "\n |"<<_right << " "<< 2 << " " << tmp_mod_2 << " " << _left << "\n";
            if(tmp_mod_2 == 0) { _ret = _right; return; }
        }
        _left ++;
    }
}

void printAns(int i) {
    if   (i > 0) { printAns(nodes[i]._last_node); }
    else if (i == 0) { return; }
    cout << nodes[i]._digit;
}


int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 100000; ++ i) {
        N = i; //cout << "\n | N=" << N << " : ";
        cout << "ss[" << N << "] = ";
        if (N == 1) { cout << "\"1\"\n"; continue; }
        if (N == 2) { cout << "\"2\"\n"; continue; }
        //init start
        nodes[1].Set(1, 1, 0);
        nodes[2].Set(2, 2, 0);
        _left = 1; _right = 2;
        _ret = 0;
        cout << "\"";
        memset(vis, false, sizeof(vis));
        vis[1] = true; vis[2] = true;
        //init end
        BFS();
        if(_ret == 0) { cout << "Impossible\";\n"; continue; }
        printAns(_ret); cout << "\";\n";
    
    }
    return 0;
}
