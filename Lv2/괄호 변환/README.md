# 프로그래머스 - 괄호 변환

&nbsp;문제에 나온 순서대로 잘 구현해주면 된다.

- Programmers - [괄호 변환](https://programmers.co.kr/learn/courses/30/lessons/60058)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 빈 문자열인 경우 빈 문자열을 리턴해준다.

- `u`와 `v`로 분리하면서 올바른 괄호 문자열인지 확인해준다.

- 올바른 괄호 문자열이라면 `return u + solve(v)`를 해준다.

- 올바른 괄호 문자열이 아니라면 `'(' + solve(v) + ')'` + (`u`의 시작과 끝을 제외한 나머지 괄호들을 뒤집음)를 리턴해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solve(string w)
{
    // 빈 문자열인 경우
    if (w == "") {
        return "";
    }
    // u, v로 분리
    bool isGood = true;
    int bal = 0;
    string u = "", v = "";
    for (int i = 0; i < w.size(); ++i) {
        if (w[i] == '(') {
            u += '(';
            ++bal;
        }
        else {
            u += ')';
            --bal;
        }
        if (bal == 0) {
            v = w.substr(i + 1);
            break;
        }
        // bal이 음수가 되는 순간 올바른 괄호 문자열이 될 수 없음
        else if (bal < 0) {
            isGood = false;
        }
    }
    // 올바른 괄호 문자열이라면
    if (isGood) {
        return u + solve(v);
    }
    // 올바른 괄호 문자열이 아니라면
    else {
        string tmp = "(";
        tmp += solve(v);
        tmp += ')';

        for (int i = 1; i < u.size() - 1; ++i) {
            if (u[i] == '(') {
                tmp += ')';
            }
            else {
                tmp += '(';
            }
        }
        return tmp;
    }
}

string solution(string p)
{
    string answer = "";

    answer = solve(p);

    return answer;
}
```
