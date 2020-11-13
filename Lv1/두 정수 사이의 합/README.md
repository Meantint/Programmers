# 프로그래머스 - 두 정수 사이의 합

&nbsp;진짜 쉽다!

- Programmers - [두 정수 사이의 합](https://programmers.co.kr/learn/courses/30/lessons/12912)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `a > b`라면 `a`와 `b`의 값을 바꿔준다.

- for문을 통해 `a ~ b`의 범위를 `answer`에 하나씩 모두 더해준다(최대 `20,000,000` 연산).

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;

    if (a > b) swap(a, b);
    for (long long i = a; i < b; ++i) {
        answer += i;
    }
    answer += b;

    return answer;
}
```
