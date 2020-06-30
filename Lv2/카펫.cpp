#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow)
{
        vector<int> answer;

        int test = brown / 2;
        for (int i = 1; i <= test; ++i) {
                int col = i + 1;
                int row = test - i + 1;
                if (col * row == brown + yellow) {
                        answer.push_back(row);
                        answer.push_back(col);

                        return answer;
                }
        }

        return answer;
}