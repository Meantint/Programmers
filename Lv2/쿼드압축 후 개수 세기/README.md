# 프로그래머스 - 쿼드압축 후 개수 세기

&nbsp;분할정복을 이용해 풀었다.

- Programmers - [쿼드압축 후 개수 세기](https://programmers.co.kr/learn/courses/30/lessons/68936)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `solve()` 함수에서 범위 내의 모든 값이 `0`인 경우 `++cnt_0`을 해주고 모든 값이 `1`인 경우 `++cnt_1`을 해준다.

- `solve()` 함수에서 범위 내의 값이 `0`과 `1`이 섞여 있을 경우 `4`개로 분할해서 다시 탐색해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int cnt_0 = 0, cnt_1 = 0;
vector<vector<int>> global_arr;

void solve(int x, int y, int size)
{
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (global_arr[x + i][y + j] == 1) {
                ++cnt;
            }
        }
    }
    // 범위 내의 원소들의 값이 모두 1이라면
    if (cnt == size * size) {
        ++cnt_1;
    }
    // 범위 내의 원소들의 값이 모두 0이라면
    else if (cnt == 0) {
        ++cnt_0;
    }
    // 수가 섞여있다면
    else {
        int half = size / 2;
        solve(x, y, half);
        solve(x, y + half, half);
        solve(x + half, y, half);
        solve(x + half, y + half, half);
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    global_arr = arr;
    solve(0, 0, arr.size());

    answer.push_back(cnt_0);
    answer.push_back(cnt_1);

    return answer;
}
```
