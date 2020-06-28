#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit)
{
        int answer = 0;

        sort(people.begin(), people.end(), greater<int>());
        int pSize = people.size();
        int backIdx = pSize - 1;
        for (int i = 0; i < pSize; ++i) {
                if (backIdx < i)
                        break;
                else if (backIdx == i) {
                        ++answer;
                        --backIdx;
                        break;
                }
                if (people[i] + people[backIdx] <= limit) {
                        ++answer;
                        --backIdx;
                }
                else
                        ++answer;
        }

        return answer;
}