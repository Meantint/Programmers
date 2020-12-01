#include <string>
#include <vector>

using namespace std;

string solve(string w)
{
    // 빈 문자열인 경우
    if (w == "") {
        return "";
    }
    // u, v로 분리
    bool isGood = true;
    int bal = 0;
    string u = "", v = "";
    for (int i = 0; i < w.size(); ++i) {
        if (w[i] == '(') {
            u += '(';
            ++bal;
        }
        else {
            u += ')';
            --bal;
        }
        if (bal == 0) {
            v = w.substr(i + 1);
            break;
        }
        // bal이 음수가 되는 순간 올바른 괄호 문자열이 될 수 없음
        else if (bal < 0) {
            isGood = false;
        }
    }
    // 올바른 괄호 문자열이라면
    if (isGood) {
        return u + solve(v);
    }
    // 올바른 괄호 문자열이 아니라면
    else {
        string tmp = "(";
        tmp += solve(v);
        tmp += ')';

        for (int i = 1; i < u.size() - 1; ++i) {
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