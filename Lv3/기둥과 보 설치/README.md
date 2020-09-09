&nbsp;카카오 블라인드 문제. 너무 안풀렸다. 실제로 카카오 블라인드를 할 때도 대충 보고 넘어갔던 문제인데, 맘 먹고 다시 풀어봐도 안풀리는 것이다. 결국 인터넷 뒤적뒤적해서 풀었다. 참고로 나는 처음 문제를 기둥을 `(0, 0)`의 위치에 설치한다는 정보를 입력받으면 `(0, 0)`뿐만 아니라 `(0, 1)`에도 세워진다고 값을 설정했다.(이거 바꿨더니 맞았음) 똑같이 `(0, 0)`의 위치에 보를 설치한다는 정보를 입력받았을 때는 `(0, 0)`, `(1, 0)`에 세워진다고 설정했다. 

#### Programmers - [기둥과 보 설치](https://programmers.co.kr/learn/courses/30/lessons/60061)
#### My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

<hr>

## 풀이

- `(x, y)`위치에 기둥, 보가 세워졌는지 확인하는 2차원 백터 `gidung`, `bo`를 선언

- 우선 기둥과 보를 설치할 수 있는 조건을 알아야한다.

  - 기둥을 설치할 수 있는 조건
  
    1. 바닥 위에 설치한다.
    
    2. 다른 기둥의 위에 설치한다.
    
    3. 세우는 위치에 보가 하나 이상 있다.
  
  - 보를 설치할 수 있는 조건, 바닥이 아니어야 한다는 기본 전제.
  
    1. 보를 받쳐주는 기둥이 있다(보의 왼쪽이나 오른쪽)
    
    2. 양 옆에 보가 있다.
    
- 기둥과 보를 삭제하는 방법으로는 그 위치의 기둥/보를 제거한 후에 남은 기둥과 보가 설치 조건을 만족하고 있으면 없애고, 설치 조건을 만족하지 못한다면 그 명령을 무시하고 다음 명령으로 넘어간다.

- 모든 `build_frame`를 방문한 후 설치되어 있는 기둥과 보들을 `answer`에 넣은 후 `x`, `y`, `a`순으로 오름차순 해준다.

<hr>

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> gidung;
vector<vector<bool>> bo;

bool check()
{
    for (int i = 0; i < gidung.size(); ++i) {
        for (int j = 0; j < gidung[0].size() - 1; ++j) {
            // 기둥이 있다면
            if (gidung[i][j]) {
                if (j == 0 || bo[i][j])
                    continue;
                else if (j - 1 >= 0 && gidung[i][j - 1])
                    continue;
                else if (i - 1 >= 0 && bo[i - 1][j])
                    continue;
                // 기둥의 조건을 만족하지 못하면 false를 반환
                else
                    return false;
            }
        }
    }
    for (int i = 0; i < bo.size() - 1; ++i) {
        for (int j = 0; j < bo[0].size(); ++j) {
            // 보가 있다면
            if (bo[i][j]) {
                if (j - 1 >= 0 && gidung[i][j - 1])
                    continue;
                else if (j - 1 >= 0 && gidung[i + 1][j - 1])
                    continue;
                else if (i - 1 >= 0 && bo[i - 1][j] && bo[i + 1][j])
                    continue;
                // 기둥의 조건을 만족하지 못하면 false를 반환
                else
                    return false;
            }
        }
    }
    // 모든 것이 이상 없으면 true 반환
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    // 기둥과 보의 사이즈 설정
    gidung.resize(n + 1, vector<bool>(n + 1, 0));
    bo.resize(n + 1, vector<bool>(n + 1, 0));

    int buildSize = build_frame.size();
    for (int i = 0; i < buildSize; ++i) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        // 설치
        if (b == 1) {
            // 기둥
            if (a == 0) {
                // 조건을 만족하면
                if (y == 0) {
                    gidung[x][y] = true;
                }
                else if (y - 1 >= 0 && gidung[x][y - 1]) {
                    gidung[x][y] = true;
                }
                else if (bo[x][y]) {
                    gidung[x][y] = true;
                }
                else if (x - 1 >= 0 && bo[x - 1][y]) {
                    gidung[x][y] = true;
                }
            }
            // 보
            else if (a == 1) {
                // 조건을 만족하면
                if (y != 0) {
                    if (y - 1 >= 0 && gidung[x][y - 1]) {
                        bo[x][y] = true;
                    }
                    else if (y - 1 >= 0 && gidung[x + 1][y - 1]) {
                        bo[x][y] = true;
                    }
                    else if (x - 1 >= 0 && bo[x - 1][y] && bo[x + 1][y]) {
                        bo[x][y] = true;
                    }
                }
            }
        }
        // 삭제
        else {
            // 기둥
            if (a == 0) {
                gidung[x][y] = false;
                if (!check()) {
                    gidung[x][y] = true;
                }
            }
            // 보
            if (a == 1) {
                bo[x][y] = false;
                if (!check()) {
                    bo[x][y] = true;
                }
            }
            // }
        }
    }
    for (int i = 0; i < bo.size() - 1; ++i) {
        for (int j = 0; j < bo[0].size(); ++j) {
            if (bo[i][j]) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
                bo[i][j] = false;
            }
        }
    }
    for (int i = 0; i < gidung.size(); ++i) {
        for (int j = 0; j < gidung[0].size() - 1; ++j) {
            if (gidung[i][j]) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
                gidung[i][j] = false;
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
```

<hr>