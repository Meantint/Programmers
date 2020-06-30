#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> baseball)
{
        int answer = 0;

        int size = baseball.size();
        for (int i = 1; i < 10; ++i) {
                for (int j = 1; j < 10; ++j) {
                        if (i == j)
                                continue;
                        for (int k = 1; k < 10; ++k) {
                                if (i == k || j == k)
                                        continue;
                                bool isFull = true;
                                // ijk 순서
                                for (int idx = 0; idx < size; ++idx) {
                                        int num = baseball[idx][0];
                                        int strike = 0;
                                        int ball = 0;

                                        // strike, ball 검출
                                        int ball1 = num % 10;
                                        if (ball1 == k)
                                                ++strike;
                                        else if (ball1 == i || ball1 == j)
                                                ++ball;
                                        num /= 10;
                                        int ball10 = num % 10;
                                        if (ball10 == j)
                                                ++strike;
                                        else if (ball10 == i || ball10 == k)
                                                ++ball;
                                        num /= 10;
                                        int ball100 = num % 10;
                                        if (ball100 == i)
                                                ++strike;
                                        else if (ball100 == j || ball100 == k)
                                                ++ball;
                                        if (strike == baseball[idx][1] && ball == baseball[idx][2])
                                                continue;
                                        else {
                                                isFull = false;
                                                break;
                                        }
                                }
                                if (isFull)
                                        ++answer;
                        }
                }
        }

        return answer;
}