# 프로그래머스 - 정수 제곱근 판별

&nbsp;`n`의 제곱근에서 소숫점을 버린 후 제곱을 한 수가 `n`과 같다면 어떤 정수 x의 제곱이다.

- Programmers - [정수 제곱근 판별](https://programmers.co.kr/learn/courses/30/lessons/12934)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n == pow((int)sqrt(n), 2)` 판별을 해준 후 참이라면 `answer = pow((int)sqrt(n) + 1, 2)`를 해주고 거짓이라면 `answer = -1`을 해준다.

## Code

```cpp
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    // n의 제곱근의 소숫점을 버린 후 제곱한 것이 기존의 n과 같다면 어떤 양의 정수 x의 제곱이다.
    if (n == pow((int)sqrt(n), 2)) {
        answer = pow((int)sqrt(n) + 1, 2);
    }
    // x의 제곱이 아니다.
    else {
        answer = (long long)-1;
    }

    return answer;
}
```
