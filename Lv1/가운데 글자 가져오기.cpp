#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
        string answer = "";

        // 짝수라면
        if (s.size() % 2 == 0) {
                answer.push_back(s[s.size() / 2 - 1]);
                answer.push_back(s[s.size() / 2]);
        }
        else {
                answer = s[s.size() / 2];
        }

        return answer;
}