# 프로그래머스 - 스킬트리

&nbsp;크기가 작았기 때문에 `map`을 이용해서 풀었다. 실수로 `skill`의 값들을 `map`에 넣지 않아서 헤맸다.

- Programmers - [스킬트리](https://programmers.co.kr/learn/courses/30/lessons/49993)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 올바른 스킬트리인지 확인하는 `bool` 타입 변수 `isGood`을 만든다.

- `skill`의 인덱스를 저장하는 `curPos` 변수를 만든다.

- `map::find`를 이용하여 `st`를 찾고 `skill` 안에 있는지 확인한다.

- `skill` 안에 없을 경우에는 `skill_tree`의 다음 인덱스를 탐색한다.

- `skill` 안에 있을 경우에 현재 탐색 중인 `st`가 `skill[curPos]`와 일치하는지 본다.

  - 일치하는 경우 : 스킬트리가 올바른 순서이므로 `++curPos` 해준다.

  - 일치하지 않는 경우 : 스킬트리가 올바르지 않으므로 `isGood = false`로 바꿔준 후 `break` 해준다.

- 2번째 for문을 나온 후, `isGood`이 `true`라면 `++answer`를 해준다(올바른 스킬트리이므로).

## Code

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> m;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (auto& s : skill) {
        m[s] = &s - &skill[0];
    }

    for (auto& skill_tree : skill_trees) {
        // 올바른 스킬트리인지 확인하는 bool 타입 변수
        bool isGood = true;
        int curPos = 0;
        // cout << skill_tree << endl;
        for (auto& st : skill_tree) {
            auto it = m.find(st);
            // cout << it->first << ", " << m.end()->first << endl;

            // find에 실패했을시 map 컨테이너의 end()를 리턴하는 것을 이용한다.
            // skill 순서안에 포함된다면
            if (it != m.end()) {
                // 스킬트리 순서를 따른다면
                if (st == skill[curPos]) {
                    ++curPos;
                }
                // 순서가 잘못된 스킬트리라면
                else {
                    isGood = false;
                    break;
                }
            }
        }
        // 스킬트리가 올바르다면
        if (isGood) {
            ++answer;
        }
    }

    return answer;
}
```
