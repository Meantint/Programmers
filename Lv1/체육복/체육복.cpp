#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    vector<int> p(n, 1);

    for (auto& l : lost) {
        --p[l - 1];
    }
    for (auto& r : reserve) {
        ++p[r - 1];
    }
    for (int i = 0; i < n; ++i) {
        // 2벌 있을 때 다른 친구들에게 빌려줄 수 있다.
        if (p[i] == 2) {
            // 왼쪽부터 빌려줘야하는지 검사!
            if (i - 1 >= 0 && p[i - 1] == 0) {
                --p[i];
                ++p[i - 1];
            }
            // 왼쪽을 빌려주지 않아도 된다면 오른쪽 검사!
            else if (i + 1 < n && p[i + 1] == 0) {
                --p[i];
                ++p[i + 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] > 0) ++answer;
    }

    return answer;
}