#include <bits/stdc++.h>

using namespace std;

long long solution(long long n)
{
        long long answer = 0;

        // sqrt(n) 값을 int로 바꿔줘야 소수점 부분이 버려지므로
        // 값이 다르게 나와서 제곱수 유무를 올바르게 판단할 수 있다.
        if (pow((int)sqrt(n), 2) == n) {
                answer = pow(sqrt(n) + 1, 2);
        }
        else
                answer = -1;

        return answer;
}