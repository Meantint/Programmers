#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    while (n != 0) {
        // 3으로 나누어 떨어진다면
        if (n % 3 == 0) {
            answer = '4' + answer;
            n -= 3;
            n /= 3;
        }
        else {
            answer = to_string(n % 3) + answer;
            n /= 3;
        }
    }

    return answer;
}