#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1001;

    int size = s.size();
    int searchSize = size / 2;
    for (int i = 1; i <= searchSize; ++i) {
        int sameCnt = 1;
        string tmp = "";
        string prev = "";
        int j;
        for (j = 0; j + i - 1 < size; j += i) {
            string cur = s.substr(j, i);
            // 이번에 탐색한 문자와 이전에 탐색한 문자와 일치할 때
            if (cur == prev) {
                ++sameCnt;
            }
            else {
                // 하나밖에 없었다면 숫자를 붙일 필요가 없다.
                if (sameCnt == 1) {
                    tmp += prev;
                    prev = cur;
                }
                // 2개 이상이었다면
                else {
                    tmp += (to_string(sameCnt) + prev);
                    prev = cur;
                    sameCnt = 1;
                }
            }
        }
        if (sameCnt != 1) {
            tmp += (to_string(sameCnt) + prev);
        }
        else {
            tmp += prev;
        }
        tmp += s.substr(j);
        // 압축 완료 후의 길이가 현재 answer 값 보다 작다면 교체
        if (tmp.size() < answer) {
            answer = tmp.size();
        }
    }
    // 예외 : s.size()가 1인 경우
    if (size == 1) {
        answer = 1;
    }

    return answer;
}