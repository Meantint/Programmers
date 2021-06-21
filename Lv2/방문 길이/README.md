# 프로그래머스 - 방문 길이

&nbsp;좌표를 저장하는게 아니라 좌표 사이의 선을 저장해야하기 때문에 잘 생각해야하는 문제.

- Programmers - [방문 길이](https://programmers.co.kr/learn/courses/30/lessons/49994)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- 현재의 위치를 저장하는 `pair<int, int>` 변수 `current_pos`를 선언하고, 지나가는 모든 좌표를 저장하는 `vector<tuple<int, int, int>>` 변수 `save_pos`를 선언하였다.

- 이동할 위치가 문제에서 선언한 좌표 범위 내인지 확인하는 함수 `canMove`를 선언하고 `canMove = true`라면 선의 정보를 저장하고 현재 위치를 갱신해주는 함수 `Push`를 선언했다. `Move` 함수는 `URLD`중 하나의 값을 받아 `find_index`를 설정해주고 `Push` 함수를 호출하는 함수이다.

- 전체 문자열을 다 탐색하면 이동했던 모든 좌표가 `save_pos`에 저장되어 있다. 이 좌표들 중 겹치는 것이 있으면 제외해야하기 때문에 `sort` 함수를 사용한 후 `prev != save_pos[i]`라면 `++answer`를 해주었다.

## Code

```cpp
#include <algorithm>
// #include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

pair<int, int> current_pos = make_pair(0, 0);
int find_index;
vector<tuple<int, int, int>> save_pos;

// URDL
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool canMove(int y, int x)
{
    if (y < -5 || y > 5 || x < -5 || x > 5) {
        return false;
    }
    return true;
}

void Push()
{
    if (canMove(current_pos.first + dy[find_index], current_pos.second + dx[find_index])) {
        int cy, cx, cd;
        if (find_index > 1) {
            cy = current_pos.first + dy[find_index];
            cx = current_pos.second + dx[find_index];
            cd = find_index - 2;
        }
        else {
            cy = current_pos.first;
            cx = current_pos.second;
            cd = find_index;
        }

        save_pos.push_back(make_tuple(cy, cx, cd));

        current_pos.first += dy[find_index];
        current_pos.second += dx[find_index];
    }
}

void Move(char ch)
{
    if (ch == 'U') {
        find_index = 0;
    }
    else if (ch == 'R') {
        find_index = 1;
    }
    else if (ch == 'D') {
        find_index = 2;
    }
    else if (ch == 'L') {
        find_index = 3;
    }
    Push();
}
int solution(string dirs)
{
    int answer = 0;
    int size = dirs.size();

    save_pos.clear();
    for (int i = 0; i < size; ++i) {
        Move(dirs[i]);
    }

    answer = 1;
    sort(save_pos.begin(), save_pos.end());
    int save_size = save_pos.size();
    tuple<int, int, int> prev = save_pos[0];

    // for (int i = 0; i < save_size; ++i) {
    //     cout << get<0>(save_pos[i]) << ", " << get<1>(save_pos[i]) << ", " << get<2>(save_pos[i]) << '\n';
    // }

    for (int i = 1; i < save_size; ++i) {
        if (prev == save_pos[i]) {
            continue;
        }
        else {
            ++answer;
            prev = save_pos[i];
        }
    }

    return answer;
}
```
