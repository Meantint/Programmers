#include <string>
#include <vector>

using namespace std;

vector<bool> prime;

int solution(int n)
{
    int answer = 0;

    prime = vector<bool>(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        // i가 소수가 아니라면 다음 숫자로 넘어간다.
        if (!prime[i]) continue;
        // i를 제외한 i의 배수들을 모두 false로 바꿔준다.
        for (int j = i * 2; j <= n; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        // prime[i] = true라면 카운트를 올려준다.
        if (prime[i]) ++answer;
    }

    return answer;
}