# 프로그래머스 - 게임 맵 최단거리

&nbsp;`BFS`를 이용하면 된다.

- Programmers - [게임 맵 최단거리](https://programmers.co.kr/learn/courses/30/lessons/1844)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `queue`에 여러 원소를 담기 위해 `tuple` 라이브러리를 사용했다.

- 배열의 범위를 체크하는 함수 `isSafe`를 만들고 2차원 배열을 탐색하는 함수 `bfs`를 만들었다.

- `dy[4], dx[4]`는 배열의 방향을 설정하는 배열

- `queue` 탐색에서 `y = ySize - 1`, `x = xSize - 1`인 경우 현재의 `cost`를 리턴해준다.

- 현재 이동시킨 위치가 벽이 아니고 방문한 적이 없다면 `queue`에 넣어준다.

## Code

```cpp
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int ySize, xSize;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (y < 0 || y >= ySize || x < 0 || x >= xSize) {
        return false;
    }
    return true;
}

int bfs(vector<vector<int>> maps)
{
    ySize = maps.size();
    xSize = maps[0].size();
    vector<vector<bool>> isVisited(ySize, vector<bool>(xSize, false));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));
    isVisited[0][0] = true;

    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int cost = get<2>(q.front());
        q.pop();

        if (y == ySize - 1 && x == xSize - 1) {
            return cost;
        }

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx)) {
                if (maps[cy][cx] == 1 && !isVisited[cy][cx]) {
                    q.push(make_tuple(cy, cx, cost + 1));
                    isVisited[cy][cx] = true;
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    answer = bfs(maps);

    return answer;
}
```
