#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        // n이 i로 나누어 떨어진다면
        if (n % i == 0) {
            answer += i;
        }
    }

    return answer;
}