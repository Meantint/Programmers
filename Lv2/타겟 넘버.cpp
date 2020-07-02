#include <bits/stdc++.h>

using namespace std;

int answer = 0;
vector<int> maxVal; // numbers의 누적 값을 저장하는 vector
vector<int> copyVec; // numbers의 copy vector
int copyTarget; // target의 copy

// isPlus가 true이면 nowValue에 값을 더함, false면 nowValue에 값을 뺀다.
void dfs(int idx, bool isPlus, int nowValue)
{
        if (nowValue + maxVal[idx] >= copyTarget && nowValue - maxVal[idx] <= copyTarget) {
                if (isPlus)
                        nowValue += copyVec[idx];
                else
                        nowValue -= copyVec[idx];
                if (idx + 1 == copyVec.size()) {
                        if (nowValue == copyTarget) {
                                ++answer;
                                return;
                        }
                        return;
                }
                else {
                        dfs(idx + 1, true, nowValue);
                        dfs(idx + 1, false, nowValue);
                }
        }
        return;
}

int solution(vector<int> numbers, int target)
{
        int size = numbers.size();
        maxVal.resize(numbers.size());
        maxVal.back() = numbers.back();
        for (int i = size - 2; i >= 0; --i) {
                maxVal[i] = maxVal[i + 1] + numbers[i];
        }
        copyVec = numbers;
        copyTarget = target;

        dfs(0, true, 0);
        dfs(0, false, 0);

        return answer;
}