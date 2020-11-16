# 프로그래머스 - [1차] 비밀지도

&nbsp;`string` 사이즈만 잘 맞춰주면 무난한 문제.

- Programmers - [[1차] 비밀지도](https://programmers.co.kr/learn/courses/30/lessons/17681)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `merge[i] = (arr1[i] | arr2[i])`

- `merge[i] % 2`가 나누어 떨어지면 `tmp += ' '`를 해준다.

- `merge[i] % 2`가 나누어 떨어지지 않으면 `tmp += '#'`를 해준다.

- `tmp.size() == n`이 될 때까지 `tmp`에 공백을 넣어준다.

- `tmp`를 거꾸로 뒤집은 후 `answer`에 넣는다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    int size = arr1.size();
    vector<int> merge(size);

    for (int i = 0; i < size; ++i) {
        merge[i] = (arr1[i] | arr2[i]);
    }
    for (auto &val : merge) {
        string tmp = "";
        while (val != 0) {
            // 나누어 떨어진다면
            if (val % 2 == 0) {
                tmp += ' ';
            }
            // 나누어 떨어지지 않는다면
            else {
                tmp += '#';
            }
            val >>= 1;
        }
        // 암호의 길이가 n보다 작다면
        while (tmp.size() != n) {
            tmp += ' ';
        }
        // 거꾸로 뒤집어준다.
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }

    return answer;
}
```
