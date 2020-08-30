#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, n;
int answer = 0;

bool del(int m, int n, vector<string>& board)
{
    int cnt = 0;
    vector<vector<bool>> isCheck(m, vector<bool>(n, false));
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (board[i][j] == ' ') {
                continue;
            }
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                isCheck[i][j] = isCheck[i + 1][j] = isCheck[i][j + 1] = isCheck[i + 1][j + 1] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isCheck[i][j]) {
                ++cnt;
                board[i][j] = ' ';
            }
        }
    }
    if (cnt == 0) {
        return false;
    }
    else {
        answer += cnt;
        for (int j = 0; j < n; ++j) {
            for (int i = m - 1; i >= 0; --i) {
                if (board[i][j] == ' ') {
                    for (int k = i - 1; k >= 0; --k) {
                        if (board[k][j] != ' ') {
                            char tmp = board[k][j];
                            board[k][j] = board[i][j];
                            board[i][j] = tmp;
                            break;
                        }
                    }
                }
            }
        }
        return true;
    }
}

int solution(int m, int n, vector<string> board)
{
    while (del(m, n, board)) {
    };

    return answer;
}

int main()
{
    cin >> m >> n;
    vector<string> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> vec[i];
    }

    cout << solution(m, n, vec) << '\n';

    return 0;
}