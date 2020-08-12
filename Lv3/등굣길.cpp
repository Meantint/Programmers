#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int size = puddles.size();
    for (int i = 0; i < size; ++i) {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }
            if (dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
            }
            if (dp[i][j - 1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    answer = dp[m][n];

    return answer;
}

int main()
{
    cout << solution(4, 3, { { 2, 2 } }) << '\n';

    return 0;
}