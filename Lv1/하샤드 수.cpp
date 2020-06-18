#include <bits/stdc++.h>

using namespace std;

bool solution(int x)
{
        bool answer = true;

        int saveX = x;
        int sum = 0;
        while (x != 0) {
                int num = x % 10;
                x /= 10;
                sum += num;
        }
        if (saveX % sum == 0)
                answer = true;
        else
                answer = false;

        return answer;
}