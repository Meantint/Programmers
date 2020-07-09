#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
        int answer = 0;

        map<int, int> m;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
                if (m.count(nums[i]) == 0) {
                        m[nums[i]] = 1;
                }
        }
        answer = (m.size() > size / 2) ? (size / 2) : m.size();
        return answer;
}