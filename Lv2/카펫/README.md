# 프로그래머스 - 카펫

&nbsp;

- Programmers - [카펫](https://programmers.co.kr/learn/courses/30/lessons/42842)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `brown`과 `yellow`를 합치면 전체 카펫의 넓이가 나오므로 둘을 합친 값을 저장하는 변수 `all`을 만든다.

- `all`의 `(int)`제곱근 만큼의 범위를 탐색하기위해 `range`를 만들었다.

- 만약 나눠떨어지고 갈색 부분을 뺀 가로 * 세로가 `yellow`와 같다면 정답이므로 가로의 길이인 `all / i`와 세로의 길이인 `i`를 `answer`에 넣어준다.

## Code

```cpp
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int all = brown + yellow;
    int range = (int)sqrt(all);
    for (int i = 1; i <= range; ++i) {
        // 나눠 떨어진다면
        if (all % i == 0) {
            // 갈색 부분을 뺀 직사각형의 넓이가 yellow와 같다면
            if ((i - 2) * (all / i - 2) == yellow) {
                answer.push_back(all / i);
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}
```
