# 프로그래머스 - 기능개발

&nbsp;

- Programmers - [기능개발](https://programmers.co.kr/learn/courses/30/lessons/42586)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 배포된 작업의 개수를 저장하는 변수 `relCnt`와 한 사이클에 실행되는 작업의 수를 저장하는 변수 `pgCnt`를 선언한다.

- 첫 번째 while문 : `relCnt >= pSize`가 될 때까지 반복한다.

  - 각각의 `progresses`를 각각의 `speeds` 만큼 더해준다.

  - 현재 탐색 중인 `progresses[relCnt]`가 `100`을 넘어 작업이 끝난 경우 `++pgCnt`와 `++relCnt`를 해준다.

  - 다음 `progresses[relCnt]` 역시 작업이 끝난 경우 위와 같은 작업을 진행해준다.

  - 2번째 while문이 끝난 후 `pgCnt`가 `0`이 아니라면 작업이 최소 하나는 끝난 것이므로 `answer.push_back(pgCnt)`를 해주고 `pgCnt = 0`으로 초기화 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int relCnt = 0;
    // 한 사이클에 실행되는 작업의 수를 세는 변수
    int pgCnt = 0;

    int pSize = progresses.size();
    // 마지막 작업이 배포되기 전까지 계속
    while (relCnt < pSize) {
        for (int i = 0; i < pSize; ++i) {
            progresses[i] += speeds[i];
        }
        // 작업이 끝났다면
        // relCnt의 바로 뒤부터 작업이 끝나있는 상태일 수 있기 때문에 한 번에 처리해야한다.
        // 그래서 while문 사용!
        while (relCnt < pSize && progresses[relCnt] >= 100) {
            ++pgCnt;
            ++relCnt;
        }
        // while문을 돌고 나온 상태라면
        if (pgCnt != 0) {
            answer.push_back(pgCnt);
            pgCnt = 0;
        }
    }

    return answer;
}
```
