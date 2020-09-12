#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

vector<vector<int>> newBoard;
// [0] : 오른쪽 한칸 더, [1] : 아래로 한칸 더
int dx[2] = {0, 1};
int dy[2] = {1, 0};
pair<PII, int> pos;
int row;

int solution(vector<vector<int>> board)
{
    int answer = 2112345678;

    row = board.size();

    newBoard.resize(row + 2, vector<int>(row + 2, 1));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }
    row = newBoard.size();

    pos.first.first = 1;
    pos.first.second = 1;
    pos.second = 0;

    // (x, y, dir)을 방문 했는지 확인하는 변수
    vector<vector<vector<bool>>>
        isVisited(row, vector<vector<bool>>(row, vector<bool>(2, false)));
    isVisited[pos.first.first][pos.first.second][pos.second] = true;
    queue<pair<PII, int>> q;
    // distance
    queue<int> d;
    q.push(pos);
    d.push(0);

    int idx = 1;  // test
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        int dist = d.front();
        // test
        // cout << "case #" << idx++ << "\n";
        // cout << x << ", " << y << ", " << dir << ", " << dist << "\n\n";
        q.pop();
        d.pop();

        // 로봇의 오른쪽 부분이나 아랫쪽 부분이 목적지에 도달하였다면
        if (x + dx[dir] == row - 2 && y + dy[dir] == row - 2) {
            answer = dist;
            break;
        }

        if (newBoard[x + 2 * dx[dir]][y + 2 * dy[dir]] == 0) {
            if (!isVisited[x + dx[dir]][y + dy[dir]][dir]) {
                q.push(make_pair(make_pair(x + dx[dir], y + dy[dir]), dir));
                d.push(dist + 1);
                isVisited[x + dx[dir]][y + dy[dir]][dir] = true;
            }
        }
        if (newBoard[x - dx[dir]][y - dy[dir]] == 0) {
            if (!isVisited[x - dx[dir]][y - dy[dir]][dir]) {
                q.push(make_pair(make_pair(x - dx[dir], y - dy[dir]), dir));
                d.push(dist + 1);
                isVisited[x - dx[dir]][y - dy[dir]][dir] = true;
            }
        }

        // 로봇이 한 행에 2개 있다면 (dir = 0)
        if (dir == 0) {
            // 로봇의 윗 두칸이 모두 0이라면
            if (newBoard[x - 1][y] == 0 && newBoard[x - 1][y + 1] == 0) {
                // 아직 방문한 적이 없다면
                if (!isVisited[x - 1][y][1]) {
                    q.push(make_pair(make_pair(x - 1, y), 1));
                    d.push(dist + 1);
                    isVisited[x - 1][y][1] = true;
                }
                if (!isVisited[x - 1][y + 1][1]) {
                    q.push(make_pair(make_pair(x - 1, y + 1), 1));
                    d.push(dist + 1);
                    isVisited[x - 1][y + 1][1] = true;
                }
                if (!isVisited[x - 1][y][0]) {
                    q.push(make_pair(make_pair(x - 1, y), 0));
                    d.push(dist + 1);
                    isVisited[x - 1][y][0] = true;
                }
            }
            // 로봇의 아래 두칸이 모두 0이라면
            if (newBoard[x + 1][y] == 0 && newBoard[x + 1][y + 1] == 0) {
                if (!isVisited[x][y][1]) {
                    q.push(make_pair(make_pair(x, y), 1));
                    d.push(dist + 1);
                    isVisited[x][y][1] = true;
                }
                if (!isVisited[x][y + 1][1]) {
                    q.push(make_pair(make_pair(x, y + 1), 1));
                    d.push(dist + 1);
                    isVisited[x][y + 1][1] = true;
                }
                if (!isVisited[x + 1][y][0]) {
                    q.push(make_pair(make_pair(x + 1, y), 0));
                    d.push(dist + 1);
                    isVisited[x + 1][y][0] = true;
                }
            }
        }
        // 로봇이 한 열에 2개 있다면 (dir = 1)
        else {
            // 로봇의 두 왼쪽 칸이 모두 0이라면
            if (newBoard[x][y - 1] == 0 && newBoard[x + 1][y - 1] == 0) {
                if (!isVisited[x][y - 1][0]) {
                    q.push(make_pair(make_pair(x, y - 1), 0));
                    d.push(dist + 1);
                    isVisited[x][y - 1][0] = true;
                }
                if (!isVisited[x + 1][y - 1][0]) {
                    q.push(make_pair(make_pair(x + 1, y - 1), 0));
                    d.push(dist + 1);
                    isVisited[x + 1][y - 1][0] = true;
                }
                if (!isVisited[x][y - 1][1]) {
                    q.push(make_pair(make_pair(x, y - 1), 1));
                    d.push(dist + 1);
                    isVisited[x][y - 1][1] = true;
                }
            }
            // 로봇의 두 오른쪽 칸이 모두 0이라면
            if (newBoard[x][y + 1] == 0 && newBoard[x + 1][y + 1] == 0) {
                if (!isVisited[x][y][0]) {
                    q.push(make_pair(make_pair(x, y), 0));
                    d.push(dist + 1);
                    isVisited[x][y][0] = true;
                }
                if (!isVisited[x + 1][y][0]) {
                    q.push(make_pair(make_pair(x + 1, y), 0));
                    d.push(dist + 1);
                    isVisited[x + 1][y][0] = true;
                }
                if (!isVisited[x][y + 1][1]) {
                    q.push(make_pair(make_pair(x, y + 1), 1));
                    d.push(dist + 1);
                    isVisited[x][y + 1][1] = true;
                }
            }
        }
    }

    return answer;
}