# 프로그래머스 - 징검다리

&nbsp;이분탐색 문제. 자꾸 같은 테스트케이스가 틀려서 머리를 한참 굴리다 결국에 인터넷 찬스를 썼는데 기본적인 코드 개념이 나랑 똑같았다(내가 훨씬 멀리 돌아가서 푼 느낌). 기회가 되면 한 번 코드를 보고 왜 내 코드는 안되는지 확인해보려고 한다.

- Programmers - [징검다리](https://programmers.co.kr/learn/courses/30/lessons/43236)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 돌과 돌사이의 거리를 저장하는 `vector<int>` 변수 `dist`를 만들었고 `dist`의 개수는 항상 `rocks.size() + 1`이다.

- 이분탐색을 해서 정답을 도출해내는 함수 `BinarySearch`를 만들었다.

- 이 문제에서 이분탐색으로 하고자 하는 것은 돌과 돌사이의 거리가 `mid`보다 작을 경우 바로 옆에 있는 돌의 길이와 합쳐주는 것이다(길이를 합쳐준다는 것은 합쳤을 때 겹치는 부분에 있는 돌 하나를 제거한다는 의미이기도 하다).

- 특정 위치에서 현재 탐색하는 위치까지의 길이를 저장해놓는 `sum`을 만들고 현재 `sum`의 크기가 걸어 놓은 기준 `mid`보다 작은 길이라면 다음 길이를 더해줘야하고 이 동작은 돌을 하나 제거하는 것과 똑같은 것이기 때문에 `++ret`을 해준다. 만약 `sum`의 크기가 `mid`보다 크거나 `mid`와 같은 경우에는 돌을 더 제거할 필요가 없기 때문에 `sum`을 `0`으로 초기화 하여 다시 과정을 반복해준다.

- `ret > n`이라면(돌을 제거한 개수가 `n`보다 많다면) 통과시키는 돌 사이의 거리를 완화해줘야 `ret`의 개수가 줄어들기 때문에 `high = mid - 1`을 해준다.

- `ret <= n`이라면(돌을 제거한 개수가 `n`이하라면) 돌 사이의 거리를 늘려줘야 `ret`의 개수가 늘어나기 때문에 `low = mid + 1`을 해준다.

  - `ret == n`일 때도 `low`의 크기를 늘려주는 이유는 이미 현재의 `mid` 값이 `answer`에 들어가있다고 생각할 수 있고 `mid` 값이 더 작아지는 경우는 `answer`의 변화에 아무런 영향을 끼치지 못하기 때문에 할 필요가 없다. 하지만 `mid` 값이 커지는 경우, 그리고 `ret == n`이 된다면 `answer`의 값은 바뀔 수 있기 때문에 합치는 기준을 더 크게 만들어줘야한다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> dist;

int answer = 0;

void BinarySearch(int n)
{
    int low = 1, high = 1000000000;
    int mid = (low + high) / 2;

    while (low <= high) {
        int ret = 0;
        vector<int> temp;

        int sum = 0;

        for (auto d : dist) {
            sum += d;
            if (sum < mid) {
                ++ret;
            }
            else {
                sum = 0;
            }
        }

        if (ret > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    answer = mid;
}

void solve(int distance, vector<int> rocks, int n)
{
    answer = 0;

    sort(rocks.begin(), rocks.end());

    dist.push_back(rocks[0]);
    int rSize = rocks.size();
    for (int i = 1; i < rSize; ++i) {
        dist.push_back(rocks[i] - rocks[i - 1]);
    }
    dist.push_back(distance - rocks.back());

    BinarySearch(n);
}

int solution(int distance, vector<int> rocks, int n)
{
    solve(distance, rocks, n);

    return answer;
}
```
