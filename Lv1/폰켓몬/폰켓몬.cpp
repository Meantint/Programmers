#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    sort(nums.begin(), nums.end());
    int size = nums.size();
    int max_mon = size / 2;

    int count_mon = 1;
    int prev = nums[0];
    for (int i = 1; i < size; ++i) {
        if (prev != nums[i]) {
            ++count_mon;
            prev = nums[i];
        }
    }
    answer = (count_mon > max_mon) ? max_mon : count_mon;

    return answer;
}