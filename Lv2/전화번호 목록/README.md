# 프로그래머스 - 전화번호 목록

&nbsp;`set`을 이용해 풀었다.

- Programmers - [전화번호 목록](https://programmers.co.kr/learn/courses/30/lessons/42577)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `phone_book`을 오름차순 정렬한다.

- `phone_book`의 원소를 앞부분에서 시작하여 길이를 1씩 늘리며 `s`에 접두어가 존재하는지 확인하고 하나라도 발견된다면 `false`를 리턴해준다.

- 접두어가 존재하지 않는경우 `answer(=true)`를 리턴한다.

## Code

```cpp
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    set<string> s;
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (auto& num : phone_book) {
        int pSize = num.size();
        for (int i = 0; i < pSize; ++i) {
            // 접두어가 존재하는 경우
            if (s.find(num.substr(0, i + 1)) != s.end()) {
                return false;
            }
        }
        s.insert(num);
    }

    return answer;
}
```
