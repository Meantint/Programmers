# 프로그래머스 - 다음 큰 숫자

&nbsp;방법만 잘 찾으면 된다.

- Programmers - [다음 큰 숫자](https://programmers.co.kr/learn/courses/30/lessons/12911)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `n`을 이진수로 바꿔준다(`str`에 역순으로 저장됨). 마지막에 `'0'`을 더해준다.

- `for`문 탐색을 하면서 지나친 `'0'`과 `'1'`의 개수를 저장해놓는 `cnt_0`과 `cnt_1`을 만든다.

- 만약 `str[i]`이 `'1'`이고 `str[i + 1]`이 `'0'`인 경우 뒤집어줘야 하는 경우이므로 `swap(str[i], str[i + 1])`을 해주고 앞에서부터 이 때까지 세었던 `cnt_1`만큼 `'1'`을 추가해준뒤 `cnt_0`만큼 `'0'`을 추가해준다.

- `str`을 다시 십진수로 돌려주면 정답이 나온다.

## Code

```cpp
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    string str = "";
    while (n != 0) {
        str += to_string(n % 2);
        n /= 2;
    }
    str += '0';
    int size = str.size() - 1;
    int cnt_0 = 0, cnt_1 = 0;
    bool isChange = false;
    for (int i = 0; i < size; ++i) {
        if (str[i] == '1' && str[i + 1] == '0') {
            swap(str[i], str[i + 1]);
            for (int j = 0; j < cnt_1; ++j) {
                str[j] = '1';
            }
            for (int j = 0; j < cnt_0; ++j) {
                str[cnt_1 + j] = '0';
            }
            isChange = true;
            break;
        }
        if (str[i] == '0') {
            ++cnt_0;
        }
        else {
            ++cnt_1;
        }
    }
    if (!isChange) {
        str.back() = '0';
        str.push_back('1');
    }
    size = str.size();
    for (int i = 0; i < size; ++i) {
        answer += pow(2, i) * (str[i] - '0');
    }

    return answer;
}
```
