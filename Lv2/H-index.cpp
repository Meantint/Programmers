#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations)
{
        int answer = 0;

        sort(citations.begin(), citations.end());
        int size = citations.size();
        int h = 0;
        while (1) {
                bool isFull = true; // for문을 break없이 다 돌았을 떄 true
                for (int i = 0; i < size; ++i) {
                        if (citations[i] >= h) {
                                // h번 이상 인용된 논문이 h편 이상이라면
                                if (h <= size - i) {
                                        answer = h;
                                        ++h;
                                        isFull = false;
                                        break;
                                }
                                else {
                                        return answer;
                                }
                        }
                }
                if (isFull)
                        return answer;
        }
}