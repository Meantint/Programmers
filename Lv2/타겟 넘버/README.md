# 프로그래머스 - 타겟 넘버

&nbsp;

- Programmers - [타겟 넘버](https://programmers.co.kr/learn/courses/30/lessons/43165)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 함수 `solve`의 인자

  - `pos` : 현재 `global_numbers`의 인덱스

  - `val` : `pos - 1` 인덱스까지의 합을 저장

  - `isPlus` : `false`라면 `global_numbers[pos]`의 값에 `-1` 곱해준다.

- `global_numbers[pos]`의 부호가 `+` 혹은 `-` 두 가지이므로 `solve`를 `isTrue = 1`, `isTrue = 0`으로 두 번 호출한다.

- 만약 `pos`가 `nSize`에 도달했고 결과값이 타겟 넘버와 같다면 `++answer` 해준다.

- `pos`가 `nSize - 1`이고 `val + num`이 타겟 넘버와 같은 경우 `++answer`가 한번만 이루어져야 하지만 `solve()`가 두 개 있으므로 `++answer`가 두 번 실행되게 된다. 그러므로 최종 `answer`의 `1/2`가 정답이다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> global_numbers;
int global_target, nSize;
int answer = 0;

void solve(int pos, int val, bool isPlus)
{
    if (pos != nSize) {
        int num = global_numbers[pos];
        // 마이너스라면
        if (!isPlus) {
            num *= -1;
        }
        solve(pos + 1, val + num, 1);
        solve(pos + 1, val + num, 0);
    }
    else {
        if (val == global_target) {
            ++answer;
        }
    }
}

int solution(vector<int> numbers, int target)
{
    answer = 0;
    global_numbers = numbers;
    global_target = target;
    nSize = global_numbers.size();

    solve(0, 0, 1);
    solve(0, 0, 0);
    answer >>= 1;

    return answer;
}
```
