#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
        string answer = "";

        int size = s.size();
        int strIdx = 0;
        for (int i = 0; i < size; ++i) {
                if (s[i] != ' ') {
                        if (strIdx % 2 == 0 && s[i] >= 'a' && s[i] <= 'z')
                                s[i] -= 32;
                        else if (strIdx % 2 == 1 && s[i] >= 'A' && s[i] <= 'Z')
                                s[i] += 32;
                        ++strIdx;
                }
                // 초기화 시킴
                else if (s[i] == ' ') {
                        strIdx = 0;
                }
        }
        answer = s;

        return answer;
}