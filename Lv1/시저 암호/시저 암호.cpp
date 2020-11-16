#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";

    for (auto &c : s) {
        // 소문자라면
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + n) % 26 + 'a';
        }
        // 대문자라면
        else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + n) % 26 + 'A';
        }
        // 공백이라면
        else if (c == ' ') {
            continue;
        }
    }
    answer = s;

    return answer;
}