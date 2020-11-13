#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    // 홀수
    if (s.size() % 2 == 1) {
        answer += s[s.size() / 2];
    }
    // 짝수
    else {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }

    return answer;
}