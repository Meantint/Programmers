#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
        vector<int> fibo;
        fibo.push_back(0);
        fibo.push_back(1);
        for (int i = 2; i < n + 1; ++i) {
                fibo.push_back((fibo[i - 1] + fibo[i - 2]) % 1234567);
        }

        return fibo[n];
}