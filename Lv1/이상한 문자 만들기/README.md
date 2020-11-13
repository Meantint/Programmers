# 프로그래머스 - 이상한 문자 만들기

&nbsp;단어가 바뀔 때마다 index를 초기화해주면 쉽게 풀 수 있다.

- Programmers - [이상한 문자 만들기](https://programmers.co.kr/learn/courses/30/lessons/12930)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `s[i] == ' '`이라면 `strIdx = 0`으로 초기화해준다.

- `strIdx`가 짝수이고 `s[i]`가 소문자라면

  - 대문자로 바꿔준다.

- `strIdx`가 홀수이고 `s[i]`가 대문자라면

  - 소문자로 바꿔준다.
  
- 단어 검사를 하고 난 후 `++strIdx`를 해준다.

## Code

```cpp
#include <string>

using namespace std;

string solution(string s)
{
    // 단어의 index를 저장하는 변수
    int strIdx = 0;
    int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (s[i] == ' ') {
            strIdx = 0;
        }
        else {
            // 짝수 index라면
            if (strIdx % 2 == 0) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
            }
            // 홀수 index라면
            else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
            ++strIdx;
        }
    }

    return s;
}
```
