#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 100000000

using namespace std;

int gb_n;
int ans = 0;
vector<vector<int>> adj;
vector<bool> isVisited;

void floyd()
{
    for (int i = 0; i < gb_n; ++i) {
        adj[i][i] = 0;
    }
    for (int k = 0; k < gb_n; ++k) {
        for (int i = 0; i < gb_n; ++i) {
            for (int j = 0; j < gb_n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
void bfsAll()
{
    for (int i = 0; i < gb_n; ++i) {
        if (isVisited[i] == false) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (isVisited[cur]) continue;
                isVisited[cur] = true;
                for (int j = 0; j < gb_n; ++j) {
                    if (adj[cur][j] != 0) {
                        q.push(j);
                    }
                }
            }
            ++ans;
        }
    }
}
int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    gb_n = n;
    isVisited = vector<bool>(gb_n, false);
    adj = computers;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == 0) {
                adj[i][j] = INF;
            }
        }
    }

    floyd();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == INF) adj[i][j] = 0;
            // cout << adj[i][j] << ' ';
        }
        // cout << '\n';
    }
    bfsAll();
    answer = ans;

    return answer;
}