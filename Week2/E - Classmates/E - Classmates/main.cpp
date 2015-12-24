//
//  main.cpp
//  E - Classmates
//
//  Created by Kieran Will on 9/30/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#define MSIZE 10001
using namespace std;

class Node {
public:
    int _n;
    string _in;
    string _out;
     Node(int n, string& in, string & out): _in(in), _out(out), _n(n) {}
    
};


class Node2 {
public:
    int _n;
    string _name;
    Node2(int n, string in): _name(in), _n(n) {}
    
};

int N, M, tap;
bool vis[MSIZE];
string s_tmp1, s_tmp2;
vector<Node> _v;
vector<Node> _vv[MSIZE];
vector<Node2> _b;
vector<int> check[MSIZE];
set<string> _ss;

void clear_vv();
int main(int argc, const char * argv[]) {
    while (cin >> N >> M) {
        _v.clear(); memset(vis, false, sizeof(vis)); clear_vv();
        for (int i = 0; i < M; ++ i) {
            cin >> s_tmp1 >> s_tmp2;
            _v.push_back(Node(i, s_tmp1, s_tmp2));
            _ss.insert(s_tmp2); _ss.insert(s_tmp1);//add to the set
        }
        set<string>::iterator it; int _c = 0;
        for (it = _ss.begin(); it != _ss.end(); ++ it) {
            _b.push_back(Node2(_c, *it));
            ++ _c;
        }
        cin >> s_tmp1;
        for (int i = 0; i < M; ++ i) {
            if (s_tmp1 == _v[i]._in) {
                tap = i; break;
            }
        }
        vis[tap] = true;
        
        
        
    }
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}


void clear_vv() {
    for (int i = 0; i < MSIZE; ++ i) {
        _vv[i].clear();
    }
    for (int i = 0; i < MSIZE; ++ i) {
        check[i].clear();
    }
}
