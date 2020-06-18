#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
        int rowSize = arr1.size();
        int columnSize = arr1[0].size();
        vector<vector<int>> answer(rowSize, vector<int>(columnSize, 0));
        for (int i = 0; i < rowSize; ++i) {
                for (int j = 0; j < columnSize; ++j) {
                        answer[i][j] = arr1[i][j] + arr2[i][j];
                }
        }

        return answer;
}