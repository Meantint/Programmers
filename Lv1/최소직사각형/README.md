# 프로그래머스 - 최소직사각형

&nbsp;

## 문제/코드 링크

- [프로그래머스 - 최소직사각형](https://programmers.co.kr/learn/courses/30/lessons/86491)

- [My Programmers Repo](https://github.com/Meantint/Programmers)

## 풀이

- 우선 가로나 세로 중 더 큰 값과 작은 값을 일관적으로 나눠야 한다. 필자의 경우 더 큰 값을 가로로 보내도록 코드를 작성했다.

- 이후 가로에서 가장 큰 값 * 세로에서 가장 큰 값이 우리가 찾는 정답이다.

## Code

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int width = 0, height = 0;
    int size = sizes.size();
    for (int i = 0; i < size; ++i) {
        if (sizes[i][0] < sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        if (width < sizes[i][0]) {
            width = sizes[i][0];
        }
        if (height < sizes[i][1]) {
            height = sizes[i][1];
        }
    }

    answer = width * height;

    return answer;
}
```
