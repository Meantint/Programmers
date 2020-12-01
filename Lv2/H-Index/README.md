# 프로그래머스 - H-Index

&nbsp;`algorithm`의 `lower_bound()`와 `upper_bound`를 사용한 이분탐색으로 풀었다. 범위 때문에 넘 헷갈림 ㅠㅠ

- Programmers - [H-Index](https://programmers.co.kr/learn/courses/30/lessons/42747)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `mid` 값 이상인 첫 번째 원소의 인덱스를 저장하는 `findIdx_st`를 만들었다.

- `mid` 값을 초과하는 첫 번째 원소의 인덱스를 저장하는 `findIdx_ed`를 만들었다.

- `findIdx_ed <= mid` : `mid` 값 보다 작은 논문의 개수가 `mid` 이하인지 확인

- `citations.size() - findIdx_st >= mid` : `mid` 값 보다 큰 논문의 개수가 `mid` 이상인지 확인

- 바로 위의 두 조건을 만족하는 경우 `answer = max(answer, mid)`를 실행해준다(최대값을 구하는 문제이기 때문). 이후 `st = mid + 1`을 해준다.

- 위의 두 조건을 만족하지 못하는 경우 `ed = mid - 1`을 해준다.

- `mid = ((st + ed) >> 1)`로 바꿔준다.

- `st > ed`가 `true`가 될 때까지 while문을 반복한다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    int st = 0, ed = 10000, mid;
    mid = ((st + ed) >> 1);
    while (st <= ed) {
        int findIdx_st = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        int findIdx_ed = upper_bound(citations.begin(), citations.end(), mid) - citations.begin();
        // 조건을 만족하는 경우
        if (findIdx_ed <= mid && citations.size() - findIdx_st >= mid) {
            answer = max(answer, mid);

            // 더 위로 올려도 가능한지 확인 해야한다.
            st = mid + 1;
        }
        // 조건을 만족하지 못하면 더 아래로 내려가야한다.
        else {
            ed = mid - 1;
        }
        mid = ((st + ed) >> 1);
    }

    return answer;
}
```
