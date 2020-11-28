# 프로그래머스 - 프린터

&nbsp;`queue`를 이용하여 쉽게 풀 수 있다.

- Programmers - [프린터](https://programmers.co.kr/learn/courses/30/lessons/42587)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 기존 `priorities`의 순서대로 `q`에 넣어준다. `priorities`의 인덱스를 함께 넣어준다.

- 중요도를 검사하기 위해 `priorities`의 복사본 `copy`를 만들어준 후 내림차순 정렬해준다.

- `q.front()`의 중요도가 현재 최고 중요도와 같다면 `++answer` 해준다.

  - 작업의 인덱스도 우리가 찾는 `location`과 같다면 `break`를 해준다.

  - `location`과 다르다면 `q.pop()`으로 작업을 제거하고 `++cpIdx`를 해준다.

- `q.front()`의 중요도가 현재 최고 중요도와 다르다면 현재의 `q.front()`를 가장 뒤로 보내준 후 `q.pop()` 해준다.

## Code

```cpp
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    vector<int> copy = priorities;
    // 내림차순 정렬
    sort(copy.begin(), copy.end(), greater<int>());
    // copy 배열의 현재 인덱스를 저장하는 변수
    int cpIdx = 0;

    queue<PII> q;
    // (priority, location)
    for (auto& p : priorities) {
        q.push(make_pair(p, &p - &priorities[0]));
    }

    while (1) {
        // 현재의 가장 높은 중요도 값과 현재 탐색하고있는 q.front()의 중요도가 같다면
        if (q.front().first == copy[cpIdx]) {
            ++answer;
            // 이번에 인쇄하는 작업의 인덱스가 우리가 찾는 location이라면
            if (q.front().second == location) {
                break;
            }
            // location이 다르다면 현재 제일 앞에 있는 요청을 제거해준다.
            else {
                ++cpIdx;
                q.pop();
            }
        }
        // 중요도가 다르다면 제일 뒤로 넣어준다.
        else {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}
```
