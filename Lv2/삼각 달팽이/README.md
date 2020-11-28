# 프로그래머스 - 삼각 달팽이

&nbsp;이전에 풀었을 때는 `make` 함수를 재귀적으로 수행해서 한 번만 호출해도 모든 배열이 만들어지도록 하였다. 이전에 짠 코드가 조금 더 알아보기 쉽고 간결하게 짠 것 같다.

- Programmers - [삼각 달팽이](https://programmers.co.kr/learn/courses/30/lessons/68645)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 가장 외곽 삼각형 모양을 만들어주는 함수 `make`를 만든다.

- `make` 함수가 한 번 실행될 때마다 시작점이 `x` 좌표가 `2`만큼 커지고 `y` 좌표가 `1`만큼 커진다. 외각의 길이가 `3` 만큼 작아진다.

- `n * n` 배열을 만들어서 하였기 때문에 값을 넣어준 부분만 `answer.push_back()` 할 수 있도록 한다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int val = 1;
int cnt, idx = 0;

void make(int x, int y, int k, vector<vector<int>>& b)
{
    // 세로
    for (int i = 0; i < k; ++i) {
        b[x + i][y] = val;
        ++val;
    }
    // 가로
    for (int i = 1; i < k; ++i) {
        b[x + k - 1][y + i] = val;
        ++val;
    }
    // 대각선
    for (int i = 1; i < k - 1; ++i) {
        b[x + k - 1 - i][y + k - 1 - i] = val;
        ++val;
    }
}

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n, 0));
    cnt = (n + 2) / 3;
    while (idx < cnt) {
        make(0 + idx * 2, 0 + idx, n - idx * 3, board);
        ++idx;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(board[i][j]);
        }
    }

    return answer;
}
```
