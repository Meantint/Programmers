# 프로그래머스 - 폰켓몬

&nbsp;폰켓몬의 종류를 모두 세어 그 개수를 폰켓몬을 골라야 하는 개수와 비교하여 정답을 도출해냈다.

- Programmers - [폰켓몬](https://programmers.co.kr/learn/courses/30/lessons/1845)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `count_mon` : 폰켓몬 종류의 개수를 담는 변수

- `max_mon = size / 2` : 골라야 하는 폰켓몬의 개수를 담아놓은 변수

- 정렬하지 않고 풀기 위해서는 `map`이 필요하다고 생각(다른게 있는지 없는지 확인해야해서), 오름차순 정렬을 하였다.

- 전체 탐색을 하면서 다른 종류의 폰켓몬이 나타날 때마다 `++count_mon`을 해준다.

- 폰켓몬 종류가 고르는 폰켓몬 수보다 많은 경우 `answer = 고르는 폰켓몬 수`

- 폰켓몬 종류가 고르는 포켓몬 수보다 적은 경우 `answer = 폰켓몬 종류 수`

## Code

```cpp
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    sort(nums.begin(), nums.end());
    int size = nums.size();
    int max_mon = size / 2;

    int count_mon = 1;
    int prev = nums[0];
    for (int i = 1; i < size; ++i) {
        if (prev != nums[i]) {
            ++count_mon;
            prev = nums[i];
        }
    }
    answer = (count_mon > max_mon) ? max_mon : count_mon;

    return answer;
}
```
