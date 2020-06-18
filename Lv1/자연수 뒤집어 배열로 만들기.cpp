#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long n)
{
        vector<int> answer;

        while (n != 0) {
                int num = n % 10;
                n /= 10;
                answer.push_back(num);
        }

        return answer;
}