#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
        vector<int> answer;

        if (arr.size() == 1) {
                answer.push_back(-1);
                return answer;
        }
        else {
                int minIdx = 0;
                int minVal = arr[0];
                int arrSize = arr.size();
                // 가장 작은 값의 index값을 저장해놓는다.
                for (int i = 1; i < arrSize; ++i) {
                        if (minVal > arr[i]) {
                                minVal = arr[i];
                                minIdx = i;
                        }
                }
                // 가장 작은 값의 index를 제외한 나머지를 answer에 넣음
                for (int i = 0; i < arrSize; ++i) {
                        if (i != minIdx) {
                                answer.push_back(arr[i]);
                        }
                }
        }

        return answer;
}