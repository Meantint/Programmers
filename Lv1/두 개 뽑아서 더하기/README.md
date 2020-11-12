# 프로그래머스 - 두 개 뽑아서 더하기

&nbsp;사이즈가 작기 때문에 더한 수들을 모두 저장하고 중복되는 값들을 `unique` 함수와 `erase` 함수를 이용해서 지워준다.

- Programmers - [두 개 뽑아서 더하기](https://programmers.co.kr/learn/courses/30/lessons/68644)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 같은 값을 가지는 원소가 있다면 `answer.erase(unique(answer.begin(), answer.end()), answer.end())`를 통해 값을 하나씩만 남겨둔다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    int size = numbers.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    sort(answer.begin(), answer.end());

    return answer;
}
```
