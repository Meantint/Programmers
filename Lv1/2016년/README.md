# 프로그래머스 - 2016년

&nbsp;배열을 만들어둬서 쉽게 풀 수 있었다.

- Programmers - [2016년](https://programmers.co.kr/learn/courses/30/lessons/12901)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 요일을 저장하는 배열 `day`와 달의 일수를 저장해놓은 `month`를 배열을 만들었다.

- 1월 1일과 a월 b일의 날짜 차이만큼 `base`에 더해준 후 `answer = day[base % 7]`을 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

string solution(int a, int b)
{
    string answer = "";

    // 2016년 1월 1일을 금요일로 설정해 놓는다. (day[5] = "FRI")
    int base = 5;
    for (int i = a - 2; i >= 0; --i) {
        base += month[i];
    }
    base += (b - 1);
    answer = day[base % 7];

    return answer;
}
```
