#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int len_x, len_y;
int areaCnt = 0;
int bigArea = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j, vector<vector<int>>& p)
{
    int cnt = 0;

    queue<PII> q;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (p[cx][cy] == 0) {
            continue;
        }
        ++cnt;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            // 범위 밖이면 컷
            if (ccx < 0 || ccx >= len_x || ccy < 0 || ccy >= len_y) {
                continue;
            }
            // 색깔이 다르다면
            if (p[cx][cy] != p[ccx][ccy]) {
                continue;
            }
            q.push(make_pair(ccx, ccy));
        }
        p[cx][cy] = 0;
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<int> answer(2);

    areaCnt = 0, bigArea = 0;
    len_x = m, len_y = n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 칠하지 않은 영역
            if (picture[i][j] == 0) {
                continue;
            }
            else {
                ++areaCnt;
                int cnt = bfs(i, j, picture);
                if (bigArea < cnt) {
                    bigArea = cnt;
                }
            }
        }
    }
    answer[0] = areaCnt;
    answer[1] = bigArea;

    return answer;
}