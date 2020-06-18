#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
        int pCnt = 0;
        int yCnt = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
                if (s[i] == 'p' || s[i] == 'P')
                        ++pCnt;
                if (s[i] == 'y' || s[i] == 'Y')
                        ++yCnt;
        }
        if (pCnt == yCnt)
                return true;
        else
                return false;
}