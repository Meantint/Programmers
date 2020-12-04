#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int bal = 0;
    for (auto& elem : s) {
        if (elem == '(') {
            ++bal;
        }
        // elem == ')'
        else {
            --bal;
        }
        // bal이 음수로 내려간 적이 있다면 올바른 괄호가 될 수 없다.
        if (bal < 0) {
            answer = false;
            break;
        }
    }
    // 좌우 괄호의 개수가 맞지 않으면 올바른 괄호가 될 수 없다.
    if (bal != 0) {
        answer = false;
    }

    return answer;
}