#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b)
{
        long long answer = 0;

        long long cnt = abs(a - b) + 1;
        long long sum = a + b;
        answer = sum * (cnt / 2);
        // 개수가 홀수개라면
        if (cnt % 2 == 1)
                answer += sum / 2;

        return answer;
}