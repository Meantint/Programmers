#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land)
{
        int answer = 0;

        int size = land.size();
        for (int i = 1; i < size; ++i) {
                for (int j = 0; j < 4; ++j) {
                        land[i][j] += max({ land[i - 1][(j + 1) % 4], land[i - 1][(j + 2) % 4], land[i - 1][(j + 3) % 4] });
                }
        }
        answer = max({ land[size - 1][0], land[size - 1][1], land[size - 1][2], land[size - 1][3] });
        return answer;
}