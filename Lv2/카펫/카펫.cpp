#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int all = brown + yellow;
    int range = (int)sqrt(all);
    for (int i = 1; i <= range; ++i) {
        // 나눠 떨어진다면
        if (all % i == 0) {
            // 갈색 부분을 뺀 직사각형의 넓이가 yellow와 같다면
            if ((i - 2) * (all / i - 2) == yellow) {
                answer.push_back(all / i);
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}