# 프로그래머스 - 같은 숫자는 싫어

&nbsp;정렬하지 않은 상태로 `erase()`와 `unique()`를 같이 사용하면 한번에 해결된다!

- Programmers - [같은 숫자는 싫어](https://programmers.co.kr/learn/courses/30/lessons/12906)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `arr.erase(unique(arr.begin(), arr.end()), arr.end())`로 같은 값이 여러 개 붙어있다면 한 개로 압축시켜준다(사실 압축의 개념은 아님).

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    answer = arr;

    return answer;
}
```
