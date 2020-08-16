#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    int size = arr1.size();
    for (int i = 0; i < size; ++i) {
        int sum = 0;
        int size2 = arr2[0].size();
        for (int j = 0; j < size2; ++j) {
            int size3 = arr1[0].size();
            for (int k = 0; k < size3; ++k) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}