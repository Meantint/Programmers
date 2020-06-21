#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
        int answer = 0;

        queue<PII> bridge;
        // 현재 무게
        int now_weight = 0;
        // 다리 위 공간 수(다리 길이 - 트럭 수)
        int truckSize = truck_weights.size();
        for (int i = 0; i < truckSize; ++i) {
                // 다음 트럭이 다리에 올라가도 된다면
                if (now_weight + truck_weights[i] <= weight) {
                        // bridge에 올라간 시점 값 저장
                        bridge.push(make_pair(i, ++answer));
                        now_weight += truck_weights[i];
                        //++answer;
                }
                // 다음 트럭이 다리에 못 올라간다면
                else {
                        answer = bridge_length + bridge.front().second - 1;
                        now_weight -= truck_weights[bridge.front().first];
                        bridge.pop();
                        --i;
                }
                // bridge의 마지막 위치에 있다면
                if (bridge.front().second + bridge_length - 1 == answer) {
                        now_weight -= truck_weights[bridge.front().first];
                        bridge.pop();
                }
        }
        answer = bridge.back().second + bridge_length;

        return answer;
}