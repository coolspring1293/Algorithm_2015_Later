//
//  main.cpp
//  C - Folding
//
//  Created by Kieran Will on 11/21/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

//The constist pare
#define N 102
#define INF 0x3f3f3f3f

#define LP(i, s, e, b) for (int i = (s); i < (e); i = i + (b))
using namespace std;

vector<int> factors[N];
string str, ans;
int dp[N][N], _next[N][N][N];



void trans(int, string&);
int  count_digit(int);
int  solve(int, int);
void get_string(int, int, string&, int&);

int main(int argc, const char * argv[]) {

    LP(i, 1, N, 1) LP(j, i, N, i) factors[j].push_back(i);
    cin >> str;
    int n = static_cast<int>(str.length());
    memset(dp, -1, sizeof(dp));
    int length = 0;
    get_string(1, n, ans, length);
    cout << ans << "\n";
    return 0;
}


void trans(int x, string& dest) {
    x *= 10;
    while (x /= 10) dest += (x % 10 + '0');
    reverse(dest.begin(), dest.end());
}

int count_digit(int x) {
    string buffer; trans(x, buffer);
    return static_cast<int>(buffer.length());
}



int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int &result = dp[l][r];
    result = INF;
    
    LP(k, l, r, 1) result = min(result, solve(l, k) + solve(k+1, r));
    _next[l][r][l] = l - 1;
    int j = l - 1;
    LP(i, l+1, r+1, 1) {
        while (j >= l and str[i] != str[j+1])
            j = _next[l][r][j];
        j += str[i] == str[j+1];
        _next[l][r][i] = j;
    }

    result = min(result, r-l+1);
    int shortest = r - _next[l][r][r];
    if ((r - l + 1) % shortest == 0) {
        int amount = (r - l + 1) / shortest;
        LP(i, 0, factors[amount].size(), 1) {
            int number = factors[amount][i];
            if (number > 1) {
                int len = (r - l + 1) / number;
                int temp = count_digit(number) + 2 + solve(l, l + len - 1);
                result = min(result, temp);
            }
        }
    }
    return result;
}


void get_string(int l, int r, string& answer, int &start) {
    cout << " l=" << l << " r=" << r << " ans=" << answer << " Start=" << start << "\n";
    LP(k, l, r, 1)
        if (dp[l][k] + dp[k+1][r] == dp[l][r]) {
            std::cout << "   " << k << " " << answer << " St=" << start << "\n";
            get_string(l,   k, answer, start);
            get_string(k+1, r, answer, start);
            return;
        }
    
    int shortest = r - _next[l][r][r];
    
    if (r-l+1 == dp[l][r]) {
        answer += str;
        std::cout << "   " << answer << " St=" << start << "\n";
    }
    
    else if ((r - l + 1) % shortest == 0) {
        int amount = (r - l + 1) / shortest;
        LP(i, 0, factors[amount].size(), 1) {
            int number = factors[amount][i];
            if (number > 1) {
                int len = (r - l + 1) / number;
                int temp = count_digit(number) + 2 + dp[l][l + len - 1];
                if (temp == dp[l][r]) {
                    string buffer;
                    trans(number, buffer);
                    answer += buffer;
                    start += buffer.length();
                    answer += '(';
                    get_string(l, l + len - 1, answer, start);
                    answer += ')';
                    return;
                }
            }
        }
    }
}

/*
 AAAAAAAAAABABABCCD
 */