#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;

    long long cx = x;  // 계속 x만큼 더해줄 변수 생성
    for (int i = 0; i < n; ++i) {
        answer.push_back(cx);
        cx += (long long)x;
    }

    return answer;
}