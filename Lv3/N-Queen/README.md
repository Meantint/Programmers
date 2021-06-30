# 프로그래머스 - N-Queen

&nbsp;백트래킹을 이용해서 풀었다.

- Programmers - [N-Queen](https://programmers.co.kr/learn/courses/30/lessons/12952)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `i`번째 행에 있는 퀸의 열(column) 위치를 저장해놓은 `vector<int>` 변수 `row`와 `i`번째 열에 이미 퀸이 있는지의 여부를 담아두는 `vector<bool>` 변수 `col`을 선언했다.

- 백트래킹을 해준다.

  - 세로(row)가 겹치는지의 여부는 `dfs` 함수 자체에서 배제가 되기 때문에 신경 쓸 필요가 없다.

  - 이전의 모든 퀸과 대각선에서 만나는지의 여부를 검사해준다.

  - 가로의 경우 현재 행의 열(column) 인덱스의 위치에 이미 퀸이 있는지 `col` 배열을 통해서 확인해주면 된다.

- `r = global_n`인 경우 체스판 전체에 `n`개의 퀸을 배치한 것이기 때문에 `++answer`를 해준다.

- `solve` 함수 안에 있는 for문이 끝나고 들어가있는 `answer`의 값이 정답이다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<bool> col;
vector<int> row;
int answer, global_n;

void dfs(int r)
{
    if (r == global_n) {
        ++answer;
        return;
    }

    for (int i = 0; i < global_n; ++i) {
        bool isPos = true;

        for (int j = 0; j < r; ++j) {
            int y = j - r;
            int x = row[j] - i;

            if (y - x == 0 || y + x == 0) {
                isPos = false;

                break;
            }
        }

        if (!col[i] && isPos) {
            col[i] = true;
            row[r] = i;
            dfs(r + 1);
            row[r] = -1;
            col[i] = false;
        }
    }
}

void solve()
{
    answer = 0;
    for (int i = 0; i < global_n; ++i) {
        col[i] = true;
        row[0] = i;
        dfs(1);
        row[0] = -1;
        col[i] = false;
    }
}

int solution(int n)
{
    global_n = n;
    col.resize(n, false);
    row.resize(n, -1);

    solve();

    return answer;
}
```
