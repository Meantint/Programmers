#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    string str = "";
    while (n != 0) {
        str.push_back(n % 10 + '0');
        n /= 10;
    }
    // 내림차순 정렬
    sort(str.begin(), str.end(), greater<char>());
    for (auto& s : str) {
        answer *= (long long)10;
        answer += (long long)(s - '0');
    }

    return answer;
}