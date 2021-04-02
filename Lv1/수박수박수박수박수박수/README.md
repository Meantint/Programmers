# 프로그래머스 - 수박수박수박수박수박수?

&nbsp;한글은 유니코드라 바이트가 더 많이 필요하다. 그래서 char로 하면 `error: character too large for enclosing character literal type` 오류가 뜬다.


- Programmers - [수박수박수박수박수박수?](https://programmers.co.kr/learn/courses/30/lessons/12922)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `i % 2 == 0`이라면 `answer += "수"`를 해준다.

- `i % 2 == 1`이라면 `answer += "박"`을 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    for (int i = 0; i < n; ++i) {
        // 짝수라면 '수'
        if (i % 2 == 0) {
            answer += "수";
        }
        // 홀수라면 '박'
        else {
            answer += "박";
        }
    }

    return answer;
}
```
