# 프로그래머스 - 괄호 회전하기

&nbsp;최대 크기가 `1000`이기 때문에 모든 경우의 수를 탐색하는데 최대 `1000 * 1000` 정도가 걸린다.

- Programmers - [괄호 회전하기](https://programmers.co.kr/learn/courses/30/lessons/76502)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `LIFO(Last In, First Out)` 구조를 사용해야 하기 때문에 스택을 사용한다.

- 현재 탐색 중인 문자와 `s.top()`의 값이 짝을 이룬다면 `s.pop()`을 실행한다.

- 문자열의 `0`번째 인덱스를 가장 뒤로 넘겨주면서 모든 경우를 탐색해본다.

- 만약 현재의 문자열이 잘못된 상태인 것을 확인 했을 때는 `s.push('$')`를 실행한다.

## Code

```cpp
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int size = s.size();

    string tmp = s;
    for (int i = 0; i < size; ++i) {
        stack<char> s;

        for (int j = 0; j < size; ++j) {
            if (tmp[j] == '(' || tmp[j] == '{' || tmp[j] == '[') {
                s.push(tmp[j]);
            }
            else if (tmp[j] == ']' && !s.empty() && s.top() == '[') {
                s.pop();
            }
            else if (tmp[j] == ')' && !s.empty() && s.top() == '(') {
                s.pop();
            }
            else if (tmp[j] == '}' && !s.empty() && s.top() == '{') {
                s.pop();
            }
            else {
                s.push('$');
                break;
            }
        }
        if (s.empty()) {
            ++answer;
        }
        tmp = tmp.substr(1) + tmp[0];
    }

    return answer;
}
```
