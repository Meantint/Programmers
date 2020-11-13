# 프로그래머스 - 나누어 떨어지는 숫자 배열

&nbsp;쉽다!

- Programmers - [나누어 떨어지는 숫자 배열](https://programmers.co.kr/learn/courses/30/lessons/12910)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `arr` 원소들 중 `divisor`로 나누어 떨어지는 수가 있다면 `answer`에 넣어준다.

- for문을 종료했을 때 `answer.empty() == true`라면 `-1`을 넣어준다.

- `answer`를 오름차순 정렬 해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (auto &a : arr) {
        if (a % divisor == 0) answer.push_back(a);
    }
    if (answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());

    return answer;
}
```
