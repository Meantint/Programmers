#include <bits/stdc++.h>

using namespace std;

bool isVisited[101][101];
vector<vector<int>> board;

int dfs(int i, int j, int color)
{
        // 배열 범위를 벗어나면 return 0
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
                return 0;
        if (isVisited[i][j] == true)
                return 0;
        if (board[i][j] != color)
                return 0;

        isVisited[i][j] = true;

        return dfs(i + 1, j, color) + dfs(i - 1, j, color) + dfs(i, j + 1, color) + dfs(i, j - 1, color) + 1;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
        int max_area = -1;
        int cnt_area = 0;
        memset(isVisited, false, sizeof(isVisited));
        board = picture;

        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (isVisited[i][j] == false && board[i][j] != 0) {
                                ++cnt_area;
                                max_area = max(max_area, dfs(i, j, board[i][j]));
                        }
                }
        }

        vector<int> answer(2);
        answer[0] = cnt_area;
        answer[1] = max_area;
        return answer;
}