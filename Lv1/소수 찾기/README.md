# 프로그래머스 - 소수 찾기

&nbsp;에라토스테네스의 체를 이용하여 푼다.

- Programmers - [소수 찾기](https://programmers.co.kr/learn/courses/30/lessons/12921)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `prime[i]` : `i`가 소수라면 `true`, 소수가 아니라면 `false`를 저장

- 에라토스테네스의 체를 이용하여 `prime` 원소들의 값을 바꿔준다.

- 에라토스테네스의 체를 완료한 후 `2 ~ n` 범위의 소수 개수를 세어준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<bool> prime;

int solution(int n)
{
    int answer = 0;

    prime = vector<bool>(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        // i가 소수가 아니라면 다음 숫자로 넘어간다.
        if (!prime[i]) continue;
        // i를 제외한 i의 배수들을 모두 false로 바꿔준다.
        for (int j = i * 2; j <= n; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        // prime[i] = true라면 카운트를 올려준다.
        if (prime[i]) ++answer;
    }

    return answer;
}
```
