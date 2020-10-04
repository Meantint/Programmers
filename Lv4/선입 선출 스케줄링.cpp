#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores)
{
    int answer = 0;

    int cSize = cores.size();
    int st = 0, ed = 1000000000;
    int mid;
    // n의 개수를 안넘는 가장 큰 시간
    int savTime = -1;
    // savTime 시간일 때의 처리한 일 개수
    long long savWork = -1;

    while (st <= ed) {
        mid = (st + ed) / 2;

        long long sum = 0;
        for (int i = 0; i < cSize; ++i) {
            sum += (long long)(mid / cores[i]) + 1;
        }
        if (sum >= (long long)n) {
            ed = mid - 1;
        }
        else if (sum < (long long)n) {
            savTime = mid;
            savWork = sum;
            st = mid + 1;
        }
        // cout << sum << '\n';
    }
    // cout << savTime << ", " << savWork << '\n';
    int idx = savTime;
    while (1) {
        ++idx;
        for (int i = 0; i < cSize; ++i) {
            if (idx % cores[i] == 0) ++savWork;
            if (savWork == n) {
                return i + 1;
            }
        }
    }
}

int main()
{
    cout << solution(6, {1, 2, 3}) << '\n';

    return 0;
}