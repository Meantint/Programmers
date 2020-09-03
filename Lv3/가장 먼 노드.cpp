#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

vector<int> dist;
vector<vector<int>> vt;
void dfs(int cur, vector<bool> isCheck, int num)
{
    // 이미 방문한 곳이라면
    if (isCheck[cur]) {
        return;
    }
    else {
        if (dist[cur] == 0) {
            dist[cur] = num;
        }
        else if (dist[cur] <= num) {
            return;
        }
        else {
            dist[cur] = num;
        }
        isCheck[cur] = true;
    }
    int size = vt[cur].size();
    for (int i = 0; i < size; ++i) {
        dfs(vt[cur][i], isCheck, num + 1);
    }
    return;
}
void bfs(int cur)
{
    queue<int> q;
    vector<bool> isCheck(vt.size(), false);

    q.push(cur);
    isCheck[cur] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        int size = vt[now].size();
        for (int i = 0; i < size; ++i) {
            int next = vt[now][i];
            if (!isCheck[next]) {
                q.push(next);
                dist[next] = dist[now] + 1;
                isCheck[next] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    vt.resize(n + 1);
    int rowSize = edge.size();
    for (int i = 0; i < rowSize; ++i) {
        vt[edge[i][0]].push_back(edge[i][1]);
        vt[edge[i][1]].push_back(edge[i][0]);
    }
    vector<bool> isCheck(n + 1, false);
    dist.resize(n + 1, 0);
    // isCheck[1] = true;
    // dfs(1, isCheck, 1);
    bfs(1);
    int maxNum = -1;
    // dist 중 최대값을 찾는 for문
    for (int i = 1; i < n + 1; ++i) {
        if (maxNum < dist[i]) {
            maxNum = dist[i];
        }
    }
    // 최대값을 가지는 dist의 원소가 몇 개 인지 찾는 for문
    for (int i = 1; i < n + 1; ++i) {
        if (maxNum == dist[i]) {
            ++answer;
        }
    }
    for (int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return answer;
}

int main()
{
    cout << solution(6,
                     {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}})
         << '\n';

    return 0;
}