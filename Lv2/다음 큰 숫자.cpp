#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
        int answer = 0;

        vector<int> vec(20, 0);
        for (int i = 19; i >= 0; --i) {
                int val = pow(2, i);
                if (val <= n) {
                        vec[i] = 1;
                        n -= val;
                }
        }
        int pushCnt = 0; // 다시 넣어줘야 하는 1의 개수
        for (int i = 0; i < 20; ++i) {
                if (vec[i] == 0)
                        continue;
                if (vec[i + 1] == 1) {
                        vec[i] = 0;
                        ++pushCnt;
                        continue;
                }
                vec[i + 1] = 1;
                vec[i] = 0;
                int idx = 0;
                while (pushCnt != 0) {
                        vec[idx] = 1;
                        ++idx;
                        --pushCnt;
                }
                break;
        }
        for (int i = 0; i < 20; ++i) {
                if (vec[i] == 1)
                        answer += pow(2, i);
        }

        return answer;
}