#include <bits/stdc++.h>

using namespace std;

int answer = 0;
// bool isVisited[1001][1001] = { 0 };

void check(int i, int j, vector<vector<int>>& board)
{
        if (i == 0 || j == 0) {
                answer = max(answer, board[i][j]);
                return;
        }
        if (board[i][j] == 0)
                return;
        answer = max(answer, board[i][j]);
        if (board[i - 1][j - 1] == 0 || board[i - 1][j] == 0 || board[i][j - 1] == 0)
                return;
        else {
                board[i][j] = min({ board[i - 1][j - 1], board[i - 1][j], board[i][j - 1] }) + 1;
                answer = max(answer, board[i][j]);
        }
}

int solution(vector<vector<int>> board)
{
        int rowSize = board.size();
        int colSize = board[0].size();

        for (int i = 0; i < rowSize; ++i) {
                for (int j = 0; j < colSize; ++j) {
                        // if (!isVisited[i][j]) {
                        // check(i, j, board);
                        // }
                        check(i, j, board);
                }
        }

        return answer * answer;
}