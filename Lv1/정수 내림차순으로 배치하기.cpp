#include <bits/stdc++.h>

using namespace std;

long long solution(long long n)
{
        long long answer = 0;

        string str;
        while (n != 0) {
                int num = n % 10;
                n /= 10;
                str += to_string(num);
        }
        sort(str.begin(), str.end(), greater<char>());
        answer = stoll(str);

        return answer;
}