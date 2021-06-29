# 프로그래머스 - 거스름돈

&nbsp;DP 문제. 지금 생각해보니 정렬할 필요는 없을 것 같다.

- Programmers - [거스름돈](https://programmers.co.kr/learn/courses/30/lessons/12907)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `vector<int>` 변수 `dp`를 만들고 `dp[0] = 1`, 나머지는 `0`으로 초기화 해줬는데 `dp[0] = 1`을 해준 이유는 시작점이고, 시작점은 아무 것도 놓지 않아도 되는 단 하나의 경우가 있다고 생각했다(그런 것도 있고 기본적인 연산 자체가 편리함).

- 바깥 for문이 `money`의 인덱스를 참조하고 안쪽 for문이 `0 ~ (n - 1)`까지 탐색하는 2중 for문을 만들고 `dp[i]`의 값이 `0`이 아니고 현재의 값에 `money[k]`를 더했을 때 `n` 이하의 값을 가진다면 점화식 과정을 수행해준다.

- 정답은 `dp[n]`에 저장되어 있다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n, vector<int> money)
{
    int mSize = money.size();
    for (int k = 0; k < mSize; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dp[i] != 0 && i + money[k] <= n) {
                dp[i + money[k]] += dp[i];
                dp[i + money[k]] %= 1000000007;
            }
        }
    }

    return dp[n];
}

int solution(int n, vector<int> money)
{
    dp.resize(n + 1, 0);
    dp[0] = 1;
    sort(money.begin(), money.end(), greater<>());

    return solve(n, money);
}
```
