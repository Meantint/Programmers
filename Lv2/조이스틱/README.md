# 프로그래머스 - 조이스틱

&nbsp;머릿속에서 정리가 잘 안되는 문제. 이해는 가는데 구현을 하기 너무 귀찮고 어려운..그런 문제

- Programmers - [조이스틱](https://programmers.co.kr/learn/courses/30/lessons/42860)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `A`가 여러개 이어져있는 경우 순차 이동하는 것 보다 순차 탐색하다 역으로 돌아가는 탐색이 이동 횟수가 더 작은경우가 있다. 그러므로 `A`가 발견될 경우 `A`의 시작과 끝 인덱스를 저장하는 변수 `st`와 `ed`를 만들어준다.

- `0`번 인덱스 기준 앞으로 탐색해야하는 거리 `left`, 뒤로 탐색해야하는 거리 `right`를 만들어준다.

- `left`와 `right` 두 개 중 이동 횟수가 더 작은 것에 `2`를 곱해준다(다시 돌아가야하기 때문에).

- 현재의 최소 이동 횟수인 `move`보다 `left + right`가 더 작다면 `move`를 바꿔준다.

- 문자열 전체를 탐색하면서 원하는 알파벳을 만들기 위해 위 아래로 이동해야하는 최소 횟수를 `answer`에 더해준다.

- 아까 구한 `move`를 `answer`에 더해주고 출력한다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int st, ed, answer = 0;
    int move = name.size() - 1;

    for (int i = 1; i < name.size(); ++i) {
        if (name[i] == 'A') {
            ed = st = i;
            while (ed < name.size() && name[ed] == 'A') {
                ++ed;
            }
            int left = st - 1, right = name.size() - ed;
            if (left >= right) {
                right *= 2;
            }
            else {
                left *= 2;
            }
            if (left + right < move) {
                move = left + right;
            }
            i = ed - 1;
        }
    }
    for (auto& n : name) {
        if (n <= 'N') {
            answer += (n - 'A');
        }
        else {
            answer += 26 - (n - 'A');
        }
    }
    answer += move;

    return answer;
}
```
