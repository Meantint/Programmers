#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
        int answer = 0;

        vector<int> num(n, 1); // 모두가 한 벌씩 들고 있다고 생각하고 초기화
        int lostSize = lost.size();
        int reserveSize = reserve.size();
        for (int i = 0; i < lostSize; ++i) {
                --num[lost[i] - 1];
        }
        for (int i = 0; i < reserveSize; ++i) {
                ++num[reserve[i] - 1];
        }

        int numSize = num.size();
        for (int i = 0; i < numSize; ++i) {
                if (num[i] == 2) {
                        // idx가 0이 아니고 왼쪽 번호 학생이 옷이 없을 때
                        if (i != 0 && num[i - 1] == 0) {
                                --num[i];
                                ++num[i - 1];
                        }
                        else if (i != numSize && num[i + 1] == 0) {
                                --num[i];
                                ++num[i + 1];
                        }
                }
        }
        for (int i = 0; i < numSize; ++i) {
                if (num[i] > 0)
                        ++answer;
        }

        return answer;
}