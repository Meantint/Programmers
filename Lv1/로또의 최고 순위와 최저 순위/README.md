# 프로그래머스 - 로또의 최고 순위와 최저 순위

&nbsp;예외 케이스만 잘 처리해주면 된다.

- Programmers - [로또의 최고 순위와 최저 순위](https://programmers.co.kr/learn/courses/30/lessons/77484)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 알 수 없는 숫자의 개수 `zeroCnt`와 알고 있는 숫자 중 당첨 번호의 개수를 저장하는 `targetCnt`를 선언한다.

- 예외 케이스(`7`)가 아닌 경우 최저 등수는 `7 - targetCnt`이고 `7`인 경우는 `6`으로 바꾸면 된다.

- 예외 케이스(`0`)가 아닌 경우 최고 등수는 `answer[1] - zeroCnt`이고 `0`인 경우는 `1`로 바꾸면 된다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer(2);
    int zeroCnt = 0;
    int targetCnt = 0;

    sort(win_nums.begin(), win_nums.end());
    sort(lottos.begin(), lottos.end());

    for (int i = 0; i < 6; ++i) {
        if (lottos[i] == 0) {
            ++zeroCnt;

            continue;
        }
        else {
            for (int j = 0; j < 6; ++j) {
                if (win_nums[j] > lottos[i]) {
                    break;
                }
                else if (win_nums[j] == lottos[i]) {
                    ++targetCnt;
                    break;
                }
            }
        }
    }
    answer[1] = 7 - targetCnt;
    if (answer[1] == 7) {
        answer[1] = 6;
    }
    answer[0] = answer[1] - zeroCnt;
    if (answer[0] == 0) {
        answer[0] = 1;
    }

    return answer;
}
```
