#include <string>
#include <vector>

using namespace std;

int val = 1;
int cnt, idx = 0;

void make(int x, int y, int k, vector<vector<int>>& b)
{
    // 세로
    for (int i = 0; i < k; ++i) {
        b[x + i][y] = val;
        ++val;
    }
    // 가로
    for (int i = 1; i < k; ++i) {
        b[x + k - 1][y + i] = val;
        ++val;
    }
    // 대각선
    for (int i = 1; i < k - 1; ++i) {
        b[x + k - 1 - i][y + k - 1 - i] = val;
        ++val;
    }
}

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n, 0));
    cnt = (n + 2) / 3;
    while (idx < cnt) {
        make(0 + idx * 2, 0 + idx, n - idx * 3, board);
        ++idx;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(board[i][j]);
        }
    }

    return answer;
}