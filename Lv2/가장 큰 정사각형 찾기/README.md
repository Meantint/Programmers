# 프로그래머스 - 가장 큰 정사각형 찾기

&nbsp;

- Programmers - [가장 큰 정사각형 찾기](https://programmers.co.kr/learn/courses/30/lessons/42746)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `board[i][j]` : `board[i - 1][j]`, `board[i][j - 1]`, `board[i - 1][j - 1]`의 값들 중 가장 작은 값 + 1

- `answer`를 매번 갱신해준다.

- `answer`에는 가장 큰 정사각형의 한 변의 길이가 들어가있으므로 `return answer * answer`를 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            // 범위를 벗어나는 경우
            if (i - 1 == -1 || j - 1 == -1) {
                continue;
            }
            // 0인 경우도 볼 필요 없음
            if (board[i][j] == 0) {
                continue;
            }
            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
            if (answer < board[i][j]) {
                answer = board[i][j];
            }
        }
    }

    return answer * answer;
}
```
