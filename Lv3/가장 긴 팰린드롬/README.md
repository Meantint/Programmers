# 프로그래머스 - 가장 긴 팰린드롬

&nbsp;2차원 배열을 이용한 완전탐색을 구현했다.

- Programmers - [가장 긴 팰린드롬](https://programmers.co.kr/learn/courses/30/lessons/12904)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `vector<vector<bool>>` 변수 `dp`를 생성

  - `dp[from][to]` : `from`에서 `to`까지의 부분 문자열이 팰린드롬이라면 `true`, 아니라면 `false`

  - `dp[i][i]`는 무조건 팰린드롬이므로 `true`

  - `s[i] = s[i + 1]`이라면 `dp[i][i + 1]`는 무조건 팰린드롬이므로 `true`

- `k = 2`부터 1씩 증가시켜주면서 `i` ~ `i + k`의 값을 완전탐색으로 채워준다.

  - `s[i] = s[i + k]`이고 `dp[i + 1][i + k - 1] = true`라면 `dp[i][i + k] = true`이다.

  - `dp[i][i + k] = true`인 경우 `ret`의 값을 갱신해준다.

    - `ret`의 대소 비교를 하지 않는 이유 : `k`가 오름차순 증가하기 때문에 해줄 필요 없음

  - 나머지의 경우는 `dp[i][i + k] = false`이다.

- 최대 팰린드롬의 길이가 저장되어 있는 `ret`의 값을 리턴해준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> dp;

int solve(string s)
{
    int ret = 1;    // 최소 팰린드롬의 크기 1
    int sSize = s.size();
    dp = vector<vector<bool>>(sSize, vector<bool>(sSize, false));

    for (int i = 0; i < sSize; ++i) {
        dp[i][i] = true;
    }
    --sSize;  // 범위 초과 방지
    for (int i = 0; i < sSize; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    ++sSize;  // 복구

    for (int k = 2; k < sSize; ++k) {
        int kRange = sSize - k;

        for (int i = 0; i < kRange; ++i) {
            if (s[i] == s[i + k]) {
                dp[i][i + k] = dp[i + 1][i + k - 1];
                if (dp[i][i + k]) {
                    ret = k + 1;
                }
            }
            else {
                dp[i][i + k] = false;
            }
        }
    }

    return ret;
}

int solution(string s)
{
    return solve(s);
}
```
