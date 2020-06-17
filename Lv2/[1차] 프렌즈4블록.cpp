#include <bits/stdc++.h>

using namespace std;

bool cycle = false;
bool mapCheck[30][30] = { 0 };

void changeBoard(vector<string>& board)
{
        int columnSize = board[0].size();
        for (int i = 0; i < columnSize; ++i) {
                string str;

                int rowSize = board.size();
                int blankCnt = 0; // 빈 칸의 개수를 센다.
                for (int j = 0; j < rowSize; ++j) {
                        if (board[j][i] != ' ') {
                                str.push_back(board[j][i]);
                        }
                        else
                                ++blankCnt;
                }
                for (int j = 0; j < board.size(); ++j) {
                        // str = ' ' + str;
                        if (j < blankCnt)
                                board[j][i] = ' ';
                        else {
                                board[j][i] = str[j - blankCnt];
                        }
                }
        }
}

void dfs22(int i, int j, vector<string> board)
{
        if (board[i][j] == board[i][j + 1]) {
                if (board[i][j] == board[i + 1][j]) {
                        if (board[i][j] == board[i + 1][j + 1]) {
                                mapCheck[i][j] = mapCheck[i][j + 1] = mapCheck[i + 1][j] = mapCheck[i + 1][j + 1] = 1;
                                cycle = true; // 부숴야 하는 22블록이 최소 1개 이상이다.
                        }
                }
        }
}

int solution(int m, int n, vector<string> board)
{
        int answer = 0;

        int rowSize = board.size();
        int columnSize = board[0].size();
        while (1) {
                cycle = false;
                memset(mapCheck, false, sizeof(mapCheck));
                for (int i = 0; i < rowSize - 1; ++i) { // 1 Cycle
                        for (int j = 0; j < columnSize - 1; ++j) {
                                if (board[i][j] == ' ')
                                        continue;
                                dfs22(i, j, board);
                        }
                }
                // 한 사이클 돌았는데 22블록이 없다면 break;
                if (cycle == false) {
                        break;
                }
                else {
                        for (int i = 0; i < rowSize; ++i) {
                                for (int j = 0; j < columnSize; ++j) {
                                        if (mapCheck[i][j] == true) {
                                                ++answer;
                                                board[i][j] = ' ';
                                        }
                                }
                        }
                }
                changeBoard(board);
        }
        return answer;
}

int main()
{
        cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }) << endl;

        return 0;
}
