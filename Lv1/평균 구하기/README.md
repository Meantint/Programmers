# 프로그래머스 - 평균 구하기

&nbsp;시키는대로 하자!

- Programmers - [평균 구하기](https://programmers.co.kr/learn/courses/30/lessons/12944)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 배열의 합을 저장하는 변수 `sum`을 선언했다.

- `answer = (double)(sum) / (double)arr.size()`을 실행한다(형 변환 해줌).

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;

    int sum = 0;
    for (auto& a : arr) {
        sum += a;
    }
    answer = (double)(sum) / (double)arr.size();

    return answer;
}
```
