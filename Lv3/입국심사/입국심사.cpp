#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answer;

void solve(int n, vector<int> times)
{
    answer = -1;

    long long low = 1;
    long long high = (long long)1000000000 * (long long)1000000000;
    long long mid;

    long long sum;
    while (low <= high) {
        sum = 0;
        mid = (low + high) / (long long)2;

        for (long long time : times) {
            sum += (mid / time);
        }
        cout << "mid : " << mid << ", sum : " << sum << '\n';

        if (sum < n) {
            low = mid + 1;
        }
        else {
            if (answer == -1) {
                answer = mid;
            }
            else if (answer > mid) {
                answer = mid;
            }

            high = mid - 1;
        }
    }
}

long long solution(int n, vector<int> times)
{
    solve(n, times);

    return answer;
}