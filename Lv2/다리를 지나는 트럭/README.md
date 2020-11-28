# 프로그래머스 - 다리를 지나는 트럭

&nbsp;`queue`를 이용해서 풀면된다.

- Programmers - [다리를 지나는 트럭](https://programmers.co.kr/learn/courses/30/lessons/42583)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 다리의 길이 만큼 `queue<int>` 타입 변수 `q`에 `0`을 넣어준다.

- `q.front()`가 빠지고 다음 트럭이 들어왔을 때의 무게가 한도를 넘지 않는다면 다음 트럭을 `q.push()` 해준 후 `q.pop()`을 해준다.

- 위의 조건을 따르고 무게가 한도를 넘는 경우에는 `q.pop()`을 해준 후 트럭이 들어오지 않는다는 의미인 `0`을 `q.push()` 해준다.

- while문을 한 번 돌 때마다 `++answer`를 해준다.

- while문을 벗어날 때 마지막 트럭이 다리의 시작 부분에 있으므로 다리의 길이 `bridge_length`를 `answer`에 더해주어야 한다.

## Code

```cpp
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int bridgeWeight = 0;
    int tSize = truck_weights.size();

    queue<int> q;
    for (int i = 0; i < bridge_length; ++i) {
        q.push(0);
    }
    int idx = 0;
    while (idx < tSize) {
        // 젤 앞의 무게가 빠지고 다음 트럭이 들어왔을 때의 무게가 weight 보다 작다면
        if (bridgeWeight - q.front() + truck_weights[idx] <= weight) {
            bridgeWeight -= q.front();
            bridgeWeight += truck_weights[idx];
            q.push(truck_weights[idx]);
            q.pop();
            ++idx;
        }
        else {
            q.push(0);
            bridgeWeight -= q.front();
            q.pop();
        }
        ++answer;
    }
    // while문을 빠져나왔을 때 상황 : 마지막 트럭이 다리의 시작 부분에 위치해있음
    answer += bridge_length;

    return answer;
}
```
