#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;

vector<int> solution(vector<string> operations)
{
    int cnt_i = 0, cnt_d = 0;
    int size = operations.size();
    for (int i = 0; i < size; ++i) {
        if (operations[i][0] == 'I') {
            ++cnt_i;
            pq_max.push(stoi(operations[i].substr(2)));
            pq_min.push(stoi(operations[i].substr(2)));
        }
        else {
            ++cnt_d;
            if (operations[i][2] == '1') {
                if (!pq_max.empty()) {
                    pq_max.pop();
                }
            }
            else {
                if (!pq_min.empty()) {
                    pq_min.pop();
                }
            }

            if (cnt_i <= cnt_d) {
                cnt_i = cnt_d = 0;
                while (!pq_max.empty()) {
                    pq_max.pop();
                }
                while (!pq_min.empty()) {
                    pq_min.pop();
                }
            }
        }
    }

    vector<int> answer;
    if (pq_max.empty()) {
        vector<int> tmp = { 0, 0 };
        answer = tmp;
    }
    else {
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }

    return answer;
}

int main()
{
    cout << solution({ "I 16", "D 1" })[0] << ' ' << solution({ "I 16", "D 1" })[1] << '\n';
    cout << solution({ "I 7", "I 5", "I -5", "D -1" })[0] << ' ' << solution({ "I 7", "I 5", "I -5", "D -1" })[1] << '\n';

    return 0;
}