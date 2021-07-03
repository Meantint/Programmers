#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dist;

int answer = 0;

void BinarySearch(int n)
{
    int low = 1, high = 1000000000;

    while (low <= high) {
        int ret = 0;
        int mid = (low + high) / 2;
        vector<int> temp;

        int dSize = dist.size();
        for (int i = 0; i < dSize; ++i) {
            // bool isLast = false;  // 마지막인지 판단 여부
            bool needCal = true;  // 계산이 필요한지의 여부
            int sum = dist[i];

            while (sum < mid) {
                ++ret;
                if (i + 1 < dSize) {
                    sum += dist[i + 1];
                    ++i;
                }
                // 현재 방문한 곳이 마지막이라면
                else {
                    if (sum < mid) {
                        needCal = false;
                        if (temp.empty()) {
                            temp.push_back(sum);
                        }
                        else {
                            temp.back() += sum;
                        }
                    }
                    break;
                }
            }

            if (needCal) {
                temp.push_back(sum);
            }
        }

        // cout << "low, high, ret => " << low << ", " << high << ", " << ret << '\n';
        // for (auto t : temp) {
        //     cout << t << ' ';
        // }
        // cout << '\n';
        if (ret == n) {
            int min_value = 2112345678;
            for (auto t : temp) {
                if (min_value > t) {
                    min_value = t;
                }
            }

            if (answer < min_value) {
                answer = min_value;
            }
        }

        if (ret > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
}

void solve(int distance, vector<int> rocks, int n)
{
    answer = 0;

    sort(rocks.begin(), rocks.end());

    dist.push_back(rocks[0]);
    int rSize = rocks.size();
    for (int i = 1; i < rSize; ++i) {
        dist.push_back(rocks[i] - rocks[i - 1]);
    }
    dist.push_back(distance - rocks.back());

    BinarySearch(n);

    // test
    vector<int> reverse(dist.size());
    for (int i = 0; i < dist.size(); ++i) {
        reverse[dist.size() - 1 - i] = dist[i];
    }
    dist = reverse;

    BinarySearch(n);
}

int solution(int distance, vector<int> rocks, int n)
{
    solve(distance, rocks, n);

    return answer;
}