#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
        bool answer = true;

        int size = s.size();
        if (size != 4 && size != 6) {
                return false;
        }
        for (int i = 0; i < size; ++i) {
                if (s[i] < '0' || s[i] > '9') {
                        answer = false;
                        break;
                }
        }

        return answer;
}