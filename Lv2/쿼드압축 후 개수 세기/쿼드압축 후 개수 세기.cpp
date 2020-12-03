#include <string>
#include <vector>

using namespace std;

int cnt_0 = 0, cnt_1 = 0;
vector<vector<int>> global_arr;

void solve(int x, int y, int size)
{
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (global_arr[x + i][y + j] == 1) {
                ++cnt;
            }
        }
    }
    // 범위 내의 원소들의 값이 모두 1이라면
    if (cnt == size * size) {
        ++cnt_1;
    }
    // 범위 내의 원소들의 값이 모두 0이라면
    else if (cnt == 0) {
        ++cnt_0;
    }
    // 수가 섞여있다면
    else {
        int half = size / 2;
        solve(x, y, half);
        solve(x, y + half, half);
        solve(x + half, y, half);
        solve(x + half, y + half, half);
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    global_arr = arr;
    solve(0, 0, arr.size());

    answer.push_back(cnt_0);
    answer.push_back(cnt_1);

    return answer;
}