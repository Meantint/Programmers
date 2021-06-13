# 프로그래머스 - 행렬 테두리 회전하기

&nbsp;따로 함수로 구현하는게 편하다(사실 다른 방법이 있는지는 모름).

- Programmers - [행렬 테두리 회전하기](https://programmers.co.kr/learn/courses/30/lessons/77485)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 현재 회전할 때 사용되는 값들 중 가장 작은 값을 리턴하고 실제 `board`의 모양을 바꿔주는 `rotate` 함수를 만들어준다.

- `(start.y, start.x)`부터 시작하기 때문에 `(start.y, start.x)` 자리에 오게 될 `(start.y + 1, start.x)` 값을 미리 `prev`에 저장해둔다.

- 모서리 부분은 중복해서 연산되지 않도록 신경써서 for문 범위 설정을 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

int rotate(vector<int> query)
{
    int ret = 2112345678;

    int sy = query[0] - 1, sx = query[1] - 1;
    int ey = query[2] - 1, ex = query[3] - 1;

    int prev = board[sy + 1][sx];
    ret = prev;
    for (int x = sx; x <= ex; ++x) {
        int tmp = board[sy][x];
        board[sy][x] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int y = sy + 1; y <= ey; ++y) {
        int tmp = board[y][ex];
        board[y][ex] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int x = ex - 1; x >= sx; --x) {
        int tmp = board[ey][x];
        board[ey][x] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int y = ey - 1; y > sy; --y) {
        int tmp = board[y][sx];
        board[y][sx] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }

    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    board = vector<vector<int>>(rows, vector<int>(columns));

    int val = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j] = ++val;
        }
    }
    int qSize = queries.size();
    for (int i = 0; i < qSize; ++i) {
        answer.push_back(rotate(queries[i]));
    }

    return answer;
}
```
