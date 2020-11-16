# 프로그래머스 - 자연수 뒤집어 배열로 만들기

&nbsp;`reverse` 할 필요 없다(숫자의 뒤부터 `answer`의 앞 원소로 들어가기 때문에).

- Programmers - [자연수 뒤집어 배열로 만들기](https://programmers.co.kr/learn/courses/30/lessons/12932)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n == 0`이 될 때까지 `answer`에 `push_back` 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
    vector<int> answer;

    while (n != 0) {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}
```
