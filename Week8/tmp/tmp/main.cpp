#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
const int N = 100 + 10;
const int INF = 1 << 29;

std::vector<int> factors[N];
char __string[N], __answer[N];
int dp[N][N];

void trans(int x, char* dest) {
    if (x <= 9) {
        dest[0] = x + '0';
        dest[1] = 0;
    } else if (x <= 99) {
        dest[0] = x / 10 + '0';
        dest[1] = x % 10 + '0';
        dest[2] = 0;
    } else {
        dest[0] = '1';
        dest[1] = dest[2] = '0';
        dest[3] = 0;
    }
}

int count_digit(int x) {
    char buffer[5];
    trans(x, buffer);
    return strlen(buffer);
}

int next[N][N][N];

int solve(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int &result = dp[l][r];
    result = INF;
    for (int k = l; k < r; ++ k) {
        result = std::min(result, solve(l, k) + solve(k + 1, r));
    }
    next[l][r][l] = l - 1;
    for (int i = l + 1, j = l - 1; i <= r; ++ i) {
        while (j >= l && __string[i] != __string[j + 1]) {
            j = next[l][r][j];
        }
        j += __string[i] == __string[j + 1];
        next[l][r][i] = j;
    }
    result = std::min(result, r - l + 1);
    int shortest = r - next[l][r][r];
    if ((r - l + 1) % shortest == 0) {
        int amount = (r - l + 1) / shortest;
        for (int i = 0; i < factors[amount].size(); ++ i) {
            int number = factors[amount][i];
            if (number > 1) {
                int len = (r - l + 1) / number;
                int temp = count_digit(number) + 2 + solve(l, l + len - 1);
                result = std::min(result, temp);
            }
        }
    }
    return result;
}

void get_string(int l, int r, char* answer, int &start) {
    for (int k = l; k < r; ++ k) {
        if (dp[l][k] + dp[k + 1][r] == dp[l][r]) {
            get_string(l, k, answer, start);
            get_string(k + 1, r, answer, start);
            return;
        }
    }
    int shortest = r - next[l][r][r];
    if (r - l + 1 == dp[l][r]) {
        for (int i = l; i <= r; ++ i) {
            answer[start ++] = __string[i];
        }
        answer[start] = 0;
    } else if ((r - l + 1) % shortest == 0) {
        int amount = (r - l + 1) / shortest;
        for (int i = 0; i < factors[amount].size(); ++ i) {
            int number = factors[amount][i];
            if (number > 1) {
                int len = (r - l + 1) / number;
                int temp = count_digit(number) + 2 + dp[l][l + len - 1];
                if (temp == dp[l][r]) {
                    char buffer[5];
                    trans(number, buffer);
                    strcpy(answer + start, buffer);
                    start += strlen(buffer);
                    answer[start ++] = '(';
                    get_string(l, l + len - 1, answer, start);
                    answer[start ++] = ')';
                    answer[start] = 0;
                    return;
                }
            }
        }
    }
}

int main() {
    for (int i = 1; i < N; ++ i) {
        for (int j = i; j < N; j += i) {
            factors[j].push_back(i);
        }
    }
    
    scanf("%s", __string + 1);
    int n = strlen(__string + 1);
    memset(dp, -1, sizeof(dp));
    int min_length = solve(1, n);
    int length = 0;
    get_string(1, n, __answer, length);
    puts(__answer);
    return 0;
}