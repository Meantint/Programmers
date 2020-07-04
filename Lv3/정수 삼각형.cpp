#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle)
{
        int answer = 0;

        int row = triangle.size();
        for (int i = 1; i < row; ++i) {
                for (int j = 0; j < i + 1; ++j) {
                        if (j == 0) {
                                triangle[i][0] += triangle[i - 1][0];
                                continue;
                        }
                        else if (j == i) {
                                triangle[i][j] += triangle[i - 1][j - 1];
                                continue;
                        }
                        else {
                                triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
                                continue;
                        }
                }
        }
        for (int i = 0; i < row; ++i) {
                answer = max(answer, triangle[row - 1][i]);
        }

        return answer;
}