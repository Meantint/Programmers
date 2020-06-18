#include <bits/stdc++.h>

#define PDI pair<double, int>

using namespace std;

bool compare(const PDI& v1, const PDI& v2)
{
        if (v1.first == v2.first)
                return v1.second < v2.second;
        else
                return v1.first > v2.first;
}

vector<int> solution(int N, vector<int> stages)
{
        vector<int> answer;

        vector<int> reachStage(N + 2, 0);
        vector<int> noClear(N + 2, 0);
        int stageSize = stages.size();
        // stages의 0번 원소부터 받아야 함
        for (int i = 0; i < stageSize; ++i) {
                int stage = stages[i];
                for (int j = 1; j < stage + 1; ++j) {
                        ++reachStage[j];
                }
                ++noClear[stage];
        }

        vector<PDI> vec;
        for (int i = 1; i < N + 1; ++i) {
                // 아무도 깬 사람이 없다면 실패율 1
                if (noClear[i] == 0)
                        vec.push_back(make_pair(0, i));
                else {
                        vec.push_back(make_pair((double)noClear[i] / (double)reachStage[i], i));
                }
        }
        sort(vec.begin(), vec.end(), compare);
        int vecSize = vec.size();
        for (int i = 0; i < vecSize; ++i) {
                answer.push_back(vec[i].second);
        }

        return answer;
}