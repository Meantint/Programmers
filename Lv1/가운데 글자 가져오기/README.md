# 프로그래머스 - 가운데 글자 가져오기

&nbsp;

- Programmers - [가운데 글자 가져오기](https://programmers.co.kr/learn/courses/30/lessons/12903)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `s.size()`가 홀수라면 `s`의 가운데 문자인 `s[s.size() / 2]`를 `answer`에 저장한다.

- `s.size()`가 짝수라면 `s`의 가운데 두 문자인 `s[s.size() / 2 - 1]`과 `s[s.size() / 2]`를 `answer`에 저장한다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    // 홀수
    if (s.size() % 2 == 1) {
        answer += s[s.size() / 2];
    }
    // 짝수
    else {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }

    return answer;
}
```
