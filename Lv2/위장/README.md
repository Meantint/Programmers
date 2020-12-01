# 프로그래머스 - 위장

&nbsp;`map`을 이용하여 풀었다.

- Programmers - [위장](https://programmers.co.kr/learn/courses/30/lessons/42578)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `map<string, int>` 변수 `m`을 만든다.

- for문 안에서 `e[1]`은 의상의 종류를 가리킨다.

- 이미 있는 의상의 종류를 받았다면 `++m[e[1]]` 해준다.

- 새로운 의상의 종류를 받았다면 `m[e[1]] = 1`을 해준다.

- `answer += (e[1] + 1)`을 해준다(의상을 안 입는 경우까지 더해준다).

- 의상을 하나도 안 입는 경우는 없으므로 `--answer`을 하여 하나 빼준다.

## Code

```cpp
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    for (auto& e : clothes) {
        if (m.find(e[1]) != m.end()) {
            ++m[e[1]];
        }
        else {
            m[e[1]] = 1;
        }
    }
    for (auto& e : m) {
        answer *= (e.second + 1);
    }
    --answer;

    return answer;
}
```
