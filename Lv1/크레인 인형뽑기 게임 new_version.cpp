#include <bits/stdc++.h>

using namespace std;

// 바구니
vector<int> basket(0);
int answer = 0;

void change(vector<vector<int>> &board, int idx)
{
    int rowSize = board.size();
    for (int i = 0; i < rowSize; ++i)
    {
        // 배열의 원소 값이 0일 때
        if (board[i][idx - 1] == 0)
            continue;
        // 바구니의 마지막 인형과 방금 넣은 인형이 같을 때
        if (!basket.empty() && board[i][idx - 1] == basket.back())
        {
            basket.pop_back();
            board[i][idx - 1] = 0;
            answer += 2;
            break;
        }
        else
        {
            basket.push_back(board[i][idx - 1]);
            board[i][idx - 1] = 0;
            break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int Size = moves.size();
    for (int i = 0; i < Size; ++i)
    {
        change(board, moves[i]);
    }

    return answer;
}