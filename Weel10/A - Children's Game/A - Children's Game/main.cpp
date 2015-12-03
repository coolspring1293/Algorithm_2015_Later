//
//  main.cpp
//  A - Children's Game
//
//  Created by Kieran Will on 12/2/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string s;
std::vector<std::string> V;
bool cmp (const string &a, const string &b) {
    if(a.size() == b.size()) return a > b;
    string tmp1 = a + b , tmp2 = b + a;
    return tmp1 > tmp2;
}
int main(int argc, const char * argv[]) {
    while (cin >> N and N != 0) {
        V.clear();
        for (int i = 0; i < N; ++ i) {
            cin >> s;
            V.push_back(s);
        }
        sort(V.begin(), V.end(), cmp);
        for (int i = 0; i < V.size(); ++ i) {
            cout << V[i];
        }
        cout << "\n";
    }
    return 0;
}
/*
 4
 123 124 56 90
 5
 123 124 56 90 9
 5
 9 9 9 9 9
 0
 
 321
 141411111411
 900
 10
 0
 00
 
 321
 141411111411
 900
 10
 0
 00
 */