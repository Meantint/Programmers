#include <string>
#include <vector>

using namespace std;

int gcd(int n1, int n2)
{
    // n2 > n1이라면 값을 바꿔준다.
    if (n2 > n1) swap(n1, n2);

    // 나누어 떨어진다면 n2를 리턴
    if (n1 % n2 == 0) return n2;
    // 아니라면 재귀호출
    else {
        return gcd(n2, n1 % n2);
    }
}

vector<int> solution(int n, int m)
{
    vector<int> answer;

    // answer에 최대공약수 넣음
    answer.push_back(gcd(n, m));
    answer.push_back((n / answer[0]) * m);

    return answer;
}