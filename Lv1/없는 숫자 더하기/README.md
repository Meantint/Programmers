# 프로그래머스 - 없는 숫자 더하기

&nbsp;

## 문제/코드 링크

- [프로그래머스 - 없는 숫자 더하기](https://programmers.co.kr/learn/courses/30/lessons/86051)

- [My Programmers Repo](https://github.com/Meantint/Programmers)

## 풀이

- 0~9까지의 합인 `45`를 기본값으로 두고 `numbers` 배열 안에 있는 모든 수를 빼주면 없는 숫자들의 합과 같다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 45;

    int size = numbers.size();
    for (int i = 0; i < size; ++i) {
        answer -= numbers[i];
    }

    return answer;
}
```
