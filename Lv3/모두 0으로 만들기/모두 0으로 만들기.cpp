#include <string>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> global_a;
vector<bool> isVisited;
long long answer;

long long dfs(int node)
{
    long long ret = global_a[node];

    isVisited[node] = true;

    int visitCount = 0;
    long long visitSum = 0;
    for (int next : adj[node]) {
        if (isVisited[next]) {
            continue;
        }

        ++visitCount;
        visitSum += dfs(next);
    }

    if (visitCount != 0) {
        ret += visitSum;
    }

    answer += (ret < 0 ? (ret * -1) : ret);

    return ret;
}

void solve(vector<int> a, vector<vector<int>> edges)
{
    adj = vector<vector<int>>(a.size());
    isVisited = vector<bool>(a.size(), false);
    global_a = a;

    for (vector<int> edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    dfs(0);
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    int sum = 0;
    int aSize = a.size();
    for (int i = 0; i < aSize; ++i) {
        sum += a[i];
    }
    if (sum == 0) {
        answer = 0;
        solve(a, edges);
    }
    else {
        answer = -1;
    }

    return answer;
}