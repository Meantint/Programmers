#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k)
{
    int answer = 0;

    long long test = 0;
    int foodSize = food_times.size();
    for (int i = 0; i < foodSize; ++i) {
        test += (long long)food_times[i];
    }
    if (test < k + 1) {
        return -1;
    }

    long long start, end, mid;
    start = 1;
    end = k;

    long long save = 0;
    long long save_k = k;
    while (start <= end) {
        long long sum = 0;
        mid = (start + end) / 2;
        vector<int> cp = food_times;
        int size = food_times.size();
        for (int i = 0; i < size; ++i) {
            if (mid > cp[i]) {
                sum += (long long)cp[i];
                cp[i] = 0;
            }
            else {
                sum += (long long)mid;
                cp[i] -= mid;
            }
        }
        if (sum > k) {
            end = mid - 1;
        }
        else {  // sum <= k
            save = mid;
            save_k = k - sum;
            start = mid + 1;
        }
    }
    // cout << save << '\n';
    for (int i = 0; i < foodSize; ++i) {
        if (food_times[i] > save) {
            if (save_k == 0) {
                return i + 1;
            }
            else {
                --save_k;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({3, 1, 2}, 5) << '\n';
    cout << solution({3, 1, 2}, 7) << '\n';
    cout << solution({7, 4, 10, 7}, 25) << '\n';
    cout << solution({7, 4, 10, 7}, 28) << '\n';
    cout << solution({1, 1, 1, 1, 1, 1}, 1) << '\n';

    return 0;
}