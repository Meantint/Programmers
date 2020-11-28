# 프로그래머스 - 주식가격

&nbsp;완전탐색하면 `O(N^2)`이므로 최대 `N = 100000`이기 떄문에 시간초과가 나야한다. 근데 안난다... 예전에 완전탐색으로 풀었는데 맞았다. 이번에는 시간 복잡도를 생각하여 스택으로 풀었다.

- Programmers - [주식가격](https://programmers.co.kr/learn/courses/30/lessons/42584)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `(price, index)`를 저장하는 `stack<pair<int, int>>` 타입 변수 `st`를 만든다.

- `curIdx`는 `price`의 `prices` 내부 위치 인덱스이다.

- `st`이 비어있을 경우 바로 `st.push()` 해준다.

- `st`가 비어있지 않은 경우

  - `st.top().second <= price`인 경우에는 `st.push()` 해준다.

  - `st.top().first > price`인 경우에는 `st` 안의 `price` 보다 큰 값들을 모두 제거 해준 후 `st.push()`를 해준다. 제거를 할 때 `answer`에 값을 저장해준다.

- for문이 완료된 후 `st`에 남아있는 값들을 `answer`에 저장해주면서 `st.pop()` 해준다.

## Code

```cpp
#include <stack>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

stack<PII> st;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), -1);

    for (auto& price : prices) {
        int curIdx = &price - &prices[0];
        // 비어 있을 경우
        if (st.empty()) {
            st.push(make_pair(price, curIdx));
        }
        else {
            // 스택의 가장 큰 값보다 price가 더 크거나 같을 경우
            if (st.top().first <= price) {
                st.push(make_pair(price, curIdx));
            }
            // st.top()이 더 클 경우는 빼줘야한다.
            else {
                // 몇 개가 있을지 모르기 때문에 while문 사용
                while (!st.empty() && st.top().first > price) {
                    answer[st.top().second] = curIdx - st.top().second;
                    st.pop();
                }
                // price보다 더 큰 stack의 요소들을 제거한 후 stack에 넣어준다.
                st.push(make_pair(price, curIdx));
            }
        }
    }

    // stack에 남아있는 나머지 요소들을 answer에 넣어준 후 빼준다.
    int topIdx = st.top().second;
    while (!st.empty()) {
        answer[st.top().second] = topIdx - st.top().second;
        st.pop();
    }

    return answer;
}
```
