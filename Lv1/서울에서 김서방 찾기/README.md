# 프로그래머스 - 서울에서 김서방 찾기

&nbsp;

- Programmers - [서울에서 김서방 찾기](https://programmers.co.kr/learn/courses/30/lessons/12919)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `str == "Kim"`이라면 현재 인덱스를 `answer`에 다른 문구들과 함께 넣어준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";

    for (auto &str : seoul) {
        if (str == "Kim") {
            answer = "김서방은 " + to_string(&str - &seoul[0]) + "에 있다";
            break;
        }
    }

    return answer;
}
```
