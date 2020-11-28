# 프로그래머스 - 문자열 압축

&nbsp;

- Programmers - [문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `s.size()`가 `1`인 경우 `answer = 1`을 해준다.

- 바로 직전의 부분 문자를 저장하는 `string` 변수 `prev`와 `i`개씩 나눴을 때의 결과를 저장하는 `string` 변수 `tmp`를 만든다.

- 이번에 탐색하는 부문 문자열 `cur`과 `prev`가 같다면 `++sameCnt`를 해준다.

- `cur`와 `prev`가 같지 않다면

  - `sameCnt`가 `1`인 경우에는 굳이 숫자를 붙일 필요 없으므로 `tmp += prev` 해준다.

  - `sameCnt`가 `2` 이상인 경우 `tmp += prev`를 하기전 `to_string(sameCnt)`를 `tmp`에 더해준다.

- 이후 `prev = cur` 해준다.

- for문을 나오고 나서 for문 안에서 처리가 안된 `prev`를 처리해준다.

- 부분 사이즈가 `i` 보다 작아서 탐색이 불가능 했던 문자들을 `tmp`에 더해준다.

- 이후 `tmp.size()`와 현재 `answer`를 비교해서 `tmp.size()`가 더 작다면 `answer = tmp.size()` 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1001;

    int size = s.size();
    int searchSize = size / 2;
    for (int i = 1; i <= searchSize; ++i) {
        int sameCnt = 1;
        string tmp = "";
        string prev = "";
        int j;
        for (j = 0; j + i - 1 < size; j += i) {
            string cur = s.substr(j, i);
            // 이번에 탐색한 문자와 이전에 탐색한 문자와 일치할 때
            if (cur == prev) {
                ++sameCnt;
            }
            else {
                // 하나밖에 없었다면 숫자를 붙일 필요가 없다.
                if (sameCnt == 1) {
                    tmp += prev;
                    prev = cur;
                }
                // 2개 이상이었다면
                else {
                    tmp += (to_string(sameCnt) + prev);
                    prev = cur;
                    sameCnt = 1;
                }
            }
        }
        if (sameCnt != 1) {
            tmp += (to_string(sameCnt) + prev);
        }
        else {
            tmp += prev;
        }
        tmp += s.substr(j);
        // 압축 완료 후의 길이가 현재 answer 값 보다 작다면 교체
        if (tmp.size() < answer) {
            answer = tmp.size();
        }
    }
    // 예외 : s.size()가 1인 경우
    if (size == 1) {
        answer = 1;
    }

    return answer;
}
```
