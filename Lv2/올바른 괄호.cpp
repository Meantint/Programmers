#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
        bool isDone = true;

        string str = "";
        int size = s.size();
        for (int i = 0; i < size; ++i) {
                if (s[i] == '(') {
                        str += s[i];
                }
                else if (s[i] == ')') {
                        if (str.empty())
                                return false;
                        str.pop_back();
                }
        }

        if (isDone) {
                if (!str.empty())
                        return false;
                return true;
        }
}