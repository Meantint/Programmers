#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> heights)
{
        vector<int> answer;

        bool isBreak = false;
        int heightSize = heights.size();
        for (int i = 0; i < heightSize; ++i) {
                isBreak = false;
                for (int j = i; j >= 0; --j) {
                        if (heights[j] > heights[i]) {
                                answer.push_back(j + 1);
                                isBreak = true;
                                break;
                        }
                }
                if (!isBreak) {
                        answer.push_back(0);
                }
        }

        return answer;
}