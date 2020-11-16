#include <string>
#include <vector>

using namespace std;

int cnt = 0;
long long n;

int solution(int num)
{
    int answer = 0;

    n = (long long)num;
    while (n != 1) {
        if (cnt == 500) {
            answer = -1;
            break;
        }
        ++cnt;
        (n % 2 == 0) ? n /= 2 : n = (n * 3 + 1);
    }
    // 만약 cnt가 500을 넘어 answer가 -1이 된 것이 아니라면
    if (answer != -1) {
        answer = cnt;
    }

    return answer;
}