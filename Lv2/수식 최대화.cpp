#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<long long> num;
string oper;

long long cal(string op1, string op2, string op3)
{
    string order = op1 + op2 + op3;

    vector<long long> tmp1, tmp2;
    string oper1, oper2 = "";
    tmp1 = num;
    oper1 = oper;

    int idx = 0;
    while (idx < 3) {
        int size = tmp1.size();
        int operSize = oper1.size();
        bool befCal = false;  // 이전에 계산했다면 true
        for (int i = 0; i < operSize; ++i) {
            if (!befCal) {
                tmp2.push_back(tmp1[i]);
            }
            befCal = false;

            if (oper1[i] == order[idx]) {
                long long tmp;
                tmp = tmp2.back();
                tmp2.pop_back();

                if (order[idx] == '*') {
                    tmp2.push_back(tmp * tmp1[i + 1]);
                }
                else if (order[idx] == '+') {
                    tmp2.push_back(tmp + tmp1[i + 1]);
                }
                else if (order[idx] == '-') {
                    tmp2.push_back(tmp - tmp1[i + 1]);
                }
                befCal = true;
            }
            else {
                // tmp2.push_back(tmp1[i]);
                oper2.push_back(oper1[i]);
                if (i == operSize - 1) {
                    tmp2.push_back(tmp1[i + 1]);
                }
            }
        }
        tmp1 = tmp2;
        oper1 = oper2;
        // cout << idx << ", " << oper2 << '\n';
        // for (int i = 0; i < tmp1.size(); ++i) {
        //     cout << tmp1[i] << ' ';
        // }
        // cout << '\n';
        if (tmp2.size() == 1) {
            break;
        }
        tmp2.clear();
        oper2.clear();
        ++idx;
    }

    return tmp1[0];
}

long long solution(string expression)
{
    long long answer = 0;

    int n = 0;
    int size = expression.size();
    for (int i = 0; i < size; ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            n *= 10;
            n += expression[i] - '0';
            continue;
        }
        num.push_back(n);
        n = 0;
        oper += expression[i];
    }
    num.push_back(n);

    // cout << '\n';

    answer = max(answer, abs(cal("*", "+", "-")));
    answer = max(answer, abs(cal("*", "-", "+")));
    answer = max(answer, abs(cal("+", "*", "-")));
    answer = max(answer, abs(cal("+", "-", "*")));
    answer = max(answer, abs(cal("-", "*", "+")));
    answer = max(answer, abs(cal("-", "+", "*")));

    return answer;
}

// int main()
// {
// cout << solution("100-200*300-500+20") << '\n';
// cout << solution("50*6-3*2") << '\n';
//
// return 0;
// }