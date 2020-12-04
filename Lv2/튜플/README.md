# 프로그래머스 - 튜플

&nbsp;계속 메모리 초과라 그래서 왜 안되나 했는데 `while`문 안의 `if`문에 `continue`가 있어서 `++idx`가 적용안되고 있는 문제가 있었다. ㅎ;;

- Programmers - [튜플](https://programmers.co.kr/learn/courses/30/lessons/64065)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 사이즈 순으로 오름차순 정렬하는 함수 `comp`를 만든다.

- 다른 숫자 하나를 찾아주는 함수 `diff`를 만든다.

- `s`를 다 읽을 때까지 반복

  - `{}`안의 모든 숫자들을 `vector<int>` 변수 `tmp`에 넣어준다.

  - 모두 넣었다면 `sort(tmp.begin(), tmp.end(), comp)`를 해준 후 `v.push_back(tmp)` 해준다.

- `v`를 사이즈 순으로 오름차순 정렬한다.

- `answer.push_back(v[0][0])` 해준다(사이즈가 `1`인 경우).

- `diff`를 실행시켜 나온 값들을 차례대로 `answer.push_back()` 해준다.

## Code

```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    return v1.size() < v2.size();
}

int diff(const vector<int> &v1, const vector<int> &v2)
{
    int v1Size = v1.size();
    for (int i = 0; i < v1Size; ++i) {
        if (v1[i] != v2[i]) {
            return v2[i];
        }
    }
    return v2.back();
}

vector<int> solution(string s)
{
    vector<int> answer;
    vector<vector<int>> v;

    int size = s.size();
    for (int i = 1; i < size; ++i) {
        if (s[i] == '{') {
            int idx = i + 1;
            int num = 0;
            vector<int> tmp;
            while (s[idx] != '}') {
                if (s[idx] == ',') {
                    tmp.push_back(num);
                    num = 0;
                }
                else {
                    num *= 10;
                    num += (s[idx] - '0');
                }
                ++idx;
            }
            tmp.push_back(num);
            sort(tmp.begin(), tmp.end());
            v.push_back(tmp);

            i = idx;
        }
    }
    sort(v.begin(), v.end(), comp);
    answer.push_back(v[0][0]);

    int vSize = v.size();
    for (int i = 1; i < vSize; ++i) {
        answer.push_back(diff(v[i - 1], v[i]));
    }

    return answer;
}
```
