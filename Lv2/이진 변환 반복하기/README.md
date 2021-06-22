# 프로그래머스 - 이진 변환 반복하기

&nbsp;구현

- Programmers - [이진 변환 반복하기](https://programmers.co.kr/learn/courses/30/lessons/70129)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 받은 문자열이 `"1"`인 경우 리턴해준다. `"1"`이 아닌 경우는 `++answer[0]`를 해주면서 `0` 제거 및 이진법 변환 작업을 해준다.

- `0`이 있으면 제거하면서 `++answer[1]`를 해준다. 모두 제거한 후는 문자열의 길이를 이진법으로 변경하고 `solve` 함수를 재귀 실행시켜준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void solve(string s)
{
    if (s == "1") {
        return;
    }
    else {
        ++answer[0];

        string new_s = "";
        int size = s.size();

        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                ++answer[1];
            }
            else {
                new_s += '1';
            }
        }

        s = "";
        int num = new_s.size();

        while (num != 0) {
            s = (char)((num % 2) + '0') + s;
            num /= 2;
        }

        solve(s);

        return;
    }
}

vector<int> solution(string s)
{
    solve(s);

    return answer;
}
```
