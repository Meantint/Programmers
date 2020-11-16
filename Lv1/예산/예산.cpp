#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    sort(d.begin(), d.end());
    for (auto& cost : d) {
        // 비용을 지불할 예산이 있다면
        if (cost <= budget) {
            budget -= cost;
            ++answer;
        }
        // 없다면 break
        else {
            break;
        }
    }

    return answer;
}