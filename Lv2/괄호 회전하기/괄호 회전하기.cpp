#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int size = s.size();

    string tmp = s;
    for (int i = 0; i < size; ++i) {
        stack<char> s;

        for (int j = 0; j < size; ++j) {
            if (tmp[j] == '(' || tmp[j] == '{' || tmp[j] == '[') {
                s.push(tmp[j]);
            }
            else if (tmp[j] == ']' && !s.empty() && s.top() == '[') {
                s.pop();
            }
            else if (tmp[j] == ')' && !s.empty() && s.top() == '(') {
                s.pop();
            }
            else if (tmp[j] == '}' && !s.empty() && s.top() == '{') {
                s.pop();
            }
            else {
                s.push('$');
                break;
            }
        }
        if (s.empty()) {
            ++answer;
        }
        tmp = tmp.substr(1) + tmp[0];
    }

    return answer;
}