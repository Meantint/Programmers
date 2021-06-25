# 프로그래머스 - 모두 0으로 만들기

&nbsp;DFS를 통해서 단말노드부터 처리하면서 진행하면 된다. `dfs` 함수를 실행시킬 때 시작 노드는 아무 노드에서나 시작해도 되는데 어느 노드에서 시작해도 그 노드를 루트 노드처럼 만들 수 있기 때문이다.

- Programmers - [모두 0으로 만들기](https://programmers.co.kr/learn/courses/30/lessons/76503)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `a` 배열의 모든 합이 `0`이 아니라면 절대 모두 `0`으로 만들 수 없기 때문에 `answer = -1`를 바로 리턴해준다.

- 간선의 정보를 저장하는 리스트인 `vector<vector<int>>` 변수 `adj`를 만들어준다.

- 단말노드라면 현재 노드가 가지고 있는 절대값만큼 `answer`에 더해준다.

  - 양방향 노드이지만 `isVisited`를 사용하면서 이미 방문한 노드는 다시 방문하지 않기 때문에 다음 방문할 곳이 하나도 없다면 단말노드라고 칭하였다.

  - 단말노드인지를 확인하려면 `visitCount = 0`이 참인지 거짓인지를 판별해주면 된다.

- 단말노드가 아니라면 재귀적으로 `dfs` 함수를 실행하여 현재 위치에서 방문할 수 있는 모든 노드들의 가중치를 `0`으로 만들면서 생긴 처리량 `visitSum`을 현재의 노드에 더해준다.

- 현재의 노드 가중치 역시 `0`으로 만들어줘야 하기 때문에 현재 가중치의 절대값을 `answer`에 더해주고 현재 값을 반환해준다.

- 모든 `dfs` 함수 동작이 끝났을 때의 `answer` 값이 문제의 정답이다.

## Code

```cpp
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
```
