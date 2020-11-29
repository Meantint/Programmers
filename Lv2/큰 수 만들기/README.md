# 프로그래머스 - 큰 수 만들기

&nbsp;`Greedy`를 이용하여 풀었다.

- Programmers - [큰 수 만들기](https://programmers.co.kr/learn/courses/30/lessons/42883)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 앞이 큰 경우가 큰 수를 만들 수 있는 경우이다(뒤를 여러개 바꿔도 앞만 큰걸로 바뀌면 의미 없음).

- 첫 번째 while문이 끝나고 `idx`가 `number.size()` 보다 작다면 `idx`가 `number.size()`가 될 때까지 `answer.push_back()` 해준다.

- 두 번째 while문이 끝나고 `k`가 `0`이 아니라면 `answer` 뒤의 값부터 제거해준다(`k`가 `0`이 될 때까지).

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

void find_idx(string str, int& start, int& k)
{
    int maxIdx = start;
    for (int i = 0; i <= k; ++i) {
        if (start + i >= str.size()) {
            break;
        }
        if (str[start + i] > str[maxIdx]) {
            maxIdx = start + i;
        }
    }
    k -= maxIdx - start;
    start = maxIdx;

    return;
}

string solution(string number, int k)
{
    int idx = 0;
    string answer = "";

    // k가 0이 될 때까지 혹은 idx >= number.size()가 될 때까지 while문 실행
    while (k != 0 && idx < number.size()) {
        find_idx(number, idx, k);
        answer += number[idx];
        ++idx;
    }
    // 남은 뒤의 숫자들을 붙여준다.
    while (idx < number.size()) {
        answer += number[idx];
        ++idx;
    }
    // k가 남아있다면 뒤에서부터 지워준다.
    while (k != 0) {
        answer.pop_back();
        --k;
    }

    return answer;
}
```
