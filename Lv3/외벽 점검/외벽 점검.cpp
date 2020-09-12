#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> new_weak;
int nSize;
int wSize;

int solve(int st, vector<int> dist)
{
    vector<int> weakPos;
    int minCnt = 2112345678;

    for (int i = 0; i < wSize; ++i) {
        // st의 기준을 항상 0으로 잡을 것임.
        weakPos.push_back(new_weak[i + st] - new_weak[st]);
    }
    do {
        int idx = 0;
        int cnt = 0;
        while (idx < wSize) {
            if (cnt >= dist.size()) {
                cnt = 2112345678;
                break;
            }
            int pos = weakPos[idx] + dist[cnt];
            ++cnt;
            ++idx;
            while (idx < wSize && pos >= weakPos[idx]) {
                ++idx;
            }
        }
        minCnt = min(minCnt, cnt);
    } while (next_permutation(dist.begin(), dist.end()));

    return minCnt;
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 2112345678;

    nSize = n;
    wSize = weak.size();
    new_weak = weak;
    sort(dist.begin(), dist.end());

    for (int i = 0; i < wSize; ++i) {
        new_weak.push_back(weak[i] + n);
    }
    for (int i = 0; i < weak.size(); ++i) {
        answer = min(answer, solve(i, dist));
    }

    if (answer == 2112345678) {
        return -1;
    }
    return answer;
}