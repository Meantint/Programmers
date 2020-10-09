#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

int global_n;
int idx = 0;

void input(int cx, int cy, int len)
{
    for (int i = 0; i < len; ++i) {
        board[cx + i][cy] = ++idx;
    }
    for (int i = 1; i < len; ++i) {
        board[cx + len - 1][cy + i] = ++idx;
    }
    for (int i = 1; i < len - 1; ++i) {
        board[cx + len - 1 - i][cy + len - 1 - i] = ++idx;
    }

    if (len > 3) input(cx + 2, cy + 1, len - 3);
    return;
}

vector<int> solution(int n)
{
    vector<int> answer;
    global_n = n;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    input(0, 0, n);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(board[i][j]);
        }
    }

    return answer;
}