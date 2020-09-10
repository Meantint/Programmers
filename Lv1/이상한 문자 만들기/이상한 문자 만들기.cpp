#include <string>

using namespace std;

string solution(string s)
{
    // 단어의 index를 저장하는 변수
    int strIdx = 0;
    int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (s[i] == ' ') {
            strIdx = 0;
        }
        else {
            // 짝수 index라면
            if (strIdx % 2 == 0) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
            }
            // 홀수 index라면
            else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
            ++strIdx;
        }
    }

    return s;
}