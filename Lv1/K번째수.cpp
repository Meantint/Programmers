#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
        vector<int> answer;

        int cmdSize = commands.size();
        for (int i = 0; i < cmdSize; ++i) {
                vector<int> vec;
                for (int j = commands[i][0] - 1; j < commands[i][1]; ++j) {
                        vec.push_back(array[j]);
                }
                sort(vec.begin(), vec.end());
                answer.push_back(vec[commands[i][2] - 1]);
        }

        return answer;
}