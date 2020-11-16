# 프로그래머스 - 하샤드 수

&nbsp;매개변수로 들어온 `x`를 `while`문으로 녹여버리면 이후에 나누는 연산을 할 수 없으므로 `x` 값을 저장하는 변수인 `cx`를 만들었다.

- Programmers - [하샤드 수](https://programmers.co.kr/learn/courses/30/lessons/12947)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `x`의 초기값을 저장하는 `cx`를 만들었다.

- `x`의 각 자리수의 합을 저장하는 `sum`을 만들었다.

- `answer = (x % sum == 0) ? answer = true : answer = false`을 실행한다.

  - `x % sum == 0`이면 `true`를, `x % sum != 0`이라면 `false`를 `answer`에 저장한다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;

    int cx = x;
    int sum = 0;
    while (cx != 0) {
        sum += cx % 10;
        cx /= 10;
    }
    answer = (x % sum == 0) ? answer = true : answer = false;

    return answer;
}
```
