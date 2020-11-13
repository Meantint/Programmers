# 프로그래머스 - 문자열 다루기 기본

&nbsp;문제에서 요구하는 것을 잘 구현하면 된다.

- Programmers - [문자열 다루기 기본](https://programmers.co.kr/learn/courses/30/lessons/12918)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `s.size() != 4 && s.size() != 6`이면 `answer = false`

- `s`의 문자들 중 하나라도 `c < '0' || c > '9'`라면 `answer = false`

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if (s.size() == 4 || s.size() == 6) {
        for (auto &c : s) {
            if (c < '0' || c > '9') {
                answer = false;
                break;
            }
        }
    }
    else {
        answer = false;
    }

    return answer;
}
```
