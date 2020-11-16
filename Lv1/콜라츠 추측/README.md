# 프로그래머스 - 콜라츠 추측

&nbsp;시키는대로 구현하면 되는데 `int` 범위를 넘어가 버리는 경우가 있으므로 값을 `long long` 타입에 옮겨서 풀었다.

- Programmers - [콜라츠 추측](https://programmers.co.kr/learn/courses/30/lessons/12943)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `int` 범위를 넘어갈 수 있으므로 `long long` 타입 `n`에 옮겨서 풀었다.

- `cnt == 500`이 됐다면(500번 시도) `break`를 실행한다.

- `answer != -1`이라면(500번 시도를 안했다면) 시도 횟수 `cnt`를 `answer`에 넣어준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
long long n;

int solution(int num)
{
    int answer = 0;

    n = (long long)num;
    while (n != 1) {
        if (cnt == 500) {
            answer = -1;
            break;
        }
        ++cnt;
        (n % 2 == 0) ? n /= 2 : n = (n * 3 + 1);
    }
    // 만약 cnt가 500을 넘어 answer가 -1이 된 것이 아니라면
    if (answer != -1) {
        answer = cnt;
    }

    return answer;
}
```
