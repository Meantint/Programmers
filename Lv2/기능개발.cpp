#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
        vector<int> answer;

        int allCheck = 0; // check된 개수가 isCheck의 size와 같을 때 반복문 종료
        int progSize = progresses.size();
        while (1) {
                int cnt = 0;
                for (int i = allCheck; i < progSize; ++i) {
                        progresses[i] += speeds[i];
                }
                while (allCheck < progSize && progresses[allCheck] >= 100) {
                        ++cnt;
                        ++allCheck;
                }
                if (cnt != 0) {
                        answer.push_back(cnt);
                }
                if (allCheck == progSize)
                        break;
        }

        return answer;
}