# 프로그래머스 - 크레인 인형뽑기 게임

&nbsp;`stack`을 이용하여 풀었다.

- Programmers - [크레인 인형뽑기 게임](https://programmers.co.kr/learn/courses/30/lessons/64061)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `st.top() == board[i][num]`일 때 `st.pop()` 해준다.

- `st.empty() == true`라면 `st.push(val)` 해준다.

- `st.top() != val`일 때 `st.push(val)` 해준다.

## Code

```cpp
#include <stack>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int bSize;
stack<int> st;

void pick(vector<vector<int>>& board, int num)
{
    for (int i = 0; i < bSize; ++i) {
        int val = board[i][num];
        // 인형이 있을 때
        if (val != 0) {
            // 인형을 뽑는다.
            board[i][num] = 0;
            // 스택이 비어 있다면
            if (st.empty()) {
                st.push(val);
            }
            // 스택이 비어 있지 않고 st.top() == val 일 때
            else if (st.top() == val) {
                answer += 2;
                st.pop();
            }
            // st.top() != val 일 때
            else {
                st.push(val);
            }
            return;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    bSize = board.size();
    int mSize = moves.size();
    for (int i = 0; i < mSize; ++i) {
        pick(board, moves[i] - 1);
    }

    return answer;
}
```
