//
//  main.cpp
//  C - Folding
//
//  Created by Kieran Will on 11/21/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define N 202
#define INF 0x3f3f3f3f
#define LP(i, s, e, b) for (int i = (s); i < (e); i = i + (b))
using namespace std;
std::vector<int> _v[N];
string _s, _a;
int dp[N][N], _next[N][N][N];
string intToStr(int x) {
    string buffer;
    x *= 10;
    while (x /= 10) buffer += (x % 10 + '0');
    reverse(buffer.begin(), buffer.end());
    return buffer;
}
int DigCnt(int x) {
    return static_cast<int>(intToStr(x).length());
}
int getSol(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int &res = dp[l][r];
    res = INF;
    LP(k, l, r, 1) res = min(res, getSol(l, k) + getSol(k + 1, r));
    _next[l][r][l] = l - 1;
    int t = l - 1;
    LP(i, l+1, r+1, 1) {
        while (t >= l and _s[i] != _s[t + 1])
            t = _next[l][r][t];
        t += _s[i] == _s[t + 1];
        _next[l][r][i] = t;
    }
    res = min(res, r - l + 1);
    int sht = r - _next[l][r][r];
    if ((r - l + 1) % sht == 0) {
        int amt = (r - l + 1) / sht;
        LP(i, 0, _v[amt].size(), 1) {
            int base = _v[amt][i];
            if (base > 1) {
                int __ll = (r - l + 1) / base, \
                __tp = DigCnt(base) + 2 + getSol(l, l + __ll - 1);
                res = min(res, __tp);
            }
        }
    }
    return res;
}

void repStr(int l, int r, string& answer, int &_start) {
    LP(k, l, r, 1)
        if (dp[l][k] + dp[k + 1][r] == dp[l][r]) {
            repStr(l, k, answer, _start);
            repStr(k + 1, r, answer, _start);
            return;
        }
    int sht_index = r - _next[l][r][r];
    if (r - l + 1 == dp[l][r]) {
        string tmp;
        LP(i, l, r+1, 1) tmp += _s[i];
        answer += tmp;
        return;
    }
    if ((r - l + 1) % sht_index == 0) {
        int amt = (r - l + 1) / sht_index;
        LP(i, 0, _v[amt].size(), 1) {
            int ind_t = _v[amt][i];
            if (ind_t > 1) {
                int __ll = (r - l + 1) / ind_t, \
                __tp = DigCnt(ind_t) + 2 + dp[l][l + __ll - 1];
                if (__tp == dp[l][r]) {
                    answer += intToStr(ind_t);
                    answer += '(';
                    _start ++;
                    //递归输出
                    repStr(l, l + __ll - 1, answer, _start);
                    answer += ')';
                    _start ++;
                    return;
                }
            }
        }
    }
}

int main() {
    LP(i, 1, N, 1) LP(j, i, N, i) _v[j].push_back(i);
    cin >> _s;
    _s = ' ' + _s;
    int n = static_cast<int>(_s.length());
    memset(dp, -1, sizeof(dp));
    getSol(1, n);
    int length = 0;
    repStr(1, n, _a, length);
    cout << _a << "\n";
    return 0;
}

/*

 AAAAAAAAAABABABCCD
 9(A)3(AB)CCD
 NEERCYESYESYESNEERCYESYESYES
 2(NEERC3(YES))
 2(NEERC3(YES)) 

 AAAAAAAAAABABABCCD
 9(A)3(AB)CCD 
 NEERCYESYESYESNEERCYESYESYES

 */