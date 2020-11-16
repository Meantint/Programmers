# 프로그래머스 - 제일 작은 수 제거하기

&nbsp;

- Programmers - [제일 작은 수 제거하기](https://programmers.co.kr/learn/courses/30/lessons/12935)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- for문 탐색을 하면서 가장 작은 값을 가지고 있는 인덱스 `savIdx`를 찾는다.

- `arr[savIdx]`를 제외한 나머지 인덱스 위치의 값들을 `answer`에 추가한다.

- `answer.empty()`라면 `-1`을 `answer`에 넣어준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int minVal = arr[0];
    int savIdx = 0;  // 최솟값의 인덱스를 저장하고 있는 변수
    for (auto& a : arr) {
        // 현재 탐색한 값이 이때까지의 최솟값 보다 작을 때
        if (a < minVal) {
            minVal = a;
            savIdx = &a - &arr[0];
        }
    }
    for (auto& a : arr) {
        // min 값을 저장한 인덱스가 아니라면 answer에 원소를 추가한다.
        if (&a - &arr[0] != savIdx) {
            answer.push_back(a);
        }
    }
    // 작업을 완료했는데 answer가 비어있으면 -1을 넣어준다.
    if (answer.empty()) answer.push_back(-1);

    return answer;
}
```
