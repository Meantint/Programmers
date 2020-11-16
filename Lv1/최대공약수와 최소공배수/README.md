# 프로그래머스 - 최대공약수와 최소공배수

&nbsp;크기가 100만이기에 서로소인 경우 최소공배수가 `int` 범위를 초과할 수 있을 것 같지만 문제에서 `vector<int>`형으로 제시하였기 때문에 그냥 `int` 범위로 설정해서 풀었다.

- Programmers - [최대공약수와 최소공배수](https://programmers.co.kr/learn/courses/30/lessons/12940)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 최대공약수를 구하는 함수 `gcd`를 만들었다.

- `n1`과 `n2`의 최소공배수 = `n1 * n2 / gcd(n1, n2)`이다.

  - `n1 * n2`부터 시행하면 `int` 범위를 초과하기 때문에 먼저 최대공약수로 두 수 중 하나를 나누어주었다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int gcd(int n1, int n2)
{
    // n2 > n1이라면 값을 바꿔준다.
    if (n2 > n1) swap(n1, n2);

    // 나누어 떨어진다면 n2를 리턴
    if (n1 % n2 == 0) return n2;
    // 아니라면 재귀호출
    else {
        return gcd(n2, n1 % n2);
    }
}

vector<int> solution(int n, int m)
{
    vector<int> answer;

    // answer에 최대공약수 넣음
    answer.push_back(gcd(n, m));
    answer.push_back((n / answer[0]) * m);

    return answer;
}
```
