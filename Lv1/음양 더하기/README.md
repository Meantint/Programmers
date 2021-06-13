# 프로그래머스 - 음양 더하기

&nbsp;잘 더하자

- Programmers - [음양 더하기](https://programmers.co.kr/learn/courses/30/lessons/76501)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 절대값 `absolutes[i]`를 받아온 후 `signs[i] = false`인 경우에만 `-1`을 곱해줘서 `answer += num` 명령을 실행해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int answer = 0;
    int size = absolutes.size();

    for (int i = 0; i < size; ++i) {
        int num = absolutes[i];

        if (!signs[i]) {
            num *= -1;
        }

        answer += num;
    }

    return answer;
}
```
