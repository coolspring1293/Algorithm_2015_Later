//
//  main.cpp
//  C - Minimal Coverage
//
//  Created by Kieran Will on 11/28/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 10002

class Node {
public:
    int _l, _h;
    Node(int a, int b) { _l = a; _h = b; }
    void print() const { std::cout << _l << " " << _h << "\n"; }
};

bool cmp(Node &x, Node &y) {
    if (x._l != y._l) { return x._l < y._l; }
    return x._h < y._h;
}


std::vector<Node> vt;
int M, rec[MAXN], low, high;
//贪了个心
int main(int argc, const char * argv[]) {
    while (std::cin >> M) {
        while (std::cin >> low >> high and (low or high)) {
            vt.push_back(Node(low, high));
        }
        sort(vt.begin(), vt.end(), cmp);
        vt.push_back(Node(INF, INF));//it is necessary
        int cur = 0, ans = 0, nxt = 0;
        bool haveSol = false, flg = false;
        for (int i = 0; i < vt.size() - 1; ++ i) {
            if (vt[i]._l <= cur and vt[nxt]._h <= vt[i]._h ) {
                nxt = i;
                flg = true;
            }
            if (vt[i+1]._l > cur and flg) {
                flg = false;
                cur = vt[nxt]._h;
                rec[ans++] = nxt;
            }
            if (cur >= M) {
                haveSol = true;
                std::cout << ans << "\n";
                for (int j = 0; j < ans; ++ j) {
                    vt[rec[j]].print();
                }
                break;
            }
            
        }
        if (!haveSol) {
            std::cout << "No solution\n";
        }
    }
    return 0;
}
/*
 1
 -1 0
 -5 -3
 2 5
 0 0
 1
 -1 0
 0 1
 0 0
 
 No solution
 1
 0 1
 
 */
