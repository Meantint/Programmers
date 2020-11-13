# 프로그래머스 - 체육복

&nbsp;for문을 순차적으로 탐색하면서 체육복이 2벌 있는 학생의 경우일 때만 차례대로 왼쪽, 오른쪽 학생이 체육복이 있는지 없는지 검사 한다. 없다면 체육복을 준다.

- Programmers - [체육복](https://programmers.co.kr/learn/courses/30/lessons/42862)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 기본적으로 `n`명의 학생 모두 1벌 씩 체육복을 가지고 있다고 생각한다.

- `lost`에 담겨 있는 학생들의 체육복 갯수를 `-1`한다.

- `reserve`에 담겨 있는 학생들의 체육복 갯수를 `+1`한다.

- 전체 탐색을 하면서 체육복을 2벌 가지고 있는 학생을 찾는다면

    1. 바로 왼쪽에 있는 학생이 체육복을 0벌 가지고 있다면 체육복 한 벌을 주고 다음 `index` 탐색을 한다.

    2. 바로 오른쪽에 있는 학생이 체육복을 0벌 가지고 있다면 체육복 한 벌을 주고 다음 `index` 탐색을 한다.

- for문 탐색이 끝난 후 체육복이 1벌 이상인 학생이 있을 때 마다 `++answer`를 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    vector<int> p(n, 1);

    for (auto& l : lost) {
        --p[l - 1];
    }
    for (auto& r : reserve) {
        ++p[r - 1];
    }
    for (int i = 0; i < n; ++i) {
        // 2벌 있을 때 다른 친구들에게 빌려줄 수 있다.
        if (p[i] == 2) {
            // 왼쪽부터 빌려줘야하는지 검사!
            if (i - 1 >= 0 && p[i - 1] == 0) {
                --p[i];
                ++p[i - 1];
            }
            // 왼쪽을 빌려주지 않아도 된다면 오른쪽 검사!
            else if (i + 1 < n && p[i + 1] == 0) {
                --p[i];
                ++p[i + 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] > 0) ++answer;
    }

    return answer;
}
```
