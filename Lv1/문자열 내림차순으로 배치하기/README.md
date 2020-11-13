# 프로그래머스 - 문자열 내림차순으로 배치하기

&nbsp;문자 정렬은 아스키코드 기준이므로 기존에 있는 `greater<char>()`로 쉽게 풀 수 있다.

- Programmers - [문자열 내림차순으로 배치하기](https://programmers.co.kr/learn/courses/30/lessons/12917)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 내림차순 정렬을 위해 `greater<char>()`를 사용해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    sort(s.begin(), s.end(), greater<char>());
    answer = s;

    return answer;
}
```
