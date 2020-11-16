# 프로그래머스 - 정수 내림차순으로 배치하기

&nbsp;내림차순 정렬 후 다시 `answer`에 넣어준다. 예전에 푼 것을 보니 그냥 `stoll()`을 이용하면 된다..!

- Programmers - [정수 내림차순으로 배치하기](https://programmers.co.kr/learn/courses/30/lessons/12933)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `str`에 한 자리 수로 분해해서 넣어준 후 `greater<char>()`를 이용해 내림차순 정렬해준다.

- `answer`에 `10`을 곱한 후 한 자리 씩 더해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    string str = "";
    while (n != 0) {
        str.push_back(n % 10 + '0');
        n /= 10;
    }
    // 내림차순 정렬
    sort(str.begin(), str.end(), greater<char>());
    for (auto& s : str) {
        answer *= (long long)10;
        answer += (long long)(s - '0');
    }

    return answer;
}
```
