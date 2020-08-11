#include <bits/stdc++.h>

using namespace std;

int gvN, gvnumber;
int gvAnswer = 9;

void dfs(int cnt, int cur)
{
    if (cnt > 8) {
        return;
    }
    if (cur == gvnumber) {
        gvAnswer = min(gvAnswer, cnt);
        return;
    }

    int n = 0;
    for (int i = 0; i < 8; ++i) {
        n = n * 10 + gvN;
        dfs(cnt + i + 1, cur + n);
        dfs(cnt + i + 1, cur - n);
        dfs(cnt + i + 1, cur * n);
        dfs(cnt + i + 1, cur / n);
    }
}

int solution(int N, int number)
{
    gvN = N, gvnumber = number;

    dfs(0, 0);
    int answer = gvAnswer;
    if (answer == 9) {
        answer = -1;
    }
    return answer;
}