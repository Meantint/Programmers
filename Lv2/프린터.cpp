#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int solution(vector<int> priorities, int location)
{
        int answer = 1;

        int priorSize = priorities.size();
        queue<PII> q;
        for (int i = 0; i < priorSize; ++i) {
                q.push(make_pair(priorities[i], i));
        }
        sort(priorities.begin(), priorities.end(), greater<int>());
        int priorIdx = 0;
        while (1) {
                if (priorities[priorIdx] == q.front().first) {
                        if (location == q.front().second)
                                return answer;
                        else {
                                ++answer;
                                ++priorIdx;
                                q.pop();
                        }
                }
                else {
                        q.push(q.front());
                        q.pop();
                }
        }

        return answer;
}