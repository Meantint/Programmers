# 프로그래머스 - 행렬의 덧셈

&nbsp;

- Programmers - [행렬의 덧셈](https://programmers.co.kr/learn/courses/30/lessons/12950)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `answer`의 사이즈를 `arr1`과 똑같이 만들어준다.

- `answer[i][j] = arr1[i][j] + arr2[i][j]`를 실행한다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer = vector<vector<int>>(arr1.size(), vector<int>(arr1[0].size()));

    int row = arr1.size();
    int col = arr1[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return answer;
}
```
