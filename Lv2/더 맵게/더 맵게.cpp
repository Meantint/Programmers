#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& s : scoville) {
        pq.push(s);
    }
    while (pq.size() > 1 && pq.top() < K) {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();

        pq.push(s1 + s2 * 2);
        ++answer;
    }
    if (pq.size() == 1 && pq.top() < K) {
        answer = -1;
    }

    return answer;
}