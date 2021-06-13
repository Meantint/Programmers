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