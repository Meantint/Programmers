#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
        vector<int> answer;

        int arrSize = arr.size();
        answer.push_back(arr[0]);
        for (int i = 1; i < arrSize; ++i) {
                if (!answer.empty() && arr[i] != answer.back())
                        answer.push_back(arr[i]);
        }

        return answer;
}