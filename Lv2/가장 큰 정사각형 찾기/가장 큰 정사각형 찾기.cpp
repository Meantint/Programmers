#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            // 범위를 벗어나는 경우
            if (i - 1 == -1 || j - 1 == -1) {
                continue;
            }
            // 0인 경우도 볼 필요 없음
            if (board[i][j] == 0) {
                continue;
            }
            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
            if (answer < board[i][j]) {
                answer = board[i][j];
            }
        }
    }

    return answer * answer;
}