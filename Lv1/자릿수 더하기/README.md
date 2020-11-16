# 프로그래머스 - 자릿수 더하기

&nbsp;쉬웠다.

- Programmers - [자릿수 더하기](https://programmers.co.kr/learn/courses/30/lessons/12931)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n == 0`이 될 때까지 `answer`에 더해준다.

## Code

```cpp
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n != 0) {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}
```
