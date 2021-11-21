# 프로그래머스 - 나머지가 1이 되는 수 찾기

&nbsp;

## 문제/코드 링크

- [프로그래머스 - 나머지가 1이 되는 수 찾기](https://programmers.co.kr/learn/courses/30/lessons/87389)

- [My Programmers Repo](https://github.com/Meantint/Programmers)

## 풀이

- `1` ~ `n - 1` 순서대로 나눠보면서 나머지가 1인 경우 그 값을 `answer`에 저장하고 `break` 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 1; i < n; ++i) {
        if (n % i == 1) {
            answer = i;
            break;
        }
    }

    return answer;
}
```
