#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> land, int height)
{
    int answer = 0;

    int lSize = land.size();
    board = land;
    isVisited = vector<vector<bool>>(lSize, vector<bool>(lSize, false));
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        if (isVisited[cx][cy]) continue;
        isVisited[cx][cy] = true;
        answer += cost;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (ccx < 0 || ccy < 0 || ccx >= lSize || ccy >= lSize) continue;
            if (abs(board[ccx][ccy] - board[cx][cy]) > height) {
                pq.push(make_pair(abs(board[ccx][ccy] - board[cx][cy]), make_pair(ccx, ccy)));
            }
            else {
                pq.push(make_pair(0, make_pair(ccx, ccy)));
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3);
}