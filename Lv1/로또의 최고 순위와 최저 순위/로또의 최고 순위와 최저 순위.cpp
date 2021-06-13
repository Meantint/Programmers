#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer(2);
    int zeroCnt = 0;
    int targetCnt = 0;

    sort(win_nums.begin(), win_nums.end());
    sort(lottos.begin(), lottos.end());

    for (int i = 0; i < 6; ++i) {
        if (lottos[i] == 0) {
            ++zeroCnt;

            continue;
        }
        else {
            for (int j = 0; j < 6; ++j) {
                if (win_nums[j] > lottos[i]) {
                    break;
                }
                else if (win_nums[j] == lottos[i]) {
                    ++targetCnt;
                    break;
                }
            }
        }
    }
    answer[1] = 7 - targetCnt;
    if (answer[1] == 7) {
        answer[1] = 6;
    }
    answer[0] = answer[1] - zeroCnt;
    if (answer[0] == 0) {
        answer[0] = 1;
    }

    return answer;
}