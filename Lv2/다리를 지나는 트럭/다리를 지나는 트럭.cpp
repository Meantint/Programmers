#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int bridgeWeight = 0;
    int tSize = truck_weights.size();

    queue<int> q;
    for (int i = 0; i < bridge_length; ++i) {
        q.push(0);
    }
    int idx = 0;
    while (idx < tSize) {
        // 젤 앞의 무게가 빠지고 다음 트럭이 들어왔을 때의 무게가 weight 보다 작다면
        if (bridgeWeight - q.front() + truck_weights[idx] <= weight) {
            bridgeWeight -= q.front();
            bridgeWeight += truck_weights[idx];
            q.push(truck_weights[idx]);
            q.pop();
            ++idx;
        }
        else {
            q.push(0);
            bridgeWeight -= q.front();
            q.pop();
        }
        ++answer;
    }
    // while문을 빠져나왔을 때 상황 : 마지막 트럭이 다리의 시작 부분에 위치해있음
    answer += bridge_length;

    return answer;
}