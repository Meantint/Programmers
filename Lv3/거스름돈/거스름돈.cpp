#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n, vector<int> money)
{
    int mSize = money.size();
    for (int k = 0; k < mSize; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dp[i] != 0 && i + money[k] <= n) {
                dp[i + money[k]] += dp[i];
                dp[i + money[k]] %= 1000000007;
            }
        }
    }

    return dp[n];
}

int solution(int n, vector<int> money)
{
    dp.resize(n + 1, 0);
    dp[0] = 1;
    sort(money.begin(), money.end(), greater<>());

    return solve(n, money);
}