#include <string>
#include <vector>

using namespace std;

void find_idx(string str, int& start, int& k)
{
    int maxIdx = start;
    for (int i = 0; i <= k; ++i) {
        if (start + i >= str.size()) {
            break;
        }
        if (str[start + i] > str[maxIdx]) {
            maxIdx = start + i;
        }
    }
    k -= maxIdx - start;
    start = maxIdx;

    return;
}

string solution(string number, int k)
{
    int idx = 0;
    string answer = "";

    // k가 0이 될 때까지 혹은 idx >= number.size()가 될 때까지 while문 실행
    while (k != 0 && idx < number.size()) {
        find_idx(number, idx, k);
        answer += number[idx];
        ++idx;
    }
    // 남은 뒤의 숫자들을 붙여준다.
    while (idx < number.size()) {
        answer += number[idx];
        ++idx;
    }
    // k가 남아있다면 뒤에서부터 지워준다.
    while (k != 0) {
        answer.pop_back();
        --k;
    }

    return answer;
}