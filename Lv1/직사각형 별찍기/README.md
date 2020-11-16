# 프로그래머스 - 직사각형 별찍기

&nbsp;

- Programmers - [직사각형 별찍기](https://programmers.co.kr/learn/courses/30/lessons/12969)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n`이 열의 개수를 나타내고 `m`이 행의 개수를 나타내는 것만 조심하면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
```
