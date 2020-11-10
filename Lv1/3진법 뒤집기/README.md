&nbsp;문제에 나와 있는 순서대로 구현하면 쉽게 풀 수 있는 문제.

#### Programmers - [3진법 뒤집기](https://programmers.co.kr/learn/courses/30/lessons/68935)
#### My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n`이 0이 될 때까지 while문을 반복한다.

- `str`에 저장된 값을 `reverse`해준다.

- `answer += (현재 위치의 값) * 3^(자릿수 위치)`

## Code
```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    string str = "";

    while (n != 0) {
        str += to_string(n % 3);
        n /= 3;
    }
    // 뒤집어 준다.
    reverse(str.begin(), str.end());

    int sSize = str.size();
    for (int i = 0; i < sSize; ++i) {
        answer += (str[i] - '0') * pow(3, i);
    }

    return answer;
}
```