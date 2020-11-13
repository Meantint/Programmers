# 프로그래머스 - K번째수

&nbsp;범위가 작기 때문에 시키는 대로 구현하면 별 문제 없이 작동한다.

- Programmers - [K번째수](https://programmers.co.kr/learn/courses/30/lessons/42748)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `commands`의 각 행 별로 배열을 생성해서 답을 `answer`에 넣어주면 된다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (auto &command : commands) {
        vector<int> tmp;
        for (int i = command[0] - 1; i < command[1]; ++i) {
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[command[2] - 1]);
    }

    return answer;
}
```
