# 프로그래머스 - 문자열 내 마음대로 정렬하기

&nbsp;정렬 방법을 직접 설정해주면 된다.

- Programmers - [문자열 내 마음대로 정렬하기](https://programmers.co.kr/learn/courses/30/lessons/12915)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 정렬을 위한 함수 `comp`를 만들어주었다.

  - `s1[N] == s2[N]`인 경우 사전 우선 순위 값으로 리턴한다.

  - `s1[N] != s2[N]`인 경우 `return s1[N] < s2[N]` 해준다.

- `comp`를 위한 전역 변수 `N`을 만들고 `N = n`으로 설정해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;

bool comp(const string &s1, const string &s2)
{
    if (s1[N] == s2[N]) {
        return s1 < s2;
    }
    return s1[N] < s2[N];
}

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    N = n;
    sort(strings.begin(), strings.end(), comp);
    answer = strings;

    return answer;
}
```
