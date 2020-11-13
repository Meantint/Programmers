# 프로그래머스 - 모의고사

&nbsp;1, 2, 3번 수포자의 패턴을 저장하는 배열 `p1`, `p2`, `p3`를 만들어 해결하였다.

- Programmers - [모의고사](https://programmers.co.kr/learn/courses/30/lessons/42840)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 1, 2, 3번 수포자의 패턴을 저장하는 배열 `p1`, `p2`, `p3`를 만든다.

- 1, 2, 3번 수포자의 맞은 문제 개수를 저장하는 변수 `c1`, `c2`, `c3`를 만든다.

- `vector<pii> check`를 만들어 맞은 개수 순으로 내림차순 정렬한다.

- 1위(or 1위들의) 번호를 `answer`에 저장한 후, `answer`를 오름차순 정렬한다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

#define pii pair<int, int>

using namespace std;

int p1[5] = {1, 2, 3, 4, 5};
int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int c1 = 0, c2 = 0, c3 = 0;
    int aSize = answers.size();
    for (int i = 0; i < aSize; ++i) {
        if (answers[i] == p1[i % 5]) ++c1;
        if (answers[i] == p2[i % 8]) ++c2;
        if (answers[i] == p3[i % 10]) ++c3;
    }
    vector<pii> check = {make_pair(c1, 1), make_pair(c2, 2), make_pair(c3, 3)};

    sort(check.begin(), check.end(), greater<pii>());

    // 가장 많이 맞은 사람의 index = 0이기 때문에 answer에 넣어준다.
    answer.push_back(check[0].second);
    // 두 번째 많이 맞은 사람의 정답 수가 첫 번째 사람이랑 같다면 answer에 넣어준다.
    if (check[0].first == check[1].first) {
        answer.push_back(check[1].second);
        // 세 번째 많이 맞은 사람의 정답 수가 두 번째 사람이랑 같다면 answer에 넣어준다.
        if (check[1].first == check[2].first) {
            answer.push_back(check[2].second);
        }
    }
    // 여러 개 들어간 경우를 대비해 오름차순으로 정렬한다.
    sort(answer.begin(), answer.end());

    return answer;
}
```
