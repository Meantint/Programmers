#include <iostream>

using namespace std;

int dfs(int check, int cntMul, int cntPlus)
{
    if (cntPlus > 38) return 0;
    if (cntMul * 2 > cntPlus) return 0;
    if (check < 1) return 0;
    if (check == 1 && cntMul * 2 == cntPlus) return 1;

    int cnt = 0;
    if (check % 3 == 0) {
        cnt += dfs(check / 3, cntMul + 1, cntPlus);
    }
    cnt += dfs(check - 1, cntMul, cntPlus + 1);

    return cnt;
}

int solution(int n)
{
    int answer = 0;

    answer = dfs(n, 0, 0);

    return answer;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    // for (int i = 1; i < n; ++i) {
    //     cout << "i : " << i << ", solution(i) : " << solution(i) << '\n';
    // }

    return 0;
}