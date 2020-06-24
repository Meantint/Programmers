#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k)
{
        string answer = "";

        int size = number.size();
        for (int i = 0; i < size; ++i) {
                int maxIdx = i;
                for (int j = 1; j <= k; ++j) {
                        if (i + j >= size)
                                break;
                        if (number[i + j] > number[maxIdx]) {
                                maxIdx = i + j;
                        }
                }
                answer += number[maxIdx];
                k -= (maxIdx - i);
                i = maxIdx;
                if (k == 0) {
                        if (maxIdx + 1 < size)
                                answer += number.substr(maxIdx + 1);
                        break;
                }
                if (answer.size() == number.size() - k) {
                        break;
                }
        }

        return answer;
}