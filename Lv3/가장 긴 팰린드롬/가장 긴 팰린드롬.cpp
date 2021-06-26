#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> dp;

int solve(string s)
{
    int ret = 1;
    int sSize = s.size();
    dp = vector<vector<bool>>(sSize, vector<bool>(sSize, false));

    for (int i = 0; i < sSize; ++i) {
        dp[i][i] = true;
    }
    --sSize;  // 범위 초과 방지
    for (int i = 0; i < sSize; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    ++sSize;  // 복구

    for (int k = 2; k < sSize; ++k) {
        int kRange = sSize - k;

        for (int i = 0; i < kRange; ++i) {
            if (s[i] == s[i + k]) {
                dp[i][i + k] = dp[i + 1][i + k - 1];
                if (dp[i][i + k]) {
                    ret = k + 1;
                }
            }
            else {
                dp[i][i + k] = false;
            }
        }
    }

    return ret;
}

int solution(string s)
{
    return solve(s);
}