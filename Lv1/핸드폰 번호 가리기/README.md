# 프로그래머스 - 핸드폰 번호 가리기

&nbsp;

- Programmers - [핸드폰 번호 가리기](https://programmers.co.kr/learn/courses/30/lessons/12948)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `reverse`해서 앞의 4개 번호를 제외한 나머지 번호를 `*`로 바꿔준 후 다시 `reverse` 해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";

    reverse(phone_number.begin(), phone_number.end());
    for (int i = 4; i < phone_number.size(); ++i) {
        phone_number[i] = '*';
    }
    reverse(phone_number.begin(), phone_number.end());
    answer = phone_number;

    return answer;
}
```
