# 프로그래머스 - 올바른 괄호

&nbsp;

- Programmers - [올바른 괄호](https://programmers.co.kr/learn/courses/30/lessons/12909)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `)`의 개수가 더 많으면 안되기 때문에 `bal`이 음수가 되면 `answer = false`를 해준다.

- `for`문이 끝났을 때 `bal`의 값이 `0`이 아니라면 괄호 개수의 밸런스가 맞지 않기 때문에 `answer = false`를 해준다.

## Code

```cpp
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int bal = 0;
    for (auto& elem : s) {
        if (elem == '(') {
            ++bal;
        }
        // elem == ')'
        else {
            --bal;
        }
        // bal이 음수로 내려간 적이 있다면 올바른 괄호가 될 수 없다.
        if (bal < 0) {
            answer = false;
            break;
        }
    }
    // 좌우 괄호의 개수가 맞지 않으면 올바른 괄호가 될 수 없다.
    if (bal != 0) {
        answer = false;
    }

    return answer;
}
```
