# 프로그래머스 - x만큼 간격이 있는 n개의 숫자

&nbsp;

- Programmers - [x만큼 간격이 있는 n개의 숫자](https://programmers.co.kr/learn/courses/30/lessons/12954)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `long long` 변수 `cx`를 생성한다.

- `answer.push_back(cx)`를 실행한 후 `cx += (long long)x`를 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;

    long long cx = x;  // 계속 x만큼 더해줄 변수 생성
    for (int i = 0; i < n; ++i) {
        answer.push_back(cx);
        cx += (long long)x;
    }

    return answer;
}
```
