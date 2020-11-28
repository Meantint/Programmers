# 프로그래머스 - 카카오프렌즈 컬러링북

&nbsp;문제가 없는데 계속 안풀려서 한참을 찾다가 전역변수 값을 `solution` 함수 안에서 초기화 했더니 바로 풀렸다. 왜 그런걸까.. 의문

- Programmers - [카카오프렌즈 컬러링북](https://programmers.co.kr/learn/courses/30/lessons/1829)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `bfs`를 사용하여 탐색한 부분들의 값을 `0`으로 바꿔준다.

- `p[cx][cy]`가 `0`이라면 `continue` 해준다.

- `p[cx][cy]`가 `0`이 아니라면 `++cnt` 해주고 코드를 이어나간다.

- 상하좌우를 가리키는 배열 `dx[4]`, `dy[4]`를 선언하여 `bfs` 함수 안에서 for문으로 상하좌우를 탐색해준다.

- for문 안에서 `p[cx][cy]`와 `p[ccx][ccy]`의 색깔이 다르거나 `ccx` 혹은 `ccy`의 범위가 배열을 벗어나면 `q.push()`를 하면 안된다.

## Code

```cpp
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int len_x, len_y;
int areaCnt = 0;
int bigArea = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j, vector<vector<int>>& p)
{
    int cnt = 0;

    queue<PII> q;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (p[cx][cy] == 0) {
            continue;
        }
        ++cnt;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            // 범위 밖이면 컷
            if (ccx < 0 || ccx >= len_x || ccy < 0 || ccy >= len_y) {
                continue;
            }
            // 색깔이 다르다면
            if (p[cx][cy] != p[ccx][ccy]) {
                continue;
            }
            q.push(make_pair(ccx, ccy));
        }
        p[cx][cy] = 0;
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<int> answer(2);

    areaCnt = 0, bigArea = 0;
    len_x = m, len_y = n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 칠하지 않은 영역
            if (picture[i][j] == 0) {
                continue;
            }
            else {
                ++areaCnt;
                int cnt = bfs(i, j, picture);
                if (bigArea < cnt) {
                    bigArea = cnt;
                }
            }
        }
    }
    answer[0] = areaCnt;
    answer[1] = bigArea;

    return answer;
}
```
