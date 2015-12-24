//
//  main.cpp
//  E - Kirill the Gardener 3
//
//  Created by Kieran Will on 11/7/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define M 100002
#define INF 0x7FFFFFFF
using namespace std;

class T {
public:
    long long  _m, _l, _h; T() {}
    T(long long n, long long x) { _m = n; _h = _l = x; }
    void alter(long long tmp) { if (_l > tmp) { _l = tmp; } if (_h < tmp) { _h = tmp; } }
};
class Node {
public:
    T _t;
    Node *_l, *_r;
    Node(long long n, long long x) { _t._m = n; _t._h = x; _t._l = x; _l = NULL; _r = NULL; }
};

Node *root;

void add_node(Node* &cur, long long m, long long i) {
    if (cur == NULL)          { cur = new Node(m, i);    }
    else if (cur->_t._m == m) { cur->_t.alter(i);        }
    else if (cur->_t._m <  m) { add_node(cur->_r, m, i); }
    else                      { add_node(cur->_l, m, i); }
}



long long N, m;
long long lf[M][2], rt[M][2], sol = 0, ii;


void pre2(Node* &r) {
    stack<Node*> S;
    if (!r) { return; }
    while (r or !S.empty()) {
        while (r) { S.push(r); r = r->_l; }
        r = S.top();
        S.pop();
        
        lf[ii][0] = r->_t._h - r->_t._l + min(lf[ii-1][0] + abs(r->_t._l - lf[ii-1][1]),
                                              rt[ii-1][0] + abs(r->_t._l - rt[ii-1][1]));
        lf[ii][1] = r->_t._h;
        
        rt[ii][0] = r->_t._h - r->_t._l + min(lf[ii-1][0] + abs(r->_t._h - lf[ii-1][1]),
                                              rt[ii-1][0] + abs(r->_t._h - rt[ii-1][1]));
        rt[ii][1] = r->_t._l;
        sol = (lf[ii][0] < rt[ii][0]) ? lf[ii][0] : rt[ii][0];
        ++ ii;
        r = r->_r;
    }
}



void pre(Node* &r) {
    if (r->_l) { pre(r->_l); }
    lf[ii][0] = r->_t._h - r->_t._l + min(lf[ii-1][0] + abs(r->_t._l - lf[ii-1][1]),
                                          rt[ii-1][0] + abs(r->_t._l - rt[ii-1][1]));
    lf[ii][1] = r->_t._h;

    rt[ii][0] = r->_t._h - r->_t._l + min(lf[ii-1][0] + abs(r->_t._h - lf[ii-1][1]),
                                          rt[ii-1][0] + abs(r->_t._h - rt[ii-1][1]));
    rt[ii][1] = r->_t._l;
    sol = (lf[ii][0] < rt[ii][0]) ? lf[ii][0] : rt[ii][0];
    ++ ii;
    if (r->_r) { pre(r->_r); }
}


int main(int argc, const char * argv[]) {
    lf[0][0] = 0; lf[0][1] = 0;  rt[0][0] = 0; rt[0][1] = 0; ii = 1;
    scanf("%lld", &N);
    root = new Node(0, 0);
    for (int i = 0; i < N; ++ i) { scanf("%lld", &m); add_node(root, m, i); }
    pre2(root);
    printf("%lld\n", sol + N);
    //cout <<  sol + N << "\n";
    return 0;
}

/**
 6
 3 2 5 6 2 5
 */