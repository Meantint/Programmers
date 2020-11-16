#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    // n의 제곱근의 소숫점을 버린 후 제곱한 것이 기존의 n과 같다면 어떤 양의 정수 x의 제곱이다.
    if (n == pow((int)sqrt(n), 2)) {
        answer = pow((int)sqrt(n) + 1, 2);
    }
    // x의 제곱이 아니다.
    else {
        answer = (long long)-1;
    }

    return answer;
}