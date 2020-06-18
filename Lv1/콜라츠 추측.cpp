#include <bits/stdc++.h>

using namespace std;

int solution(int num)
{
        int answer = 0;
        long long cp = num;

        while (cp != 1) {
                if (cp % 2 == 0)
                        cp /= 2;
                else {
                        cp = cp * 3 + 1;
                }
                ++answer;
                if (answer == 500)
                        return -1;
        }

        return answer;
}