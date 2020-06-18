#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(int x, int n)
{
        vector<long long> answer;

        long long cp = x;
        for (int i = 0; i < n; ++i) {
                answer.push_back(cp);
                cp += x;
        }

        return answer;
}