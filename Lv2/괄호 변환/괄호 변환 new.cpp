#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(string w)
{
    if (w.size() == 0) {
        return "";
    }
    bool isGood = false;
    int bal = 0;

    string u = "", v = "";
    int size = w.size();
    for (int i = 0; i < size; ++i) {
        if (w[i] == '(') {
            ++bal;
            if (i == 0) {
                isGood = true;
            }
        }
        else {
            --bal;
        }

        if (bal == 0) {
            u = w.substr(0, i + 1);
            if (i + 1 < w.size())
                v = w.substr(i + 1);
            break;
        }
    }
    // 올바른 괄호 문자열이라면
    if (isGood) {
        return u + solve(v);
    }
    else {
        string tmp = "(";
        tmp += solve(v);
        tmp += ')';
        int uSize = u.size();
        for (int i = 1; i < uSize - 1; ++i) {
            if (u[i] == '(') {
                tmp += ')';
            }
            else {
                tmp += '(';
            }
        }
        return tmp;
    }
}

string solution(string p)
{
    string answer = "";

    answer = solve(p);

    return answer;
}

// int main()
// {
//     cout << solution("(()())()") << '\n';
//     cout << solution(")(") << '\n';
//     cout << solution("()))((()") << '\n';
//     cout << solution("))(()(") << '\n';

//     return 0;
// }