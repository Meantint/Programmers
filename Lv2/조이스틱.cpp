#include <bits/stdc++.h>

using namespace std;

int solution(string name)
{
        int answer = 0;

        int nameSize = name.size();
        for (int i = 0; i < nameSize; ++i) {
                // 문자 옮기는 횟수 저장
                int cnt = name[i] - 'A';
                if (cnt > 13) {
                        answer += (26 - cnt);
                }
                else
                        answer += cnt;
        }
        int minCnt = 100;
        for (int i = 1; i < nameSize; ++i) {
                int frontCnt = 0;
                int backCnt = 0;
                int zeroCnt = 0;
                if (name[i] == 'A') {
                        frontCnt = i - 1;
                        ++zeroCnt;
                        while (i + 1 < nameSize && name[i + 1] == 'A') {
                                ++zeroCnt;
                                ++i;
                        }
                        backCnt = nameSize - (frontCnt + 1 + zeroCnt);
                        int moveCnt = (frontCnt >= backCnt) ? (backCnt * 2 + frontCnt) : (frontCnt * 2 + backCnt);
                        minCnt = min(minCnt, moveCnt);
                }
        }
        minCnt = min(minCnt, nameSize - 1);
        answer += minCnt;

        return answer;
}