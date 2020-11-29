# 프로그래머스 - 더 맵게

&nbsp;`queue`의 `priority_queue`를 이용해서 풀면된다.

- Programmers - [더 맵게](https://programmers.co.kr/learn/courses/30/lessons/42626)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `priority_queue`를 이용하여 푼다.

- `scoville`의 모든 값을 `pq`에 넣는다.

- `pq.top()`이 `K` 보다 작다면 가장 작은 두 개의 값 `s1`, `s2`를 꺼내서(`s1 < s2`) `pq.push(s1 + s2 * 2)` 해준다.

- `pq.size()`가 `1`이 될 때까지 했는데도 `pq.top()`이 `K` 보다 작다면 `answer = -1`을 해준다.

## Code

```cpp
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& s : scoville) {
        pq.push(s);
    }
    while (pq.size() > 1 && pq.top() < K) {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();

        pq.push(s1 + s2 * 2);
        ++answer;
    }
    if (pq.size() == 1 && pq.top() < K) {
        answer = -1;
    }

    return answer;
}
```
