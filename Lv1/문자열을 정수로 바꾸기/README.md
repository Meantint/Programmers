# 프로그래머스 - 문자열을 정수로 바꾸기

&nbsp;`stoi()`를 이용하여 문자열을 정수로 바꿔주면 된다.

- Programmers - [문자열을 정수로 바꾸기](https://programmers.co.kr/learn/courses/30/lessons/12925)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `stoi(s)`를 하여 `answer`에 저장하면 된다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    answer = stoi(s);

    return answer;
}
```
