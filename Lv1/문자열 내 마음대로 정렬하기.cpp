#include <bits/stdc++.h>

using namespace std;

int idx = 0;
bool compare(const string& s1, const string& s2)
{
        if (s1[idx] == s2[idx]) {
                return s1 < s2;
        }
        return s1[idx] < s2[idx];
}

vector<string> solution(vector<string> strings, int n)
{
        vector<string> answer;
        idx = n;

        sort(strings.begin(), strings.end(), compare);
        answer = strings;

        return answer;
}