# 프로그래머스 - 문자열 내 p와 y의 개수

&nbsp;문자열 내의 문자를 하나하나 탐색하면서 개수를 세어주면 된다.

- Programmers - [문자열 내 p와 y의 개수](https://programmers.co.kr/learn/courses/30/lessons/12916)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 문자 변수 `c`가 `p`이거나 `P`인 경우 `++cnt` 해준다.

- 문자 변수 `c`가 `y`이거나 `Y`인 경우 `--cnt` 해준다.

- `cnt != 0`이라면 개수가 일치하지 않는 것이므로 `answer = false`를 해준다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt = 0;
    // (p or P)를 만나면 ++cnt, (y or Y)를 만나면 --cnt 해준다.
    for (auto &c : s) {
        if (c == 'p' || c == 'P') ++cnt;
        else if (c == 'y' || c == 'Y')
            --cnt;
    }
    // 개수의 균형이 맞지 않는다면 answer를 false로 바꿔준다.
    if (cnt != 0) answer = false;

    return answer;
}
```
