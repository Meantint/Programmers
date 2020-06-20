#include <algorithm>
#include <string>
#include <vector>

#define PII pair<int, int> // first -> 실패한 사람의 수, second -> 도전한 사람의 수
#define PDI pair<double, int>

using namespace std;

bool comp(const PDI& p1, const PDI& p2)
{
        if (p1.first == p2.first)
                return p1.second < p2.second;
        return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages)
{
        vector<int> answer;

        vector<PII> vec(N + 1, PII(0, 0)); // idx 1부터 시작
        vector<PDI> cal(N + 1, PDI(0, 0));
        for (int i = 0; i < stages.size(); ++i) {
                for (int j = 1; j <= stages[i]; ++j) {
                        if (j == N + 1) {
                                break;
                        }
                        vec[j].second++;
                }
                if (stages[i] != N + 1)
                        vec[stages[i]].first++;
        }

        for (int i = 1; i < vec.size(); ++i) {
                cal[i].first = (double)vec[i].first / (double)vec[i].second;
                cal[i].second = i;
        }

        // stable_sort이냐 일반 sort이냐에 따라 정답이 달랐음(stable_sort일 때가 정답)
        stable_sort(cal.begin(), cal.end(), comp);

        for (int i = 0; i < cal.size(); ++i) {
                if (cal[i].second == 0)
                        continue;
                answer.push_back(cal[i].second);
        }
        return answer;
}