# 프로그래머스 - 입국심사

&nbsp;범위 설정이 잘못돼서 테스트케이스 4개가 계속 틀렸다. 인터넷 찬스 씀.

- Programmers - [입국심사](https://programmers.co.kr/learn/courses/30/lessons/43238)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `1` ~ `1,000,000,000`의 범위를 이분탐색하는 것이 아니라 `1` ~ `1,000,000,000 * 1,000,000,000`의 볌위를 이분탐색 해야하는데 이유는 다음과 같다.

  - 설정한 `low`와 `high` 자체가 정답을 도출하는 핵심 값인데 `high`의 경우 나올 수 있는 최악의 시간으로 설정해줘야 한다. 나올 수 있는 최악의 시간은 `1,000,000,000 * 1,000,000,000`인데 이 경우는 검사를 하는데 한 명당 `1,000,000,000`의 시간이 걸리는 감독관 한 명이 `1,000,000,000`의 사람들을 검사하는 경우이다.

    - 내가 오류를 범한 곳이 `high`의 초기 값인데 `1,000,000,000`으로 설정하여서 이 이상의 시간이 나오는 경우 제대로 된 값을 출력하지 못한 것 같다.

- 범위 설정을 제외한 나머지 `solve` 함수 내의 코드들은 기본적인 이분탐색 알고리즘과 유사하다.

- 한 감독관이 특정 시간 내에 몇 명의 사람을 검사할 수 있는지를 나타내는 값 `mid / time`을 `sum`에 더해준다.

- 모든 감독관이 `mid`라는 특정 시간 내 측정할 수 있는 모든 사람의 수를 담은 `sum`이 `n`보다 작을 경우 `low = mid + 1`을 실행시켜준다. `sum`이 `n`보다 크거나 같을 경우 `answer = -1`로 한 번도 `mid` 값을 저장한 적이 없다면 `answer = mid`를 실행해준다. `answer != -1 && answer > mid`인 경우에도 `answer = mid`를 실행해준다. 그리고 `high = mid - 1`을 실행해준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answer;

void solve(int n, vector<int> times)
{
    answer = -1;

    long long low = 1;
    long long high = (long long)1000000000 * (long long)1000000000;
    long long mid;

    long long sum;
    while (low <= high) {
        sum = 0;
        mid = (low + high) / (long long)2;

        for (long long time : times) {
            sum += (mid / time);
        }
        cout << "mid : " << mid << ", sum : " << sum << '\n';

        if (sum < n) {
            low = mid + 1;
        }
        else {
            if (answer == -1) {
                answer = mid;
            }
            else if (answer > mid) {
                answer = mid;
            }

            high = mid - 1;
        }
    }
}

long long solution(int n, vector<int> times)
{
    solve(n, times);

    return answer;
}
```
