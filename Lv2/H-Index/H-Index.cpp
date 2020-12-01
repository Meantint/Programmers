#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    int st = 0, ed = 10000, mid;
    mid = ((st + ed) >> 1);
    while (st <= ed) {
        int findIdx_st = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        int findIdx_ed = upper_bound(citations.begin(), citations.end(), mid) - citations.begin();
        // 조건을 만족하는 경우
        if (findIdx_ed <= mid && citations.size() - findIdx_st >= mid) {
            answer = max(answer, mid);

            // 더 위로 올려도 가능한지 확인 해야한다.
            st = mid + 1;
        }
        // 조건을 만족하지 못하면 더 아래로 내려가야한다.
        else {
            ed = mid - 1;
        }
        mid = ((st + ed) >> 1);
    }

    return answer;
}