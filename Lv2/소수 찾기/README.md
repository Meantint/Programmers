# 프로그래머스 - 소수 찾기

&nbsp;예전에 짠 코드는 수를 받을 때 마다 소수인지 아닌지 for문으로 검사했다. 이번에 짠 코드는 미리 `9999999`까지의 소수를 미리 판별하는 작업을 거쳐서 그런지 시간차이가 엄청나게 났다. 그래도 이게 더 깔끔한듯 ㅎ

- Programmers - [소수 찾기](https://programmers.co.kr/learn/courses/30/lessons/42839)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 주어진 `length` 만큼의 숫자를 `allNum`에 넣어주는 함수 `pushAllNum`을 만든다.

- 중복되는 경우가 아주 많기 때문에 `do-while` 안에 if문을 넣어 어느정도 줄여주었다(실제 if를 넣은 코드와 넣지 않은 코드를 비교했을 때 if를 넣은 코드가 평균 `5ms` 정도 빨랐다).

- `allNum`을 오름차순 정렬한 후, `erase`와 `unique`를 사용해 중복되는 수를 없애주었다.

- 이후 `allNum`을 탐색하며 현재 탐색하고 있는 `allNum`의 원소가 소수라면 `++answer`를 해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> allNum = {1};
vector<bool> isPrime(10000000, true);

void pushAllNum(int length, string numbers)
{
    do {
        // 중복되는 경우가 아주 많기 때문에 마지막 원소와 같을 경우 다음 원소로 넘어가준다.
        if (allNum.back() == stoi(numbers.substr(0, length))) {
            continue;
        }
        allNum.push_back(stoi(numbers.substr(0, length)));
    } while (next_permutation(numbers.begin(), numbers.end()));
}

int solution(string numbers)
{
    int answer = 0;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10000000; ++i) {
        if (isPrime[i] == false) {
            continue;
        }
        for (int j = i * 2; j < 10000000; j += i) {
            isPrime[j] = false;
        }
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 1; i <= numbers.size(); ++i) {
        pushAllNum(i, numbers);
    }
    sort(allNum.begin(), allNum.end());
    allNum.erase(unique(allNum.begin(), allNum.end()), allNum.end());
    for (auto& num : allNum) {
        if (isPrime[num]) {
            ++answer;
        }
    }

    return answer;
}
```
