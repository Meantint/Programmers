# 프로그래머스 - 가장 큰 수

&nbsp;예전에 푼 것 보다 `comp` 함수를 더 간결하게 잘 만들었다.

- Programmers - [가장 큰 수](https://programmers.co.kr/learn/courses/30/lessons/42746)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n1`의 뒤에 `n2`를 붙인 `s1`과 `n2`의 뒤에 `n1`을 붙인 `s2`의 크기를 비교하는 함수 `comp`를 만든다.

- 정렬된 `numbers`의 원소들을 `answer`에 차례대로 붙여준다.

- 만약 `answer`의 첫 원소 값이 `'0'`이라면 `answer`에 모든 값이 `'0'`이므로 `answer = '0'`으로 바꿔준다(`answer = '000'` 이런 식으로 되어 있으므로 바꿔줘야 한다.).

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const int& n1, const int& n2)
{
    string s1 = to_string(n1) + to_string(n2);
    string s2 = to_string(n2) + to_string(n1);

    return stoi(s1) > stoi(s2);
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), comp);
    for (auto& number : numbers) {
        answer += to_string(number);
    }
    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}
```
