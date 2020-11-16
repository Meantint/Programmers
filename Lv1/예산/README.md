# 프로그래머스 - 예산

&nbsp;

- Programmers - [예산](https://programmers.co.kr/learn/courses/30/lessons/12982)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `d`를 오름차순 정렬해준다.

- `budget`이 `cost`보다 크거나 같다면 `budget -= cost`를 실행하고 `++answer`를 해준다.

- `budget < cost`라면 `break`한 후 `return answer` 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    sort(d.begin(), d.end());
    for (auto& cost : d) {
        // 비용을 지불할 예산이 있다면
        if (cost <= budget) {
            budget -= cost;
            ++answer;
        }
        // 없다면 break
        else {
            break;
        }
    }

    return answer;
}
```
