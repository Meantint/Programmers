&nbsp;2020 카카오 블라인드 문제. 문제에서 시키는대로 재귀 함수를 만들면 된다. 괄호 방향을 뒤집으라고 했는데 원소 순서를 바꿔서 풀어서 시간 낭비가 있었다.

#### Programmers - [괄호 변환](https://programmers.co.kr/learn/courses/30/lessons/60058)
#### My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

<hr>

## 풀이

- 문제에서의 `u`는 함수 내에서 처리 가능하기 때문에 함수 `solve`의 인자는 하나만 받는다.

- `w.size() == 0`이면 `return ""`한다.

- `w[0] == '('`이라면 올바른 괄호 이므로 `isGood = true`을 해준다.

- 문자열을 `u`와 `v`로 나눈 후 문자열을 판단하게 되는데

  - 올바른 괄호 문자열이라면
    
    - `return u + solve(v)`를 해준다.
   
  - 균형잡힌 괄호 문자열이라면
  
    - `(` + `solve(v)` + `)` + (`u[0]`과 `u.back()`을 제외한 나머지 원소의 괄호 방향을 뒤집어서 더한다)
  
<hr>

## Code
```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(string w)
{
    if (w.size() == 0) {
        return "";
    }
    bool isGood = false;
    int bal = 0;

    string u = "", v = "";
    int size = w.size();
    for (int i = 0; i < size; ++i) {
        if (w[i] == '(') {
            ++bal;
            if (i == 0) {
                isGood = true;
            }
        }
        else {
            --bal;
        }

        if (bal == 0) {
            u = w.substr(0, i + 1);
            if (i + 1 < w.size())
                v = w.substr(i + 1);
            break;
        }
    }
    // 올바른 괄호 문자열이라면
    if (isGood) {
        return u + solve(v);
    }
    else {
        string tmp = "(";
        tmp += solve(v);
        tmp += ')';
        int uSize = u.size();
        for (int i = 1; i < uSize - 1; ++i) {
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

// int main()
// {
//     cout << solution("(()())()") << '\n';
//     cout << solution(")(") << '\n';
//     cout << solution("()))((()") << '\n';
//     cout << solution("))(()(") << '\n';

//     return 0;
// }
```

<hr>