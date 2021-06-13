# 프로그래머스 - 약수의 개수와 덧셈

&nbsp;완전탐색

- Programmers - [약수의 개수와 덧셈](https://programmers.co.kr/learn/courses/30/lessons/77884)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `1 ~ 1000`의 범위에서 약수의 개수가 홀수인 수는 많지 않다(어떤 수의 제곱일 때만 약수의 개수가 홀수). 그렇기 때문에 미리 배열에 담아서 저장해놓는다.

- `left ~ right`의 범위를 탐색하면서 값 하나하나를 배열과 비교해보면서 배열 안에 들어있는 값이라면 약수의 개수가 홀수이기 때문에 `answer -= i`를 해준다. 배열 안에 들어있지 않다면 약수의 개수가 짝수이기 때문에 `answer += i`를 해준다.

- 배열 탐색 과정에서 값을 찾아 연산을 했는지의 여부를 확인해주는 `isCal` 변수를 선언하여 `isCal = false`인 경우에는 `answer += i`를 해준다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

int solution(int left, int right)
{
    int answer = 0;

    for (int i = 1; i < 32; ++i) {
        arr.push_back(i * i);
    }
    int size = arr.size();

    bool isCal = false;
    for (int i = left; i <= right; ++i) {
        isCal = false;
        for (int j = 0; j < size; ++j) {
            if (arr[j] > i) {
                break;
            }
            if (arr[j] == i) {
                answer -= i;
                isCal = true;
                break;
            }
        }

        if (!isCal) {
            answer += i;
        }
    }

    return answer;
}
```
