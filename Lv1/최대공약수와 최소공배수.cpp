#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
        if (x % y == 0)
                return y;
        else
                return gcd(y, x % y);
}

vector<int> solution(int n, int m)
{
        vector<int> answer;

        answer.push_back((n >= m) ? gcd(n, m) : gcd(m, n));
        answer.push_back(n / answer[0] * m);

        return answer;
}