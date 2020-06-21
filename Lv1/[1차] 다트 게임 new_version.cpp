#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult)
{
        int answer = 0;

        vector<int> score;
        int dartSize = dartResult.size();
        int num = 0;
        for (int i = 0; i < dartSize; ++i) {
                if (dartResult[i] >= '0' && dartResult[i] <= '9') {
                        num *= 10;
                        num += (dartResult[i] - '0');
                }
                else if (dartResult[i] == 'S') {
                        score.push_back(num);
                        num = 0;
                }
                else if (dartResult[i] == 'D') {
                        num = pow(num, 2);
                        score.push_back(num);
                        num = 0;
                }
                else if (dartResult[i] == 'T') {
                        num = pow(num, 3);
                        score.push_back(num);
                        num = 0;
                }
                else if (dartResult[i] == '*') {
                        score.back() *= 2;
                        // score의 size가 2 이상이라면
                        if (score.size() > 1) {
                                score[score.size() - 2] *= 2;
                        }
                }
                else if (dartResult[i] == '#') {
                        score.back() *= -1;
                }
        }
        int scoreSize = score.size();
        for (int i = 0; i < scoreSize; ++i) {
                answer += score[i];
        }

        return answer;
}