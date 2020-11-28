# 프로그래머스 - 124 나라의 숫자

&nbsp;규칙을 잘 찾아야 한다..!

- Programmers - [124 나라의 숫자](https://programmers.co.kr/learn/courses/30/lessons/12899)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 3으로 나누어 떨어지는 경우에는 `answer`의 앞에 `4`를 붙여준 후 `n`을 나누기 전 `3`을 빼줘야 한다.

- 3으로 나누어 떨어지지 않는 경우에는 나머지 값 `n % 3`을 `answer`의 앞에 붙인 후 `n /= 3`을 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    while (n != 0) {
        // 3으로 나누어 떨어진다면
        if (n % 3 == 0) {
            answer = '4' + answer;
            n -= 3;
            n /= 3;
        }
        else {
            answer = to_string(n % 3) + answer;
            n /= 3;
        }
    }

    return answer;
}
```
