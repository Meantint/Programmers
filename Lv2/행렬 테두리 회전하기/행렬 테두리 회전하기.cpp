#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

int rotate(vector<int> query)
{
    int ret = 2112345678;

    int sy = query[0] - 1, sx = query[1] - 1;
    int ey = query[2] - 1, ex = query[3] - 1;

    int prev = board[sy + 1][sx];
    ret = prev;
    for (int x = sx; x <= ex; ++x) {
        int tmp = board[sy][x];
        board[sy][x] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int y = sy + 1; y <= ey; ++y) {
        int tmp = board[y][ex];
        board[y][ex] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int x = ex - 1; x >= sx; --x) {
        int tmp = board[ey][x];
        board[ey][x] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }
    for (int y = ey - 1; y > sy; --y) {
        int tmp = board[y][sx];
        board[y][sx] = prev;
        prev = tmp;
        if (ret > prev) {
            ret = prev;
        }
    }

    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    board = vector<vector<int>>(rows, vector<int>(columns));

    int val = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j] = ++val;
        }
    }
    int qSize = queries.size();
    for (int i = 0; i < qSize; ++i) {
        answer.push_back(rotate(queries[i]));
    }

    return answer;
}