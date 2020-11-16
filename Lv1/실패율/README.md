# 프로그래머스 - 실패율

&nbsp;정렬 커스텀에서 `stages`가 최대 20만까지 가능하므로 범위를 초과할 수 있으므로 `long long` 타입으로 변환해서 비교해준다.

- Programmers - [실패율](https://programmers.co.kr/learn/courses/30/lessons/42889)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `stages[i]` 값을 받아서 `++fail[stages[i] - 1]`을 해준다.

- `stages[i] - 1`까지의 모든 `arrive` 인덱스들의 값을 1증가 해준다.

- `fail`, `arrive`, `i + 1`의 값을 저장하는 `vector<tuple<int, int, int>> all(N)`을 만든다.

- 대소 비교에서 `get<0>(t1) * get<1>(t2)` > `get<0>(t2) * get<1>(t1)`가 내림차순의 역할을 해준다.

- `get<0>(t1) * get<1>(t2)` == `get<0>(t2) * get<1>(t1)`라면 인덱스 순으로 오름차순 정렬한다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool comp(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2)
{
    long long n1 = (long long)get<0>(t1) * (long long)get<1>(t2);
    long long n2 = (long long)get<0>(t2) * (long long)get<1>(t1);
    if (n1 == n2) {
        return get<2>(t1) < get<2>(t2);
    }
    return n1 > n2;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<int> fail(N + 1, 0);
    vector<int> arrive(N + 1, 0);
    for (auto& stage : stages) {
        ++fail[stage - 1];
        for (int i = 0; i < stage; ++i) {
            ++arrive[i];
        }
    }
    // (fail, arrive, idx)
    vector<tuple<int, int, int>> all(N);
    for (int i = 0; i < N; ++i) {
        all[i] = make_tuple(fail[i], arrive[i], i + 1);
    }
    sort(all.begin(), all.end(), comp);
    for (auto& a : all) {
        answer.push_back(get<2>(a));
    }

    return answer;
}
```
