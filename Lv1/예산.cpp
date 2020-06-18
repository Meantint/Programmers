#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget)
{
        int answer = 0;

        int size = d.size();
        sort(d.begin(), d.end());
        for (int i = 0; i < size; ++i) {
                if (budget - d[i] >= 0) {
                        ++answer;
                        budget -= d[i];
                }
                else
                        break;
        }

        return answer;
}