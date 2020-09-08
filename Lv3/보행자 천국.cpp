#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;
int dp[510][510];
vector<vector<int>> map;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;

    map = city_map;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < m; ++i) {
        if (city_map[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; ++j) {
        if (city_map[0][j] == 1)
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < m; ++i) {
        if (city_map[i][0] == 2) dp[i][0] = 0;
    }
    for (int j = 1; j < n; ++j) {
        if (city_map[0][j] == 2) dp[0][j] = 0;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (city_map[i][j] == 2) {
                int idx = 1;
                if (city_map[i - 1][j] != 2) {
                    // cout << "pass i : " << i << ", " << j << '\n';
                    while (i + idx < m && city_map[i + idx][j] == 2) {
                        ++idx;
                        // cout << "success i, j : " << i << ", " << j << ", " << idx << '\n';
                    }
                    // city_map[i + idx][j] != 2
                    if (i + idx < m) {
                        // cout << "i + idx : " << i + idx << '\n';
                        dp[i + idx][j] += dp[i - 1][j];
                    }
                }
                idx = 1;
                if (city_map[i][j - 1] != 2) {
                    // cout << "pass j : " << i << ", " << j << '\n';
                    while (j + idx < n && city_map[i][j + idx] == 2) {
                        ++idx;
                        // cout << "success i, j : " << i << ", " << j << ", " << idx << '\n';
                    }
                    // city_map[i][j + idx] != 2
                    if (j + idx < n) {
                        // cout << "j + idx : " << j + idx << '\n';
                        dp[i][j + idx] += dp[i][j - 1];
                        // cout << "dp[i][j + idx], dp[i][j - 1] = " << dp[i][j + idx] << ", " << dp[i][j - 1] << '\n';
                    }
                }
            }
            else if (city_map[i][j] == 1) {
                dp[i][j] = 0;
            }
            else if (city_map[i][j] == 0) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                if (city_map[i - 1][j] == 2) dp[i][j] -= dp[i - 1][j];
                if (city_map[i][j - 1] == 2) dp[i][j] -= dp[i][j - 1];
            }
            // cout << "dp(" << i << ", " << j << ") = " << dp[i][j] << '\n';
            dp[i][j] %= MOD;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    answer = dp[m - 1][n - 1];

    return answer;
}

int main()
{
    // cout << solution(3, 3, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << '\n';
    cout << solution(3, 6, {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}) << '\n';

    return 0;
}