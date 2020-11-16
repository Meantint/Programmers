# 프로그래머스 - 약수의 합

&nbsp;프로그래머스에서 제일 쉽게 푼 문제 같다.

- Programmers - [약수의 합](https://programmers.co.kr/learn/courses/30/lessons/12928)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 약수라면 `answer += i` 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        // n이 i로 나누어 떨어진다면
        if (n % i == 0) {
            answer += i;
        }
    }

    return answer;
}
```
