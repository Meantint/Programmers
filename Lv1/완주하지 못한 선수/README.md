# 프로그래머스 - 완주하지 못한 선수

&nbsp;항상 `participant`가 `completion` 보다 한 명 더 많기 때문에 `completion[i] != participant[i]`인 경우 무조건 `participant[i]`가 완주하지 못한 참가자이다. for문에서 찾지 못한 경우 마지막 값인 `participant.back()`가 완주하지 못한 참가자이다.

- Programmers - [완주하지 못한 선수](https://programmers.co.kr/learn/courses/30/lessons/42576)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- for문에서 답을 찾지 못한 경우 마지막이 참가자가 완주 못한 참가자이기 때문에 미리 `answer = participant.back()`로 설정 해놓는다.

- `completion[i] == participant[i]`이면 `continue`

- `completion[i] != participant[i]`이면 `answer = participant[i]`

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    // answer가 갱신 안되면 마지막 참가자가 완주 못한 것
    // answer가 갱신 되면 갱신 된 참가자가 완주 못한 것
    answer = participant.back();

    // 항상 참가자가 한 명 더 많다.
    int cSize = completion.size();
    for (int i = 0; i < cSize; ++i) {
        if (completion[i] == participant[i]) continue;

        // 다른 경우
        answer = participant[i];
        break;
    }

    return answer;
}
```
