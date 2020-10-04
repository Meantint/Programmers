#include <iostream>
#include <string>
#include <vector>

using namespace std;

int global_n;

int dfs(int cntLeft, int cntRight)
{
    if (cntLeft < cntRight) return 0;
    if (cntLeft > global_n || cntRight > global_n) return 0;
    if (cntLeft == cntRight && cntLeft == global_n) return 1;

    int cnt = 0;
    cnt += dfs(cntLeft + 1, cntRight);
    cnt += dfs(cntLeft, cntRight + 1);

    return cnt;
}

int solution(int n)
{
    int answer = 0;

    global_n = n;
    answer = dfs(0, 0);

    return answer;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << '\n';

    return 0;
}