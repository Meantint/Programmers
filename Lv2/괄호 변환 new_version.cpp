#include <bits/stdc++.h>

using namespace std;

string gwalho(string u, string v)
{
        string rtn = "";
        if (u.empty())
                return rtn;

        bool isGood = true;
        int bal = 0;
        int size = u.size();
        string new_u = "";
        string new_v = "";
        for (int i = 0; i < size; ++i) {
                if (u[i] == '(')
                        --bal;
                else
                        ++bal;
                new_u += u[i];
                if (bal > 0)
                        isGood = false;
                if (bal == 0) {
                        new_v = u.substr(i + 1);
                        break;
                }
        }
        // 좋은 괄호라면
        if (isGood) {
                rtn += new_u;
                rtn += gwalho(new_v, "");
                return rtn;
        }
        else {
                rtn += '(';
                rtn += gwalho(new_v, "");
                rtn += ')';
                int size = new_u.size();
                for (int i = 1; i < size - 1; ++i) {
                        if (new_u[i] == '(')
                                rtn += ')';
                        else
                                rtn += '(';
                }
                return rtn;
        }
}

string solution(string p)
{
        string answer = "";

        answer += gwalho(p, "");

        return answer;
}