#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers)
{
        vector<int> answer;

        vector<int> cnt(3, 0); // cnt[0] ~ cnt[2] : 1번 수포자 ~ 3번 수포자
        vector<int> vec1 = { 1, 2, 3, 4, 5 };
        vector<int> vec2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
        vector<int> vec3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
        int size = answers.size();
        for (int i = 0; i < size; ++i) {
                if (vec1[i % 5] == answers[i])
                        ++cnt[0];
                if (vec2[i % 8] == answers[i])
                        ++cnt[1];
                if (vec3[i % 10] == answers[i])
                        ++cnt[2];
        }

        // 제일 점수가 높은 사람을 answer에 넣는다.
        answer.push_back(1);
        // 2번 수포자 확인
        if (cnt[answer.back() - 1] < cnt[1]) {
                answer.back() = 2;
        }
        else if (cnt[answer.back() - 1] == cnt[1]) {
                answer.push_back(2);
        }
        // 3번 수포자 확인
        if (cnt[answer.back() - 1] < cnt[2]) {
                answer.clear();
                answer.push_back(3);
        }
        else if (cnt[answer.back() - 1] == cnt[2]) {
                answer.push_back(3);
        }
        return answer;
}