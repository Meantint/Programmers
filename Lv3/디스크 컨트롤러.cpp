#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

struct cmp {
    bool operator()(PII p1, PII p2)
    {
        return p1.second > p2.second;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, idx = 0, time = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<PII, vector<PII>, cmp> pq;

    int size = jobs.size();
    while (!pq.empty() || idx < size) {
        if (idx < size && jobs[idx][0] <= time) {
            pq.push(make_pair(jobs[idx][0], jobs[idx][1]));
            ++idx;
            continue;
        }
        if (!pq.empty()) {
            time += pq.top().second;
            answer += time - pq.top().first;
            pq.pop();
        }
        else {
            time = jobs[idx][0];
        }
    }
    answer /= size;

    return answer;
}

int main()
{
    cout << solution({ { 0, 3 }, { 1, 9 }, { 2, 6 } }) << endl;

    return 0;
}