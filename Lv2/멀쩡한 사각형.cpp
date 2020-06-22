#include <bits/stdc++.h>

using namespace std;

int gcd(int num1, int num2)
{
        if (num1 % num2 == 0)
                return num2;
        else
                return gcd(num2, num1 % num2);
}

long long solution(int w, int h)
{
        long long answer = 1;

        int g = (w > h) ? gcd(w, h) : gcd(h, w);
        long long copy_w = w / g;
        long long copy_h = h / g;
        answer = (long long)w * (long long)h - (copy_w + copy_h - 1) * (long long)g;

        return answer;
}