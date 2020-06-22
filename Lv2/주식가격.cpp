#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

vector<int> solution(vector<int> prices)
{
        vector<int> answer;

        vector<PII> vec;
        int size = prices.size();
        for (int i = 0; i < size; ++i) {
                bool isCheck = false;
                for (int j = i; j < size; ++j) {
                        if (prices[i] > prices[j]) {
                                answer.push_back(j - i);
                                isCheck = true;
                                break;
                        }
                }
                if (!isCheck) {
                        answer.push_back(size - i - 1);
                }
        }

        return answer;
}