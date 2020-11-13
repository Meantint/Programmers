# 프로그래머스 - 내적

&nbsp;최대 범위도 `int` 범위 내이므로 시키는 대로 하자.

- Programmers - [내적](https://programmers.co.kr/learn/courses/30/lessons/70128)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `answer += a[i] * b[i]`를 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 0;

    int size = a.size();
    for (int i = 0; i < size; ++i) {
        answer += a[i] * b[i];
    }

    return answer;
}
```
