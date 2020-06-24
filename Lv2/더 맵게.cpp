#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K)
{
        int answer = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        int size = scoville.size();
        for (int i = 0; i < size; ++i) {
                pq.push(scoville[i]);
        }
        do {
                if (pq.size() == 1) {
                        return -1;
                }
                int num1 = pq.top();
                pq.pop();
                int num2 = pq.top();
                pq.pop();
                pq.push(num1 + num2 * 2);
                ++answer;
        } while (pq.top() < K);

        return answer;
}