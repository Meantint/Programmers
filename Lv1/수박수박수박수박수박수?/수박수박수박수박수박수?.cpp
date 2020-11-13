#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    for (int i = 0; i < n; ++i) {
        // 짝수라면 '수'
        if (i % 2 == 0) {
            answer += "수";
        }
        // 홀수라면 '박'
        else {
            answer += "박";
        }
    }

    return answer;
}