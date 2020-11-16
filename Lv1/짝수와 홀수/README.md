# 프로그래머스 - 짝수와 홀수

&nbsp;삼항 연산자 사용함.

- Programmers - [짝수와 홀수](https://programmers.co.kr/learn/courses/30/lessons/12937)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 삼항 연산자를 이용해 풀었다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(int num)
{
    string answer = "";

    answer = ((num % 2 == 0) ? "Even" : "Odd");

    return answer;
}
```
