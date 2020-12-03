# 프로그래머스 - 구명보트

&nbsp;오름차순 정렬해서 양쪽 끝 부분에서 안쪽으로 탐색하는 투포인터를 썼다.

- Programmers - [구명보트](https://programmers.co.kr/learn/courses/30/lessons/60058)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 몸무게 순으로 오름차순 한다.

- `people[st] + people[ed]`가 `limit` 보다 크다면 태울 수 없다. 그리고 `st`는 항상 몸무게가 커지는 방향으로 이동하기 떄문에 `people[ed]`와 함께 탈 수 있는 사람이 없다고 볼 수 있으므로 `people[ed]`만 태운다.

- `people[st] + people[ed]`가 `limit`과 같거나 더 작다면 둘 다 태워준다.

- `while`문이 끝나고 `st`와 `ed`의 값이 같은 경우 아직 `people[st(=ed)]`를 태우지 않았으므로 `++answer` 해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());
    int st = 0, ed = people.size() - 1;
    while (st <= ed) {
        // 두 명 못태우면 몸무게 큰 사람만 태운다
        if (people[st] + people[ed] > limit) {
            ++answer;
            --ed;
        }
        // 둘 다 태울수 있으면 태운다
        else {
            ++answer;
            ++st;
            --ed;
        }
    }
    if (st == ed) {
        ++answer;
    }

    return answer;
}
```
