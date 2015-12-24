//
//  main.cpp
//  Cipher Message
//
//  Created by Kieran Will on 9/22/15.
//  Copyright (c) 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


string  _s;
int main(int argc, const char * argv[]) {
    while (cin >> _s) {
        stack<char> s;
        size_t len = _s.size();
        for (int i = 0; i < len; ++ i) {
            if (!s.empty() and s.top() == _s[i]) {
                s.pop();
            }
            else {
                s.push(_s[i]);
            }
        }
        string tmp;
        while (!s.empty()) {
            tmp += s.top();
            s.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }
    return 0;
}
/*
 wwstdaadierfflitzzz
 
 */