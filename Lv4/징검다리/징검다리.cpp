#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> dist;

int answer = 0;

void BinarySearch(int n)
{
    int low = 1, high = 1000000000;
    int mid = (low + high) / 2;

    while (low <= high) {
        int ret = 0;
        vector<int> temp;

        int sum = 0;

        for (auto d : dist) {
            sum += d;
            if (sum < mid) {
                ++ret;
            }
            else {
                sum = 0;
            }
        }

        if (ret > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    answer = mid;
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
}

int solution(int distance, vector<int> rocks, int n)
{
    solve(distance, rocks, n);

    return answer;
}