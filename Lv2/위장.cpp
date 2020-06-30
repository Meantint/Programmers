#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes)
{
        int answer = 1;

        map<string, int> m;
        int size = clothes.size();
        for (int i = 0; i < size; ++i) {
                if (m.count(clothes[i][1]) == 0)
                        m[clothes[i][1]] = 1;
                else
                        ++m[clothes[i][1]];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
                answer *= (it->second + 1);
        }

        return answer - 1;
}