#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int block = 333;
int row;
int col;

// (x, y)에서 시작하여 2 * 3직사각형을 만들 수 있는지 검사하는 함수
bool isRect23(int x, int y, vector<vector<int>> board)
{
    int blockNum = -1;
    // 번호 붙은 block이 4개여야 true
    int blockCnt = 0;
    // 직사각형이 만들어지면 true, 아니면 false
    bool isTrue = true;
    // 2 * 3 검사
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            int cur = board[i + x][j + y];
            // block이라면 ++cnt
            if (cur == block) continue;
            // 빈 공간이라면 컷
            else if (cur == 0) {
                isTrue = false;
                break;
            }
            else if (cur != 0 && cur != block) {
                // 아직 다른 block을 한번도 만나지 않았다면
                if (blockNum == -1) {
                    blockNum = cur;
                    ++blockCnt;
                }
                // 다른 block을 만난적이 있고 그 block이 현재 위치의 block 번호와 같을 때
                else if (blockNum != -1 && blockNum == cur) {
                    ++blockCnt;
                    continue;
                }
                // 다른 block을 만난적이 있고 그 block이 현재 위치의 block 번호와 다를 때
                else {
                    isTrue = false;
                    break;
                }
            }
        }
        if (isTrue == false) {
            break;
        }
    }
    if (isTrue && blockCnt == 4) return true;
    else
        return false;
}

// (x, y)에서 시작하여 3 * 2 직사각형을 만들 수 있는지 검사하는 함수
bool isRect32(int x, int y, vector<vector<int>> board)
{
    int blockNum = -1;
    // 번호 붙은 block이 4개여야 true
    int blockCnt = 0;
    // 직사각형이 만들어지면 true, 아니면 false
    bool isTrue = true;
    // 3 * 2 검사
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            int cur = board[i + x][j + y];
            // block이라면 ++cnt
            if (cur == block) continue;
            // 빈 공간이라면 컷
            else if (cur == 0) {
                isTrue = false;
                break;
            }
            else if (cur != 0 && cur != block) {
                // 아직 다른 block을 한번도 만나지 않았다면
                if (blockNum == -1) {
                    blockNum = cur;
                    ++blockCnt;
                }
                // 다른 block을 만난적이 있고 그 block이 현재 위치의 block 번호와 같을 때
                else if (blockNum != -1 && blockNum == cur) {
                    ++blockCnt;
                    continue;
                }
                // 다른 block을 만난적이 있고 그 block이 현재 위치의 block 번호와 다를 때
                else {
                    isTrue = false;
                    break;
                }
            }
        }
        if (isTrue == false) {
            break;
        }
    }
    if (isTrue && blockCnt == 4) return true;
    else
        return false;
}

// 채울 수 있는 곳을 block으로 바꿔주는 함수(가능한곳만!)
void fillmap(vector<vector<int>>& board)
{
    // 모든 열에 대하여 반복한다.
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            // 비어있다면 block을 넣는다.
            if (board[j][i] == 0) board[j][i] = block;
            // 블록이면 건너뛴다.
            else if (board[j][i] == block)
                continue;
            // 다른 블록을 만났을 때 break
            else
                break;
        }
    }
    return;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    row = board.size();
    col = board[0].size();
    int cnt = 0;
    do {
        cnt = 0;
        fillmap(board);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] != 0) {
                    // 2 * 3 만들어진다면
                    if (i + 1 < row && j + 2 < col && isRect23(i, j, board)) {
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = 0;
                        board[i + 1][j] = board[i + 1][j + 1] = board[i + 1][j + 2] = 0;
                        ++cnt;
                    }
                    // 3 * 2 만들어진다면
                    else if (i + 2 < row && j + 1 < col && isRect32(i, j, board)) {
                        board[i][j] = board[i + 1][j] = board[i + 2][j] = 0;
                        board[i][j + 1] = board[i + 1][j + 1] = board[i + 2][j + 1] = 0;
                        ++cnt;
                    }
                }
            }
        }
        answer += cnt;
    } while (cnt != 0);

    return answer;
}